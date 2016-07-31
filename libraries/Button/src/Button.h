/*
 * Description: A button library header file
 * Author: Janson <jansonhuang1989@gmail.com>
 * Revision:
 * Rev 1.0.0, 31Jul2016, Janson, Create the file.
 */
#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "Arduino.h"

class Button
{
public:
  static const int BUTTON_STATE_IDLE = 0;
  static const int BUTTON_STATE_PRESSED = 1;
  static const int BUTTON_STATE_PRESSING = 2;
public:
  Button(int button, int valid);
  void setCallBack(void (*pressed_cb)(int), void (*pressing_cb)(int), void (*release_cb)(int));
  void detect(void);
  int getState(void);
  int getCnt(void);
private:
  int _button;
  int _valid;
  int _cnt;
  int _state;
  void (*_pressed_cb)(int cnt);
  void (*_pressing_cb)(int cnt);
  void (*_release_cb)(int cnt);
};

#endif
