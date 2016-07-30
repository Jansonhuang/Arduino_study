/*
 * Description: A led library source code
 * Author: Janson <jansonhuang1989@gmail.com>
 * Revision:
 * Rev 1.0.0, 30Jul2016, Janson, Create the file.
 */
#include "Arduino.h"
#include "SimpleLED.h"

/*
 * Function:    SimpleLED(int led, int valid)
 * Description: initialize SimpleLED object & initialize GPIO
 * Input:       led             led gpio num
 *              valid           led valid level(HIGH/LOW), depends on hardware design
 * Output:      none
 * Return:      none
 * Note:        none
 */
SimpleLED::SimpleLED(int led, int valid)
{
  _led = led;
  _valid = valid;
  pinMode(_led, OUTPUT);
}

/*
 * Function:    led_on(void)
 * Description: turn on led
 * Input:       none
 * Output:      none
 * Return:      none
 * Note:        none
 */
void SimpleLED::led_on(void)
{
  if (HIGH == _valid) {
    digitalWrite(_led, HIGH);
  } else {
    digitalWrite(_led, LOW);
  }
}

/*
 * Function:    led_off(void)
 * Description: turn off led
 * Input:       none
 * Output:      none
 * Return:      none
 * Note:        none
 */
void SimpleLED::led_off(void)
{
  if (HIGH == _valid) {
    digitalWrite(_led, LOW);
  } else {
    digitalWrite(_led, HIGH);
  }
}

/*
 * Function:    led_set_value(int valid)
 * Description: turn on/off led
 * Input:       valid       >0: turn on led, ==0: turn off led 
 * Output:      none
 * Return:      none
 * Note:        none
 */
void SimpleLED::led_set_value(int valid)
{
  if (valid) {
    led_on();
  } else {
    led_off();
  }
}

/*
 * Function:    led_pwm(int pwm)
 * Description: use pwm to control led
 * Input:       pwm             pwm value(0-255)
 * Output:      none
 * Return:      none
 * Note:        none
 */
void SimpleLED::led_pwm(int pwm)
{
  if (HIGH == _valid) {
    analogWrite(_led, pwm);
  } else {
    analogWrite(_led, 255 - pwm);
  }
}
