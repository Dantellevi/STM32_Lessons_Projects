#include "LSM6DS0.h"

extern I2C_HandleTypeDef hi2c1;
extern UART_HandleTypeDef huart2;
uint8_t buf2[14]={0};
char str1[30]={0};
//Функция ошибки
void Error(void)
{
        LD2_OFF;
}
//Считывания данных по I2C
static uint8_t I2Cx_ReadData(uint16_t Addr, uint8_t Reg)
{
        HAL_StatusTypeDef status = HAL_OK;
        uint8_t value = 0;
        status = HAL_I2C_Mem_Read(&hi2c1, Addr, Reg, I2C_MEMADD_SIZE_8BIT, &value, 1, 0x10000);
        if(status != HAL_OK) Error();
        return value;
}
//Запись данных по I2C
static void I2Cx_WriteData(uint16_t Addr, uint8_t Reg, uint8_t Value)
{
        HAL_StatusTypeDef status = HAL_OK;
        status = HAL_I2C_Mem_Write(&hi2c1, Addr, (uint16_t)Reg, I2C_MEMADD_SIZE_8BIT, &Value, 1, 0x10000);
        if(status != HAL_OK) Error();
}
//считывание данных
uint8_t Accel_IO_Read(uint16_t DeviceAddr, uint8_t RegisterAddr)
{
        return I2Cx_ReadData(DeviceAddr, RegisterAddr);
}
//запись данных
void Accel_IO_Write(uint16_t DeviceAddr, uint8_t RegisterAddr, uint8_t Value)
{
        I2Cx_WriteData(DeviceAddr, RegisterAddr, Value);
}
//получаем данные по осям
void Accel_GetXYZ(int16_t* pData)
{
        uint8_t buffer[6];
        uint8_t i=0;
				buffer[0] = Accel_IO_Read(0xD6,LSM6DS0_ACC_GYRO_OUT_X_L_XL);//читаем младший регистр выхода х
        buffer[1] = Accel_IO_Read(0xD6,LSM6DS0_ACC_GYRO_OUT_X_H_XL);//читаем старший регистр выхода х
        buffer[2] = Accel_IO_Read(0xD6,LSM6DS0_ACC_GYRO_OUT_Y_L_XL);//читаем младший регистр выхода у
        buffer[3] = Accel_IO_Read(0xD6,LSM6DS0_ACC_GYRO_OUT_Y_H_XL);//читаем старший регистр выхода у
        buffer[4] = Accel_IO_Read(0xD6,LSM6DS0_ACC_GYRO_OUT_Z_L_XL);//читаем младший регистр выхода z
        buffer[5] = Accel_IO_Read(0xD6,LSM6DS0_ACC_GYRO_OUT_Z_H_XL);//читаем старший регистр выхода z
        for(i=0;i<3;i++)
        {
					pData[i] = ((int16_t)((uint16_t)buffer[2*i+1]<<8)+buffer[2*i]);
                
        }
}
//считывания Id
uint8_t Accel_ReadID(void)	
{
        uint8_t ctrl = 0x00;
	ctrl = Accel_IO_Read(0xD6,0x0F);	//обращаеся по адресу с индификатором
	return ctrl;
}
//Функция 
void Accel_Giro_ReadAcc(void)
{
int16_t buffer[3]={0};
int16_t xval,yval,zval;

Gyro_GetXYZ(buffer);
xval=buffer[0]-103;
yval=buffer[1]-47;
zval=buffer[2]-41;
//---------------------------------------
//sprintf(str1,"X:%06d Y:%06d Z:%06d\r\n", xval, yval, zval);
//HAL_UART_Transmit_DMA(&huart2, (uint8_t*)str1,strlen(str1));
 buf2[0]=0x11;
        buf2[1]=0x55;
        buf2[2]=(uint8_t)(xval>>8);
        buf2[3]=(uint8_t)xval;
        buf2[4]=(uint8_t)(yval>>8);
        buf2[5]=(uint8_t)yval;
        buf2[6]=(uint8_t)(zval>>8);
        buf2[7]=(uint8_t)zval;
        HAL_UART_Transmit_DMA(&huart2,buf2,8);
        if(zval>500)
        {
        LD2_ON;
        }
        else
        {
        LD2_OFF;
        }
        HAL_Delay(20);
//---------------------------------------
}


