/*
 * Description: A button library source code
 * Author: Janson <jansonhuang1989@gmail.com>
 * Revision:
 * Rev 1.0.0, 31Jul2016, Janson, Create the file.
 */
#include "Arduino.h"
#include "Button.h"

Button::Button(int button, int valid)
{
  _button = button;
  _valid = valid;
  _cnt = 0;
  _state = BUTTON_STATE_IDLE;
  _pressed_cb = NULL;
  _pressing_cb = NULL;
  _release_cb = NULL;
  pinMode(button, INPUT);
}

/*
 * Function:    setCallBack(void (*pressed_cb)(int), void (*pressing_cb)(int), void (*release_cb)(int))
 * Description: button callback register function
 * Input:       pressed_cb                  pressed callback function
 *              pressing_cb                 pressing callback function
 *              release_cb                  release callback funtion
 * Output:      none
 * Return:      none
 * Note:        none
 */
void Button::setCallBack(void (*pressed_cb)(int), void (*pressing_cb)(int), void (*release_cb)(int))
{
  _pressed_cb = pressed_cb;
  _pressing_cb = pressing_cb;
  _release_cb = release_cb;
}

/*
 * Function:    detect(void)
 * Description: button detect function
 * Input:       none
 * Output:      none
 * Return:      none
 * Note:        It's user's freedom to decide the detection interval
 */
void Button::detect(void)
{
  int value = digitalRead(_button);
  switch(_state)
  {
    case BUTTON_STATE_IDLE:
      if (value == _valid)
      {
        _state = BUTTON_STATE_PRESSED;
      }
      else
      {
        _state = BUTTON_STATE_IDLE;
      }
      break;
    case BUTTON_STATE_PRESSED:
      if (value == _valid)
      {
        _state = BUTTON_STATE_PRESSING;
        _cnt = 0;
        if (NULL != _pressed_cb) 
        {
          _pressed_cb(_cnt);
        }
      }
      else
      {
        _state = BUTTON_STATE_IDLE;
        if (NULL != _release_cb)
        {
          _release_cb(_cnt);
        }
      }
      break;
    case BUTTON_STATE_PRESSING:
      if (value == _valid)
      {
        _state = BUTTON_STATE_PRESSING;
        if (NULL != _pressing_cb)
        {
          _pressing_cb(_cnt);
        }
        _cnt++;
      }
      else
      {
        _state = BUTTON_STATE_IDLE;
        if (NULL != _release_cb)
        {
          _release_cb(_cnt);
        }
        _cnt = 0;
      }
  }
}

/*
 * Function:    getState(void)
 * Description: button get current state
 * Input:       none
 * Output:      none
 * Return:      none
 * Note:        none
 */
int Button::getState(void)
{
  return _state;
}

/*
 * Function:    getCnt(void)
 * Description: button get current pressing count
 * Input:       none
 * Output:      none
 * Return:      none
 * Note:        none
 */
int Button::getCnt(void)
{
  return _cnt;
}
