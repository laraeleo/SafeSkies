#include <Servo.h>

// Define constants
const int PIN_X1 = 5;
const int PIN_Y1 = 6;
const int PIN_X2 = 9;
const int PIN_Y2 = 10;

const int SERVO_MIN = 0;
const int SERVO_MAX = 180;
const int SERVO_X1_INIT = 65;
const int SERVO_Y1_INIT = 90;
const int SERVO_X2_INIT = 115;
const int SERVO_Y2_INIT = 90;

const int SEARCH_HEIGHT_1 = 30;
const int SEARCH_HEIGHT_2 = 90;
const int SEARCH_HEIGHT_3 = 150;

const int BAUDRATE = 9600;

// Initial settings
Servo servoX1, servoY1, servoX2, servoY2;
int currentX1 = SERVO_X1_INIT, currentY1 = SERVO_Y1_INIT, currentX2 = SERVO_X2_INIT, currentY2 = SERVO_Y2_INIT;
int newX1, newY1, newX2, newY2;
String x1str, y1str, x2str, y2str;
String incomingData;

// Function prototypes
void scanEnvironment(int c1, int c2);

// Setup Function
void setup() {
  Serial.begin(BAUDRATE);
  servoX1.attach(PIN_X1);
  servoY1.attach(PIN_Y1);
  servoX2.attach(PIN_X2);
  servoY2.attach(PIN_Y2);
  servoX1.write(SERVO_X1_INIT);
  servoY1.write(SERVO_Y1_INIT);
  servoX2.write(SERVO_X2_INIT);
  servoY2.write(SERVO_Y2_INIT);
}

// Loop Function
void loop() {
  scanEnvironment(1, 1);
  delay(5000);
  scanEnvironment(1, 0);
  delay(5000);
  scanEnvironment(0, 1);
  delay(5000);
}

// Scan the environment
void scanEnvironment(int c1, int c2) {
  if (c1 && c2) {
    servoY1.write(SEARCH_HEIGHT_1);
    servoY2.write(SEARCH_HEIGHT_1);
    for (int pos = 0; pos <= 180; pos++) {
      servoX1.write(pos);
      servoX2.write(pos);
      delay(15);
    }
    servoY1.write(SEARCH_HEIGHT_2);
    servoY2.write(SEARCH_HEIGHT_2);
    for (int pos = 0; pos <= 180; pos++) {
      servoX1.write(pos);
      servoX2.write(pos);
      delay(15);
    }
    servoY1.write(SEARCH_HEIGHT_3);
    servoY2.write(SEARCH_HEIGHT_3);
    for (int pos = 0; pos <= 180; pos++) {
      servoX1.write(pos);
      servoX2.write(pos);
      delay(15);
    }
    servoX1.write(SERVO_X1_INIT);
    servoY1.write(SERVO_Y1_INIT);
    servoX2.write(SERVO_X2_INIT);
    servoY2.write(SERVO_Y2_INIT);
  }
  else if (c1) {
    servoY1.write(newY1);
    for (int pos = 0; pos <= 180; pos++) {
      servoX1.write(pos);
      delay(15);
    }
    servoX1.write(SERVO_X1_INIT);
  }
  else if (c2) {
    servoY2.write(newY2);
    for (int pos = 0; pos <= 180; pos++) {
      servoX2.write(pos);
      delay(15);
    }
    servoX2.write(SERVO_X2_INIT);
  }
}
