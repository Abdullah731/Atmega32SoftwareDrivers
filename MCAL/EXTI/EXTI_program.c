/*************************************************************************/
/* !File Name:         EXTI_program.c                                    */
/* !Layer    :         MCAL                                              */
/* !Author   :         Abdullah M. Abdullah                              */
/* !Date     :         22 AUG, 2021                                      */
/* !Version  :         v1.0                                              */
/*************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../GIE/GIE_interface.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


void EXTI_voidInt0Init(void)
{
	/*1- Set Sense Control for INT0*/
	#if		INT0_SENSE == LOW_LEVEL
		CLR_BIT(MCUCR, MCUCR_ISC00);
		CLR_BIT(MCUCR, MCUCR_ISC01);
	#elif	INT0_SENSE == ON_CHANGE
		SET_BIT(MCUCR, MCUCR_ISC00);
		CLR_BIT(MCUCR, MCUCR_ISC01);
	#elif	INT0_SENSE == FALLING_EDGE
		CLR_BIT(MCUCR, MCUCR_ISC00);
		SET_BIT(MCUCR, MCUCR_ISC01);
	#elif	INT0_SENSE == RISING_EDGE
		SET_BIT(MCUCR, MCUCR_ISC00);
		SET_BIT(MCUCR, MCUCR_ISC01);
	#else
		#error "INT0_SENSE Configuration Error"
	#endif
}

