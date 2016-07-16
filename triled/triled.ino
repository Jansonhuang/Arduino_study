/*
 * Description: A tri-led evaluation code
 * Hardware connection: 
 *      RED   ---- TRILED_RED_PORT
 *      GREEN ---- TRILED_GREEN_PORT
 *      BLUE  ---- TRILED_BLUE_PORT
 * Author: Janson <jansonhuang1989@gmail.com>
 * Revision:
 * Rev 1.0.0, 16Jul2016, Janson, Create the file.
 */

// Hardware configurations:
#define TRILED_RED_PORT     (7)
#define TRILED_GREEN_PORT   (6)
#define TRILED_BLUE_PORT    (5)
#define TRILED_ACTIVE       HIGH
#define TRILED_INACTIVE     LOW

// Test relevant params:
#define TRILED_DELAY        (1000)
#define TRILED_SHORT_DELAY  (100)
#define TRILED_PWM_STEP     (32)

/*
 * Function:    triled_set_red
 * Description: Set triled to red
 * Input:       none
 * Output:      none
 * Return:      none
 * Note:        none
 */
void triled_set_red() {
  digitalWrite(TRILED_RED_PORT, TRILED_ACTIVE);
  digitalWrite(TRILED_GREEN_PORT, TRILED_INACTIVE);
  digitalWrite(TRILED_BLUE_PORT, TRILED_INACTIVE);
}

/*
 * Function:    triled_set_green
 * Description: Set triled to green
 * Input:       none
 * Output:      none
 * Return:      none
 * Note:        none
 */
void triled_set_green() {
  digitalWrite(TRILED_RED_PORT, TRILED_INACTIVE);
  digitalWrite(TRILED_GREEN_PORT, TRILED_ACTIVE);
  digitalWrite(TRILED_BLUE_PORT, TRILED_INACTIVE);
}

/*
 * Function:    triled_set_blue
 * Description: Set triled to blue
 * Input:       none
 * Output:      none
 * Return:      none
 * Note:        none
 */
void triled_set_blue() {
  digitalWrite(TRILED_RED_PORT, TRILED_INACTIVE);
  digitalWrite(TRILED_GREEN_PORT, TRILED_INACTIVE);
  digitalWrite(TRILED_BLUE_PORT, TRILED_ACTIVE);
}

/*
 * Function:    triled_set_red
 * Description: Set triled according through pwm setting
 * Input:       red         red pwm value
 *              green       green pwm value
 *              blue        blue pwm value
 * Output:      none
 * Return:      none
 * Note:        none
 */
void triled_set_rgb(unsigned char red, unsigned char green, unsigned blue) {
  analogWrite(TRILED_RED_PORT, red);
  analogWrite(TRILED_GREEN_PORT, green);
  analogWrite(TRILED_BLUE_PORT, blue);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(TRILED_RED_PORT, OUTPUT);
  pinMode(TRILED_GREEN_PORT, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned int red_pwm = 0;
  unsigned int green_pwm = 0;
  unsigned int blue_pwm = 0;
  
  triled_set_red();
  delay(TRILED_DELAY);
  triled_set_green();
  delay(TRILED_DELAY);
  triled_set_blue();
  delay(TRILED_DELAY);

  for (red_pwm = 0; red_pwm < 256; red_pwm += TRILED_PWM_STEP) {
    for (green_pwm = 0; green_pwm < 256; green_pwm += TRILED_PWM_STEP) {
      for (blue_pwm = 0; blue_pwm < 256; blue_pwm += TRILED_PWM_STEP) {
        triled_set_rgb((unsigned char)red_pwm, (unsigned char)green_pwm, (unsigned char)blue_pwm);
        delay(TRILED_SHORT_DELAY);
      }
    }
  }
}
