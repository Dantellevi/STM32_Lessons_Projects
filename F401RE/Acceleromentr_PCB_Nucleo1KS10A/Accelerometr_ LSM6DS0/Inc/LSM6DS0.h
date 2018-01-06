#ifndef LSM6DS0_H
#define LSM6DS0_H
 


#include <stdint.h>
#include "stm32f4xx_hal.h"
#include <string.h>
//————————————————
#define ABS(x)         (x < 0) ? (-x) : x
//————————————————
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define LD2_ON HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET) //GREEN
#define LD2_OFF HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET)
//————————————————
void Accel_Ini(void);
void Accel_ReadAcc(void);
//---------------------------------------------
#define LSM6DS0_ACC_GYRO_BDU_DISABLE  0x00
#define LSM6DS0_ACC_GYRO_BDU_ENABLE   0x40
#define LSM6DS0_ACC_GYRO_BDU_MASK   0x40
//————————————————
#define LSM6DS0_ACC_GYRO_CTRL_REG5_XL   0X1F
#define LSM6DS0_ACC_GYRO_CTRL_REG6_XL   0X20
#define LSM6DS0_ACC_GYRO_CTRL_REG8    0X22
//————————————————
#define LSM6DS0_ACC_GYRO_ODR_XL_POWER_DOWN 0x00
#define LSM6DS0_ACC_GYRO_ODR_XL_10Hz 0x20
#define LSM6DS0_ACC_GYRO_ODR_XL_50Hz 0x40
#define LSM6DS0_ACC_GYRO_ODR_XL_119Hz 0x60
#define LSM6DS0_ACC_GYRO_ODR_XL_238Hz 0x80
#define LSM6DS0_ACC_GYRO_ODR_XL_476Hz 0xA0
#define LSM6DS0_ACC_GYRO_ODR_XL_952Hz 0xC0
//————————————————
#define LSM6DS0_ACC_GYRO_ODR_XL_MASK    0xE0
//————————————————
#define LSM6DS0_ACC_GYRO_FS_XL_2g 0x00
#define LSM6DS0_ACC_GYRO_FS_XL_16g 0x08
#define LSM6DS0_ACC_GYRO_FS_XL_4g 0x10
#define LSM6DS0_ACC_GYRO_FS_XL_8g 0x18
//————————————————
#define LSM6DS0_ACC_GYRO_FS_XL_MASK   0x18
//————————————————
#define LSM6DS0_ACC_GYRO_XEN_XL_ENABLE 0x08
#define LSM6DS0_ACC_GYRO_YEN_XL_ENABLE 0x10
#define LSM6DS0_ACC_GYRO_ZEN_XL_ENABLE 0x20
#define LSM6DS0_ACC_GYRO_XEN_XL_MASK   0x08
#define LSM6DS0_ACC_GYRO_YEN_XL_MASK   0x10
#define LSM6DS0_ACC_GYRO_ZEN_XL_MASK   0x20
//————————————————
#define LSM6DS0_ACC_GYRO_OUT_X_L_XL   0X28
#define LSM6DS0_ACC_GYRO_OUT_X_H_XL   0X29
#define LSM6DS0_ACC_GYRO_OUT_Y_L_XL   0X2A
#define LSM6DS0_ACC_GYRO_OUT_Y_H_XL   0X2B
#define LSM6DS0_ACC_GYRO_OUT_Z_L_XL   0X2C
#define LSM6DS0_ACC_GYRO_OUT_Z_H_XL   0X2D

//————————————————




#endif /* LSM6DS0_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/


