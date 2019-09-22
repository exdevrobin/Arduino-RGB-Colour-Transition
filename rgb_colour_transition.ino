/**
  DEV-19 ard_led_0001
  Name: RGB LED Smooth Color Transition
  Purpose: RGB LED smooth color transition is achieved covering all colors in the spectrum.

  @author exdev robin
  @version 1.0 22-09-2019
*/

int redValue = 0;
int greenValue = 0;
int blueValue = 0;
int mode = 0;
int speed[] = {50, 100, 150};

const int RED_PIN = 4;
const int GREEN_PIN = 3;
const int BLUE_PIN = 2;
const int SECOND = 1000;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  initSpectrum();
}

void loop() {
  transformColor(true, false, false, true);   //green to yellow
  delay(SECOND);
  transformColor(false, true, false, false);  //yellow to red
  delay(SECOND);
  transformColor(false, false, true, true);   //red to magenta
  delay(SECOND);
  transformColor(true, false, false, false);  //magenta to blue
  delay(SECOND);
  transformColor(false, true, false, true);    //blue to cyan
  delay(SECOND);
  transformColor(false, false, true, false);   //cyan to green
  delay(SECOND);
}

/**
  Initiate Glows from idle
*/
void initSpectrum() {
  for (int i = 0; i <= 255; i = i + 1) { //black to white
    redValue = i;
    greenValue = i;
    blueValue = i;

    setInvertedRGB(RED_PIN, GREEN_PIN, BLUE_PIN, redValue, greenValue, blueValue);
    delay(SECOND / speed[mode]);
  }
  transformColor(true, false, true, false); //white to green
  delay(SECOND);
}

/**
  Change a certain color from high to low or vice versa

  @param red modify red value if 'true'
  @param green modify green value if 'true'
  @param blue modify blue value if 'true'
  @param incVal increase Value if 'true',  Decrease Value if 'false'
*/
void transformColor(boolean red, boolean green, boolean blue, boolean incVal) {
  if (incVal) { //increase from low to high
    for (int i = 0; i <= 255; i = i + 1) {
      if (red) {
        redValue = i;
      }
      if (green) {
        greenValue = i;
      }
      if (blue) {
        blueValue = i;
      }
      setInvertedRGB(RED_PIN, GREEN_PIN, BLUE_PIN, redValue, greenValue, blueValue);
      delay(SECOND / speed[mode]);
    }
  }
  else { //decrease from high to low
    for (int i = 255; i >= 0; i = i - 1) {
      if (red) {
        redValue = i;
      }
      if (green) {
        greenValue = i;
      }
      if (blue) {
        blueValue = i;
      }
      setInvertedRGB(RED_PIN, GREEN_PIN, BLUE_PIN, redValue, greenValue, blueValue);
      delay(SECOND / speed[mode]);
    }
  }
}

/**
  This function sets color values for RGB Common Anode LED.

  @param rPin Red pin value in integer
  @param gPin Green pin value in integer
  @param bPin Blue pin value in integer
  @param rVal Red Color value in integer
  @param gVal Green Color value in integer
  @param bVal Blue Color value in integer
*/
void setInvertedRGB(int rPin, int gPin, int bPin, int rVal, int gVal, int bVal) {
  analogWrite(rPin, 255 - rVal);
  analogWrite(gPin, 255 - gVal);
  analogWrite(bPin, 255 - bVal);
}

/**
  This function sets color values for RGB Common Anode LED.

  @param rPin Red pin value in integer
  @param gPin Green pin value in integer
  @param bPin Blue pin value in integer
  @param rVal Red Color value in integer
  @param gVal Green Color value in integer
  @param bVal Blue Color value in integer
*/
void setRGB(int rPIN, int gPin, int bPin, int rVal, int gVal, int bVal) {
  analogWrite(rPIN, rVal);
  analogWrite(gPin, gVal);
  analogWrite(bPin, bVal);
}

/*end of program*/