//----------------------------------------
void AccInit(uint16_t InitStruct)
{
	
	uint8_t value=0;
	//установим бит BDU-отвечает за защиту старшего байта данных от изменения в том случае если еще не считан младший
value = Accel_IO_Read(0xD6, LSM6DS0_ACC_GYRO_CTRL_REG8);
value &= ~LSM6DS0_ACC_GYRO_BDU_MASK;//сбрасываем биты
value |= LSM6DS0_ACC_GYRO_BDU_ENABLE;//устанавливаем биты
Accel_IO_Write(0xD6, LSM6DS0_ACC_GYRO_CTRL_REG8, value);//пока выключим датчик (ODR_XL = 000)
//------------------------------------------------------------
value = Accel_IO_Read(0xD6, LSM6DS0_ACC_GYRO_CTRL_REG6_XL);
value &= ~LSM6DS0_ACC_GYRO_ODR_XL_MASK;
value |= LSM6DS0_ACC_GYRO_ODR_XL_POWER_DOWN;
Accel_IO_Write(0xD6, LSM6DS0_ACC_GYRO_CTRL_REG6_XL, value);
 //Full scale selection 2G
value = Accel_IO_Read(0xD6, LSM6DS0_ACC_GYRO_CTRL_REG6_XL);
value &= ~LSM6DS0_ACC_GYRO_FS_XL_MASK;
value |= LSM6DS0_ACC_GYRO_FS_XL_2g;
Accel_IO_Write(0xD6, LSM6DS0_ACC_GYRO_CTRL_REG6_XL, value);
//Включим оси
value = Accel_IO_Read(0xD6, LSM6DS0_ACC_GYRO_CTRL_REG5_XL);
        
value &= ~(LSM6DS0_ACC_GYRO_XEN_XL_MASK |
                                                 LSM6DS0_ACC_GYRO_YEN_XL_MASK |
                                                 LSM6DS0_ACC_GYRO_ZEN_XL_MASK);
value |= (LSM6DS0_ACC_GYRO_XEN_XL_ENABLE |
                                                LSM6DS0_ACC_GYRO_YEN_XL_ENABLE |
                                                LSM6DS0_ACC_GYRO_ZEN_XL_ENABLE);
Accel_IO_Write(0xD6, LSM6DS0_ACC_GYRO_CTRL_REG5_XL, value);

//Включим Data Rate 119 Гц
value = Accel_IO_Read(0xD6, LSM6DS0_ACC_GYRO_CTRL_REG6_XL);
value &= ~LSM6DS0_ACC_GYRO_ODR_XL_MASK;
value |= LSM6DS0_ACC_GYRO_ODR_XL_119Hz;
Accel_IO_Write(0xD6, LSM6DS0_ACC_GYRO_CTRL_REG6_XL, value);
	

}

