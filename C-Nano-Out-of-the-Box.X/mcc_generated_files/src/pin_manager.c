/**
  @Company
    Microchip Technology Inc.

  @Description
    This Source file provides APIs.
    Generation Information :
    Driver Version    :   1.0.0
*/
/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/


#include "../include/pin_manager.h"
static void (*PORTF_Button_InterruptHandler)(void);
static void (*PORTA_PA1_InterruptHandler)(void);
static void (*PORTF_LED_InterruptHandler)(void);

void PORT_Initialize(void);

void PIN_MANAGER_Initialize()
{
    PORT_Initialize();

    /* DIR Registers Initialization */
    PORTA.DIR = 0x00;
    PORTC.DIR = 0x00;
    PORTD.DIR = 0x00;
    PORTF.DIR = 0x20;

    /* OUT Registers Initialization */
    PORTA.OUT = 0x00;
    PORTC.OUT = 0x00;
    PORTD.OUT = 0x00;
    PORTF.OUT = 0x00;

    /* PINxCTRL registers Initialization */
    PORTA.PIN0CTRL = 0x00;
    PORTA.PIN1CTRL = 0x00;
    PORTA.PIN2CTRL = 0x00;
    PORTA.PIN3CTRL = 0x00;
    PORTA.PIN4CTRL = 0x00;
    PORTA.PIN5CTRL = 0x00;
    PORTA.PIN6CTRL = 0x00;
    PORTA.PIN7CTRL = 0x00;
    PORTC.PIN0CTRL = 0x00;
    PORTC.PIN1CTRL = 0x00;
    PORTC.PIN2CTRL = 0x00;
    PORTC.PIN3CTRL = 0x00;
    PORTC.PIN4CTRL = 0x00;
    PORTC.PIN5CTRL = 0x00;
    PORTC.PIN6CTRL = 0x00;
    PORTC.PIN7CTRL = 0x00;
    PORTD.PIN0CTRL = 0x00;
    PORTD.PIN1CTRL = 0x00;
    PORTD.PIN2CTRL = 0x00;
    PORTD.PIN3CTRL = 0x00;
    PORTD.PIN4CTRL = 0x00;
    PORTD.PIN5CTRL = 0x00;
    PORTD.PIN6CTRL = 0x00;
    PORTD.PIN7CTRL = 0x00;
    PORTF.PIN0CTRL = 0x00;
    PORTF.PIN1CTRL = 0x00;
    PORTF.PIN2CTRL = 0x00;
    PORTF.PIN3CTRL = 0x00;
    PORTF.PIN4CTRL = 0x00;
    PORTF.PIN5CTRL = 0x00;
    PORTF.PIN6CTRL = 0x08;
    PORTF.PIN7CTRL = 0x00;

    /* Multi-pin Config registers Initialization */
    PORTA.PINCONFIG = 0x00;
    PORTA.PINCTRLCLR = 0x00;
    PORTA.PINCTRLSET = 0x00;
    PORTA.PINCTRLUPD = 0x00;
    PORTC.PINCONFIG = 0x00;
    PORTC.PINCTRLCLR = 0x00;
    PORTC.PINCTRLSET = 0x00;
    PORTC.PINCTRLUPD = 0x00;
    PORTD.PINCONFIG = 0x00;
    PORTD.PINCTRLCLR = 0x00;
    PORTD.PINCTRLSET = 0x00;
    PORTD.PINCTRLUPD = 0x00;
    PORTF.PINCONFIG = 0x00;
    PORTF.PINCTRLCLR = 0x00;
    PORTF.PINCTRLSET = 0x00;
    PORTF.PINCTRLUPD = 0x00;

    /* PORTMUX Initialization */
    PORTMUX.CCLROUTEA = 0x00;
    PORTMUX.EVSYSROUTEA = 0x00;
    PORTMUX.SPIROUTEA = 0x00;
    PORTMUX.TCAROUTEA = 0x00;
    PORTMUX.TCBROUTEA = 0x00;
    PORTMUX.TCDROUTEA = 0x00;
    PORTMUX.TWIROUTEA = 0x00;
    PORTMUX.USARTROUTEA = 0x00;

    // register default ISC callback functions at runtime; use these methods to register a custom function
    PORTF_Button_SetInterruptHandler(PORTF_Button_DefaultInterruptHandler);
    PORTA_PA1_SetInterruptHandler(PORTA_PA1_DefaultInterruptHandler);
    PORTF_LED_SetInterruptHandler(PORTF_LED_DefaultInterruptHandler);
}

void PORT_Initialize(void)
{
    /* On AVR devices all peripherals are enable from power on reset, this
     * disables all peripherals to save power. Driver shall enable
     * peripheral if used */

    /* Set all pins to low power mode */
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTF + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTA + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTC + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTD + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
}

/**
  Allows selecting an interrupt handler for PORTF_Button at application runtime
*/
void PORTF_Button_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTF_Button_InterruptHandler = interruptHandler;
}

void PORTF_Button_DefaultInterruptHandler(void)
{
    // add your PORTF_Button interrupt custom code
    // or set custom function using PORTF_Button_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_PA1 at application runtime
*/
void PORTA_PA1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_PA1_InterruptHandler = interruptHandler;
}

void PORTA_PA1_DefaultInterruptHandler(void)
{
    // add your PORTA_PA1 interrupt custom code
    // or set custom function using PORTA_PA1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTF_LED at application runtime
*/
void PORTF_LED_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTF_LED_InterruptHandler = interruptHandler;
}

void PORTF_LED_DefaultInterruptHandler(void)
{
    // add your PORTF_LED interrupt custom code
    // or set custom function using PORTF_LED_SetInterruptHandler()
}
