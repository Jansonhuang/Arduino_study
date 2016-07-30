/*
 * Description: A led library header file
 * Author: Janson <jansonhuang1989@gmail.com>
 * Revision:
 * Rev 1.0.0, 30Jul2016, Janson, Create the file.
 */
#ifndef _SIMPLELED_H_
#define _SIMPLELED_H_

#include "Arduino.h"

class SimpleLED
{
public:
  SimpleLED(int led, int valid);
  void led_on(void);
  void led_off(void);
  void led_pwm(int pwm);
private:
  int _led;
  int _valid;
};

#endif
