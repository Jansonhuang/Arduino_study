#include <SimpleLED.h>
#include <Triled.h>

#define COMMON_DELAY      (1000)
#define TRILED_ON         (1)
#define TRILED_OFF        (0)
#define TRILED_RED_GPIO_NUM   (5)
#define TRILED_GREEN_GPIO_NUM (6)
#define TRILED_BLUE_GPIO_NUM  (7)

Triled tri_led(SimpleLED(TRILED_RED_GPIO_NUM, HIGH), \
               SimpleLED(TRILED_GREEN_GPIO_NUM, HIGH), \
               SimpleLED(TRILED_BLUE_GPIO_NUM, HIGH));

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  tri_led.set_value(TRILED_ON, TRILED_OFF, TRILED_OFF);  // display red
  delay(COMMON_DELAY);
  tri_led.set_value(TRILED_OFF, TRILED_ON, TRILED_OFF);  // display green
  delay(COMMON_DELAY);
  tri_led.set_value(TRILED_OFF, TRILED_OFF, TRILED_ON);  // display blue
  delay(COMMON_DELAY);
}
