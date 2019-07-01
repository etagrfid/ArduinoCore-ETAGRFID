/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
  
  Updated by Jay Wilhelm (jwilhelm@ohio.edu) for the ETAG2 with D21/L21
*/
/*
 *
 * + Pin number +  ZERO Board pin  |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+------------------------------
 */


#include "variant.h"

/*
 * Pins descriptions
 */
const PinDescription g_APinDescription[]=
{
  // 0 .. 19 - Digital pins
  // ----------------------
  // 0/1 - SERCOM/UART (Serial1)
  { PORTB, 12, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_12 }, // RX: SERCOM0/PAD[3]
  { PORTB, 13, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_13 }, // TX: SERCOM0/PAD[2]

  // 2..12
  { PORTB, 14, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM0_CH0, TCC0_CH0, EXTERNAL_INT_14 }, // EXTERNAL_INT_NMI }, // TCC0/WO[0]
  { PORTB, 15, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM0_CH1, TCC0_CH1, EXTERNAL_INT_15 }, // TCC0/WO[1]
  { PORTB, 10, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM3_CH0, TC3_CH0, EXTERNAL_INT_10 }, // TC3/WO[0]
  { PORTB, 11, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM3_CH1, TC3_CH1, EXTERNAL_INT_11 }, // TC3/WO[1]
  { PORTA, 12, PIO_TIMER_ALT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM0_CH6, TCC0_CH6, EXTERNAL_INT_12 }, // TCC0/WO[6]
  { PORTA, 13, PIO_TIMER_ALT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM0_CH7, TCC0_CH7, EXTERNAL_INT_13 }, // TCC0/WO[7]
  { PORTA, 14, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM1_CH0, TCC1_CH0, EXTERNAL_INT_14 }, // TCC1/WO[0]
  { PORTA, 15, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM1_CH1, TCC1_CH1, EXTERNAL_INT_15 }, // TCC1/WO[1]
  { PORTA, 18, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM3_CH0, TC3_CH0, EXTERNAL_INT_2 }, // TC3/WO[0]
  { PORTA, 16, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM2_CH0, TCC2_CH0, EXTERNAL_INT_0 }, // TCC2/WO[0]
  { PORTA, 19, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM3_CH1, TC3_CH1, EXTERNAL_INT_3 }, // TC3/WO[1]
  { PORTA, 17, PIO_PWM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM), No_ADC_Channel, PWM2_CH1, NOT_ON_TIMER, EXTERNAL_INT_1 }, // TCC2/WO[1]

  // 14 (GND)
  { NOT_A_PORT, 0, PIO_NOT_A_PIN, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },

  // 15 (AREF)
  { PORTA, 3, PIO_ANALOG, PIN_ATTR_ANALOG, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3 }, // DAC/VREFP

  // 16..17 I2C pins (SDA/SCL and also EDBG:SDA/SCL)
  // ----------------------
  { PORTA, 22, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6 }, // SDA: SERCOM3/PAD[0]
  { PORTA, 23, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7 }, // SCL: SERCOM3/PAD[1]

  // 18..23 - SPI pins (ICSP:MISO,SCK,MOSI)
  // ----------------------
  { PORTA, 11, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11 }, // MISO: SERCOM4/PAD[0]
  { NOT_A_PORT, 0, PIO_NOT_A_PIN, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 5V0
  { PORTA,  9, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_9 }, // SCK: SERCOM4/PAD[3]
  { PORTA,  8, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // MOSI: SERCOM4/PAD[2] // EXT INT: NMI?
  { NOT_A_PORT, 0, PIO_NOT_A_PIN, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // RESET
  { NOT_A_PORT, 0, PIO_NOT_A_PIN, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // GND

  // 24..29 - Analog pins
  // --------------------
  { PORTA,  2, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel0, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 }, // ADC/AIN[0]
  { PORTB,  4, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel2, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_4 }, // ADC/AIN[2]
  { PORTB,  5, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel3, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5 }, // ADC/AIN[3]
  { PORTB,  6, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel4, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6 }, // ADC/AIN[4]
  { PORTB,  7, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel5, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7 }, // ADC/AIN[5]
  { PORTB,  8, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel10, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_8 }, // ADC/AIN[10]

  // 30..31 - RX/TX LEDS -> legacy, set to AUX IO pins (PORTB 30, PORTB 31)
  // --------------------
  { PORTB, 30, PIO_OUTPUT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // used as output only
  { PORTB, 31, PIO_PWM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM), No_ADC_Channel, PWM2_CH1, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // used as output only

  // 32..33 - USB
  // --------------------
  { PORTA, 24, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_12 }, // USB/DM -> USB_N
  { PORTA, 25, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_13 }, // USB/DP -> USB_P

 // ----------------------
 // 34 - Alternate use of A0 (DAC output)
  { PORTA,  2, PIO_ANALOG, PIN_ATTR_ANALOG, DAC_Channel0, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 }, // DAC/VOUT

  // 35...40 - AUX IO
  // --------------------
  { PORTB,  3, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel0, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3 }, // AIN 9
  { PORTB,  2, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel0, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 }, // AIN 8
  { PORTB,  1, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel0, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_1 }, // AIN 7
  { PORTB,  0, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel0, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_0 }, // AIN 6
  { PORTB, 31, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM1_CH1, TCC1_CH1, EXTERNAL_INT_11 }, // PIN_D15
  { PORTB, 30, PIO_TIMER, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM1_CH1, TCC1_CH1, EXTERNAL_INT_10 }, // PIN_D14

  // 41...42 - RFID IN
  { PORTB, 22, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel0, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6 }, // RFID_IN1
  { PORTB, 23, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel0, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7 }, // RFID_IN2

  // 43 - LED
  { PORTA, 27, PIO_OUTPUT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_15 } // LED

} ;

const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ TCC0, TCC1, TCC2, TC3, TC4, TC5 } ;

// Multi-serial objects instantiation
SERCOM sercom0( SERCOM0 ) ;
SERCOM sercom1( SERCOM1 ) ;
SERCOM sercom2( SERCOM2 ) ;
SERCOM sercom3( SERCOM3 ) ;
SERCOM sercom4( SERCOM4 ) ;
SERCOM sercom5( SERCOM5 ) ;

Uart Serial1( &sercom0, PIN_SERIAL1_RX, PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX ) ;
Uart Serial( &sercom5, PIN_SERIAL_RX, PIN_SERIAL_TX, PAD_SERIAL_RX, PAD_SERIAL_TX ) ;
void SERCOM0_Handler()
{
  Serial1.IrqHandler();
}

void SERCOM5_Handler()
{
  Serial.IrqHandler();
}