//-------------------------------------------------------------
void GyroInit(uint16_t InitStruct)
{
        uint8_t value = 0;
	 //установим бит BDU
        value = Accel_IO_Read(0xD6,LSM6DS0_ACC_GYRO_CTRL_REG8);
        value&=~LSM6DS0_ACC_GYRO_BDU_MASK;
        value|=LSM6DS0_ACC_GYRO_BDU_ENABLE;
        Accel_IO_Write(0xD6,LSM6DS0_ACC_GYRO_CTRL_REG8,value);
				
	
	//выключим датчик (ODR-XL-000)
				value = Accel_IO_Read(0xD6,LSM6DS0_ACC_GYRO_CTRL_REG1_G);
        value&=~LSM6DS0_ACC_GYRO_ODR_G_MASK;	//выставляем биты ODR
	value|=LSM6DS0_ACC_GYRO_ODR_G_POWER_DOWN;	//отключаем питание
        Accel_IO_Write(0xD6,LSM6DS0_ACC_GYRO_CTRL_REG1_G,value);

	/*
	В данном коде мы работаем с регистром 
	CTRL_REG1_G (адрес 0X10), с его битами, 
	отвечающим за частоту снятия данных именно 
	с гироскопа
	*/
	
	
	 //Full scale selection 500 dps
        value = Accel_IO_Read(0xD6,LSM6DS0_ACC_GYRO_CTRL_REG1_G);//читаем с устройства по определенному регистру
        value&=~LSM6DS0_ACC_GYRO_FS_G_MASK;	//маскирование
        value|=LSM6DS0_ACC_GYRO_FS_G_500dps;//указываем значение измерений
        Accel_IO_Write(0xD6,LSM6DS0_ACC_GYRO_CTRL_REG1_G,value);	//производим запись в регистр
	 
	 
	 //Включим оси
        value = Accel_IO_Read(0xD6,LSM6DS0_ACC_GYRO_CTRL_REG4);
        value&=~(LSM6DS0_ACC_GYRO_XEN_G_MASK|\
                                         LSM6DS0_ACC_GYRO_YEN_G_MASK|\
                                         LSM6DS0_ACC_GYRO_ZEN_G_MASK);	//включаем оси  
        value|=(LSM6DS0_ACC_GYRO_XEN_G_ENABLE|\
                                        LSM6DS0_ACC_GYRO_YEN_G_ENABLE|\
                                        LSM6DS0_ACC_GYRO_ZEN_G_ENABLE);	//флаги подтверждение использование осей
        Accel_IO_Write(0xD6,LSM6DS0_ACC_GYRO_CTRL_REG4,value);					//записываем в регистр
	
	
				//Включим HPF и LPF2 (фильтрация)
        value = Accel_IO_Read(0xD6,LSM6DS0_ACC_GYRO_CTRL_REG2_G);		//переходим в регистр
        value&=~LSM6DS0_ACC_GYRO_OUT_SEL_MASK;											//производим маскирование
        value|=LSM6DS0_ACC_GYRO_OUT_SEL_USE_HPF_AND_LPF2;						//устанавливаем фильтр
        Accel_IO_Write(0xD6,LSM6DS0_ACC_GYRO_CTRL_REG2_G,value);		//записываем данные в регистр
				
				 //Включим BW (пропускная способность). При 952 Гц настроек будет пропускная способность 100 Гц
        value = Accel_IO_Read(0xD6,LSM6DS0_ACC_GYRO_CTRL_REG1_G);
        value&=~LSM6DS0_ACC_GYRO_BW_G_MASK;
        value|=LSM6DS0_ACC_GYRO_BW_G_ULTRA_HIGH;
        Accel_IO_Write(0xD6,LSM6DS0_ACC_GYRO_CTRL_REG1_G,value);
				
				//Включим Data Rate 952 Гц
        value = Accel_IO_Read(0xD6,LSM6DS0_ACC_GYRO_CTRL_REG1_G);
        value&=~LSM6DS0_ACC_GYRO_ODR_G_MASK;
        value|=LSM6DS0_ACC_GYRO_ODR_G_952Hz;
        Accel_IO_Write(0xD6,LSM6DS0_ACC_GYRO_CTRL_REG1_G,value);
}
//-------------------------------------------------------------

//Инициализация
void Accel_Giro_Ini(void)
{
        uint16_t ctrl = 0x0000;
        HAL_Delay(1000);
	if(Accel_ReadID()==0x68) LD2_ON;	// если индификатор совпадает вкл. зелен.светодиод
	else Error();		//возращаем ошибку
	LD2_OFF;
        //AccInit(ctrl);
	GyroInit(ctrl);
	LD2_ON;
}


//Функция получения данных с гироскопа
void Gyro_GetXYZ(int16_t* pData)
{
        uint8_t buffer[6];		//буффер для данных
        uint8_t i=0;
	buffer[0]=Accel_IO_Read(0xD6,LSM6DS0_ACC_GYRO_OUT_X_L_G);//обращаемся к адресу и получаем младшую часть значения по оси х
        buffer[1]=Accel_IO_Read(0xD6,LSM6DS0_ACC_GYRO_OUT_X_H_G);//обращаемся к адресу и получаем старшую часть значения по оси х
        buffer[2]=Accel_IO_Read(0xD6,LSM6DS0_ACC_GYRO_OUT_Y_L_G);//обращаемся к адресу и получаем младшую часть значения по оси у
	buffer[3]=Accel_IO_Read(0xD6,LSM6DS0_ACC_GYRO_OUT_Y_H_G);//обращаемся к адресу и получаем старшую часть значения по оси у
        buffer[4]=Accel_IO_Read(0xD6,LSM6DS0_ACC_GYRO_OUT_Z_L_G);//обращаемся к адресу и получаем младшую часть значения по оси z
        buffer[5]=Accel_IO_Read(0xD6,LSM6DS0_ACC_GYRO_OUT_Z_H_G);//обращаемся к адресу и получаем старшую часть значения по оси z
        for(i=0;i<3;i++)
        {
                pData[i] = ((int16_t)((uint16_t)buffer[2*i+1]<<8)+buffer[2*i]);
        }
}
