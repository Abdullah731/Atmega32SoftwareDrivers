/*************************************************************************/
/* !File Name:         USART_private.h                                   */
/* !Layer    :         MCAL                                              */
/* !Author   :         Abdullah M. Abdullah                              */
/* !Date     :         1 SEP, 2021                                       */
/* !Version  :         v1.0                                              */
/*************************************************************************/
#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

#define			UCSRA		 *((volatile u8 *)(0x2B))		// USART Control Status Register A
#define			UCSRA_MPCM	 0								// Multi-processor Communication Mode
#define			UCSRA_U2X	 1								// Double The USART Transmission Speed
#define			UCSRA_PE	 2								// Parity Error
#define			UCSRA_DOR	 3								// Data OverRun
#define 		UCSRA_FE	 4								// Frame Error
#define			UCSRA_UDRE	 5								// USART Data Register Empty
#define			UCSRA_TXC	 6								// USART Transmit Complete
#define			UCSRA_RXC	 7								// USART Receive Complete

#define			UCSRB		 *((volatile u8 *)(0x2A))		// USART Control Status Register B
#define			UCSRB_TXB8	 0								// Transmit Data Bit 8
#define			UCSRB_RXB8	 1								// Receive Data Bit 8
#define			UCSRB_UCSZ2	 2								// Character Size
#define			UCSRB_TXEN	 3								// Transmitter Enable
#define			UCSRB_RXEN	 4								// Receiver Enable
#define			UCSRB_UDRIE  5								// USART Data Register Empty Interrupt Enable
#define			UCSRB_TXCIE  6								// TX Complete Interrupt Enable
#define			UCSRB_RXCIE	 7								// RX Complete Interrupt Enable

#define			UCSRC		 *((volatile u8 *)(0x40))		// USART Control Status Register C
#define         UCSRC_UCPOL	 0								// USART Clock Polarity
#define         UCSRC_UCSZ0  1								// USART Character Size 0
#define         UCSRC_UCSZ1  2								// USART Character Size 1
#define         UCSRC_USBS	 3								// USART Stop Bit Select
#define         UCSRC_UPM0	 4								// USART Parity Mode 0
#define         UCSRC_UPM1	 5								// USART Parity Mode 1
#define         UCSRC_UMSEL  6								// USART Mode Select
#define         UCSRC_URSEL	 7								// USART Register Select


#define			UDR			 *((volatile u8 *)(0x2C))		// USART Data Register

#define			UBRRL		 *((volatile u8 *)(0x29))		// USART Baud Rate Low Byte
#define			UBRRH		 *((volatile u8 *)(0x40))		// USART Baud Rate High Byte


#define	BAUD_EQU_RESULT 	(((F_OSC)/(8*BAUDRATE_VALUE))-1)

#endif
