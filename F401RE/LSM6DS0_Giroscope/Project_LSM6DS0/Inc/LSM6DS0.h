#ifndef LSM6DS0_H
#define LSM6DS0_H
 


#include <stdint.h>
#include "stm32f4xx_hal.h"
#include <string.h>

#define ABS(x)         (x < 0) ? (-x) : x
//макроподстановки для управления светодиодами
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define LD2_ON HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET) //GREEN
#define LD2_OFF HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET)


//---------------------------------------------
#define LSM6DS0_ACC_GYRO_CTRL_REG5_XL   0X1F
#define LSM6DS0_ACC_GYRO_CTRL_REG6_XL   0X20
#define LSM6DS0_ACC_GYRO_CTRL_REG8    0X22
#define LSM6DS0_ACC_GYRO_CTRL_REG1_G    0X10
#define LSM6DS0_ACC_GYRO_CTRL_REG2_G    0X11
#define LSM6DS0_ACC_GYRO_CTRL_REG4    0X1E
//————————————————
#define LSM6DS0_ACC_GYRO_BDU_DISABLE  0x00
#define LSM6DS0_ACC_GYRO_BDU_ENABLE   0x40
#define LSM6DS0_ACC_GYRO_BDU_MASK   0x40
//————————————————
#define LSM6DS0_ACC_GYRO_ODR_XL_POWER_DOWN 0x00
#define LSM6DS0_ACC_GYRO_ODR_XL_10Hz 0x20
#define LSM6DS0_ACC_GYRO_ODR_XL_50Hz 0x40
#define LSM6DS0_ACC_GYRO_ODR_XL_119Hz 0x60
#define LSM6DS0_ACC_GYRO_ODR_XL_238Hz 0x80
#define LSM6DS0_ACC_GYRO_ODR_XL_476Hz 0xA0
#define LSM6DS0_ACC_GYRO_ODR_XL_952Hz 0xC0
#define LSM6DS0_ACC_GYRO_ODR_XL_MASK    0xE0
//————————————————
#define        LSM6DS0_ACC_GYRO_ODR_G_POWER_DOWN        0x00
#define        LSM6DS0_ACC_GYRO_ODR_G_15Hz        0x20
#define        LSM6DS0_ACC_GYRO_ODR_G_60Hz        0x40
#define        LSM6DS0_ACC_GYRO_ODR_G_119Hz        0x60
#define        LSM6DS0_ACC_GYRO_ODR_G_238Hz        0x80
#define        LSM6DS0_ACC_GYRO_ODR_G_476Hz        0xA0
#define        LSM6DS0_ACC_GYRO_ODR_G_952Hz        0xC0
#define        LSM6DS0_ACC_GYRO_ODR_G_MASK        0xE0
//————————————————
#define LSM6DS0_ACC_GYRO_FS_XL_2g 0x00
#define LSM6DS0_ACC_GYRO_FS_XL_16g 0x08
#define LSM6DS0_ACC_GYRO_FS_XL_4g 0x10
#define LSM6DS0_ACC_GYRO_FS_XL_8g 0x18
#define LSM6DS0_ACC_GYRO_FS_XL_MASK   0x18
//————————————————
#define        LSM6DS0_ACC_GYRO_FS_G_245dps        0x00
#define        LSM6DS0_ACC_GYRO_FS_G_500dps        0x08
#define        LSM6DS0_ACC_GYRO_FS_G_1000dps        0x10
#define        LSM6DS0_ACC_GYRO_FS_G_2000dps        0x18
#define        LSM6DS0_ACC_GYRO_FS_G_MASK        0x18
//————————————————
#define        LSM6DS0_ACC_GYRO_OUT_SEL_BYPASS_HPF_AND_LPF2        0x00
#define        LSM6DS0_ACC_GYRO_OUT_SEL_BYPASS_LPF2        0x01
#define        LSM6DS0_ACC_GYRO_OUT_SEL_USE_HPF_AND_LPF2        0x02
#define        LSM6DS0_ACC_GYRO_OUT_SEL_MASK        0x03
//————————————————
#define        LSM6DS0_ACC_GYRO_BW_G_LOW        0x00
#define        LSM6DS0_ACC_GYRO_BW_G_NORMAL        0x01
#define        LSM6DS0_ACC_GYRO_BW_G_HIGH        0x02
#define        LSM6DS0_ACC_GYRO_BW_G_ULTRA_HIGH        0x03
#define        LSM6DS0_ACC_GYRO_BW_G_MASK        0x03
//————————————————
#define LSM6DS0_ACC_GYRO_XEN_XL_ENABLE 0x08
#define LSM6DS0_ACC_GYRO_YEN_XL_ENABLE 0x10
#define LSM6DS0_ACC_GYRO_ZEN_XL_ENABLE 0x20
#define LSM6DS0_ACC_GYRO_XEN_XL_MASK   0x08
#define LSM6DS0_ACC_GYRO_YEN_XL_MASK   0x10
#define LSM6DS0_ACC_GYRO_ZEN_XL_MASK   0x20
//————————————————
#define        LSM6DS0_ACC_GYRO_XEN_G_DISABLE        0x00
#define        LSM6DS0_ACC_GYRO_XEN_G_ENABLE        0x08
#define        LSM6DS0_ACC_GYRO_YEN_G_DISABLE        0x00
#define        LSM6DS0_ACC_GYRO_YEN_G_ENABLE        0x10
#define        LSM6DS0_ACC_GYRO_ZEN_G_DISABLE        0x00
#define        LSM6DS0_ACC_GYRO_ZEN_G_ENABLE        0x20
#define        LSM6DS0_ACC_GYRO_XEN_G_MASK        0x08
#define        LSM6DS0_ACC_GYRO_YEN_G_MASK        0x10
#define        LSM6DS0_ACC_GYRO_ZEN_G_MASK        0x20
//————————————————
#define LSM6DS0_ACC_GYRO_OUT_X_L_XL   0X28
#define LSM6DS0_ACC_GYRO_OUT_X_H_XL   0X29
#define LSM6DS0_ACC_GYRO_OUT_Y_L_XL   0X2A
#define LSM6DS0_ACC_GYRO_OUT_Y_H_XL   0X2B
#define LSM6DS0_ACC_GYRO_OUT_Z_L_XL   0X2C
#define LSM6DS0_ACC_GYRO_OUT_Z_H_XL   0X2D
//————————————————
#define LSM6DS0_ACC_GYRO_OUT_X_L_G    0X18
#define LSM6DS0_ACC_GYRO_OUT_X_H_G    0X19
#define LSM6DS0_ACC_GYRO_OUT_Y_L_G    0X1A
#define LSM6DS0_ACC_GYRO_OUT_Y_H_G    0X1B
#define LSM6DS0_ACC_GYRO_OUT_Z_L_G    0X1C
#define LSM6DS0_ACC_GYRO_OUT_Z_H_G    0X1D
//---------------------------------------------------------------------

//Прототипы функций
void Accel_Giro_Ini(void);	//инициализация гироскопа
void Accel_Giro_ReadAcc(void);		//чтение значений с акселерометра и гироскопа
void GyroInit(uint16_t InitStruct);	//конфигурация гироскопа
void Gyro_GetXYZ(int16_t* pData);		//получение значений от гироскопа

//---------------------------------------------------------------------
#endif /* LSM6DS0_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/


