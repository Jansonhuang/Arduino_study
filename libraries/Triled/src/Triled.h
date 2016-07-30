/*
 * Description: A triled library header file
 * Author: Janson <jansonhuang1989@gmail.com>
 * Revision:
 * Rev 1.0.0, 30Jul2016, Janson, Create the file.
 */
#ifndef _TRILED_H_
#define _TRILED_H_

#include "Arduino.h"
#include <SimpleLED.h>

class Triled {
  public:
    const int TRILED_ON = 1;
    const int TRILED_OFF = 0;
  public:
    Triled(SimpleLED led_red, SimpleLED led_green, SimpleLED led_blue):_led_red(led_red), _led_green(led_green), _led_blue(led_blue){}
    void set_value(int red, int green, int blue);
    void set_red(int valid);
    void set_green(int valid);
    void set_blue(int valid);
    void set_pwm(int red_pwm, int green_pwm, int blue_pwm);
    void set_red_pwm(int red_pwm);
    void set_green_pwm(int green_pwm);
    void set_blue_pwm(int blue_pwm);
  private:
    SimpleLED _led_red;
    SimpleLED _led_green;
    SimpleLED _led_blue;
};

#endif
