#include <Servo.h>

// Define constants
const int PIN_X1 = 5;
const int PIN_Y1 = 6;
const int PIN_X2 = 9;
const int PIN_Y2 = 10;

const int SERVO_MIN = 0;
const int SERVO_MAX = 180;
const int SERVO_X1_INIT = 90;
const int SERVO_Y1_INIT = 90;
const int SERVO_X2_INIT = 90;
const int SERVO_Y2_INIT = 90;

const int BAUDRATE = 9600;

// Initial settings
Servo servoX1, servoY1, servoX2, servoY2;
int currentX1 = SERVO_X1_INIT, currentY1 = SERVO_Y1_INIT, currentX2 = SERVO_X2_INIT, currentY2 = SERVO_Y2_INIT;
int newX1, newY1, newX2, newY2;
String x1str, y1str, x2str, y2str;
String incomingData;

// Function prototypes;
void parseCommand(String data);
void updateServoAngles();

// Setup Function
void setup() {
  Serial.begin(BAUDRATE);
  servoX1.attach(PIN_X1);
  servoY1.attach(PIN_Y1);
  servoX2.attach(PIN_X2);
  servoY2.attach(PIN_Y2);
}

// Loop Function
void loop() {
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n') {
      parseCommand(incomingData);
      updateServoAngles();
      incomingData = "";
    } else {
      incomingData += c;
    }
  }
}

// Parse the command string and convert it to angle values
void parseCommand(String data) {
  data.trim();
  int firstComma = data.indexOf(',');
  int secondComma = data.indexOf(',', firstComma + 1);
  int thirdComma = data.indexOf(',', secondComma + 1);
  if (firstComma != -1 && secondComma != -1 && thirdComma != -1) {
    x1str = data.substring(0, firstComma);
    y1str = data.substring(firstComma + 1, secondComma);
    x2str = data.substring(secondComma + 1, thirdComma);
    y2str = data.substring(thirdComma + 1);
    newX1 = x1str.toInt();
    newY1 = y1str.toInt();
    newX2 = x2str.toInt();
    newY2 = y2str.toInt();
  }
}

// Update the servo angles only if they differ from the current ones
void updateServoAngles() {
  if (newX1 != currentX1 && newX1 >= SERVO_MIN && newX1 <= SERVO_MAX) {
    servoX1.write(newX1);
    currentX1 = newX1;
  }
  if (newY1 != currentY1  && newY1 >= SERVO_MIN && newY1 <= SERVO_MAX) {
    servoY1.write(newY1);
    currentY1 = newY1;
  }
}
