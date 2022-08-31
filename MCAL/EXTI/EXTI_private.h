/*************************************************************************/
/* !File Name:         EXTI_private.h                                    */
/* !Layer    :         MCAL                                              */
/* !Author   :         Abdullah M. Abdullah                              */
/* !Date     :         22 AUG, 2021                                      */
/* !Version  :         v1.0                                              */
/*************************************************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#define			MCUCR			*((volatile u8 *)(0x55))			// Control Register
#define			MCUCR_ISC00		0									// ISC00 bit
#define			MCUCR_ISC01		1									// ISC01 bit

#define			GICR			*((volatile u8 *)(0x5B))			// Interrupt Control Register
#define			GICR_INT0		6									// INT0 Enable

#define 		GIFR			*((volatile u8 *)(0x5A))			// Interrupt Flag Register
#define 		GIFR_INTF0		6									// INT0 Flag

#define			LOW_LEVEL			0
#define			ON_CHANGE			1
#define			FALLING_EDGE		2
#define 		RISING_EDGE			3

#endif