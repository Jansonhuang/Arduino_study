#include <SimpleLED.h>
#include <Button.h>

#define BUTTON_DETECT_INTERVAL    (50)
#define BUTTON_DETECT_CNT         (1000 / BUTTON_DETECT_INTERVAL)
#define LAMP_OFF                  (0)
#define LAMP_ON                   (1)

Button touch_pad(8, HIGH);
SimpleLED lamp_led(13, HIGH);
int lamp_state = LAMP_OFF;

void pressed_func(int cnt)
{
  if (LAMP_OFF == lamp_state)
  {
    lamp_state = LAMP_ON;
  }
  else
  {
    lamp_state = LAMP_OFF;
  }
  lamp_led.led_set_value(lamp_state);
}

#if 0
void pressing_func(int cnt)
{
  if (cnt % BUTTON_DETECT_CNT)
  {
    Serial.print("pressing: ");
    Serial.println(cnt);
  }
}

void release_func(int cnt)
{
  Serial.print("release: ");
  Serial.println(cnt);
}
#endif

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //touch_pad.setCallBack(pressed_func, pressing_func, release_func);
  touch_pad.setCallBack(pressed_func, NULL, NULL);
  lamp_led.led_set_value(lamp_state);
}

void loop() {
  // put your main code here, to run repeatedly:
  touch_pad.detect();
  delay(BUTTON_DETECT_INTERVAL);
}
