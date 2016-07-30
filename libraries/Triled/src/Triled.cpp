/*
 * Description: A triled library source code
 * Author: Janson <jansonhuang1989@gmail.com>
 * Revision:
 * Rev 1.0.0, 30Jul2016, Janson, Create the file.
 */
#include "Arduino.h"
#include "Triled.h"
#include <SimpleLED.h>

/*
 * Function:    set_value(int red, int green, int blue)
 * Description: set rgb valid value
 * Input:       red                 red valid
 *              green               green valid
 *              blue                blue valid
 * Output:      none
 * Return:      none
 * Note:        none
 */
void Triled::set_value(int red, int green, int blue)
{
  _led_red.led_set_value(red);
  _led_green.led_set_value(green);
  _led_blue.led_set_value(blue);
}

/*
 * Function:    set_red(int valid)
 * Description: set red valid value
 * Input:       red                 red valid
 * Output:      none
 * Return:      none
 * Note:        none
 */
void Triled::set_red(int valid)
{
  _led_red.led_set_value(valid);
}

/*
 * Function:    set_green(int valid)
 * Description: set green valid value
 * Input:       green               green valid
 * Output:      none
 * Return:      none
 * Note:        none
 */
void Triled::set_green(int valid)
{
  _led_green.led_set_value(valid);
}

/*
 * Function:    set_blue(int valid)
 * Description: set blue valid value
 * Input:       blue                blue valid
 * Output:      none
 * Return:      none
 * Note:        none
 */
void Triled::set_blue(int valid)
{
  _led_blue.led_set_value(valid);
}

/*
 * Function:    set_pwm(int red_pwm, int green_pwm, int blue_pwm)
 * Description: set rgb pwm value
 * Input:       red_pwm             red pwm value
 *              green_pwm           green pwm value
 *              blue_pwm            blue pwm value
 * Output:      none
 * Return:      none
 * Note:        none
 */
void Triled::set_pwm(int red_pwm, int green_pwm, int blue_pwm)
{
  _led_red.led_pwm(red_pwm);
  _led_green.led_pwm(green_pwm);
  _led_blue.led_pwm(blue_pwm);
}

/*
 * Function:    set_red_pwm(int red_pwm)
 * Description: set red pwm value
 * Input:       red_pwm             red pwm value
 * Output:      none
 * Return:      none
 * Note:        none
 */
void Triled::set_red_pwm(int red_pwm)
{
  _led_red.led_pwm(red_pwm);
}

/*
 * Function:    set_green_pwm(int green_pwm)
 * Description: set green pwm value
 * Input:       green_pwm           green pwm value
 * Output:      none
 * Return:      none
 * Note:        none
 */
void Triled::set_green_pwm(int green_pwm)
{
  _led_green.led_pwm(green_pwm);
}

/*
 * Function:    set_blue_pwm(int blue_pwm)
 * Description: set blue pwm value
 * Input:       blue_pwm            blue pwm value
 * Output:      none
 * Return:      none
 * Note:        none
 */
void Triled::set_blue_pwm(int blue_pwm)
{
  _led_blue.led_pwm(blue_pwm);
}
