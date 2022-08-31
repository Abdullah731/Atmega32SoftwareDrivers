/*************************************************************************/
/* !File Name:         USART_program.c                                   */
/* !Layer    :         MCAL                                              */
/* !Author   :         Abdullah M. Abdullah                              */
/* !Date     :         1 SEP, 2021                                       */
/* !Version  :         v1.0                                              */
/*************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

void (*USART_pvNotificationFunction)(void);
u8 USART_u8Data = 0;

void USART_voidInit(void)
{
	/*Set The Result Equation in UBRRL*/
	UBRRL = (u8)BAUD_EQU_RESULT;

	/*Select The UBRRH Register*/
	CLR_BIT(UCSRC, UCSRC_URSEL);

	/*Set The Result Equation in UBRRH*/
	UBRRH = (u8)(BAUD_EQU_RESULT >> 8);

	/*Select The UCSRC Register*/
	SET_BIT(UCSRC, UCSRC_URSEL);

	/*Set The Data Bits To Be 8-bit*/
	SET_BIT(UCSRC, UCSRC_UCSZ0);
	SET_BIT(UCSRC, UCSRC_UCSZ1);
	CLR_BIT(UCSRB, UCSRB_UCSZ2);

	/*Set The Stop Bit To Be 1-bit*/
	CLR_BIT(UCSRC, UCSRC_USBS);

	/*Disable The Parity Mode*/
	CLR_BIT(UCSRC, UCSRC_UPM0);
	CLR_BIT(UCSRC, UCSRC_UPM1);

	/*Set The USART Mode To Be Asynchronous Mode*/
	CLR_BIT(UCSRC, UCSRC_UMSEL);

	/*Set The Double Speed Mode*/
	SET_BIT(UCSRA, UCSRA_U2X);

	/*Enable The RX Complete Interrupt*/
	SET_BIT(UCSRB, UCSRB_RXCIE);

	/*Enable The Tx*/
	SET_BIT(UCSRB, UCSRB_TXEN);

	/*Enable The Rx*/
	SET_BIT(UCSRB, UCSRB_RXEN);
}

void USART_voidTransmitDataSynchronous(u8 Copy_u8Data)
{
	/*Polling (Busy Waiting) until the UDR Register be empty*/
	while((GET_BIT(UCSRA, UCSRA_UDRE)) == 0);

	/*Clear The Flag*/
	SET_BIT(UCSRA, UCSRA_UDRE);

	/*Store The Data in UDR Register to be sent*/
	UDR = Copy_u8Data;
}


void USART_voidTransmitDataAsynchronous(u8 Copy_u8Data)
{
	/*Update the Data Global Variable with the data passed to the function*/
	USART_u8Data = Copy_u8Data;
	/*Enable The UDR Empty Interrupt*/
	SET_BIT(UCSRB, UCSRB_UDRIE);
}


u8 USART_u8ReceiveDataSynchronous(void)
{
	/*Polling (Busy Waiting) until the Rx Complete event is occurred*/
	while(GET_BIT(UCSRA, UCSRA_RXC) == 0);

	/*Clear The RXC Flag*/
	SET_BIT(UCSRA, UCSRA_RXC);

	/*Return the Received Data*/
	return UDR;
}


void __vector_14 (void) __attribute__((signal));
void __vector_14 (void)
{
	/*Check if the variable is changed or not*/
	if(USART_u8Data != 0)
	{
		/*Put the Data to be sent in the UDR Register*/
		UDR = USART_u8Data;
	}
	else
	{
		/*Do Nothing*/
	}

	/*Disable The UDR Empty Interrupt*/
	CLR_BIT(UCSRB, UCSRB_UDRIE);
}




