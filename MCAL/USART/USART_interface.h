/*************************************************************************/
/* !File Name:         USART_interface.h                                 */
/* !Layer    :         MCAL                                              */
/* !Author   :         Abdullah M. Abdullah                              */
/* !Date     :         1 SEP, 2021                                       */
/* !Version  :         v1.0                                              */
/*************************************************************************/
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H


void USART_voidInit(void);
void USART_voidTransmitDataSynchronous(u8 Copy_u8Data);
void USART_voidTransmitDataAsynchronous(u8 Copy_u8Data);
u8 USART_u8ReceiveDataSynchronous(void);


#endif
