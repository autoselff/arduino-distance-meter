#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TRIG 9 // pin 9 sends signal to the distance sensor
#define ECHO 10 // pin 10 receive answer signal from the distance sensor

// creating lcd object
LiquidCrystal_I2C lcd(0x27, 16, 2);
// 0x27 location of the l2c converter
// 16 number of colums
// 2 number of rows

void setup() {
    pinMode(TRIG, OUTPUT); // send signal 
    pinMode(ECHO, INPUT); // receives signal

    lcd.init();  // lcd display initialization
    lcd.backlight(); // turn on backlight
    lcd.setCursor(0, 0); // go to the (0, 0) index (column, row)
    lcd.print("Distance:"); // print text
}

void loop() {
    // sending signal to the sensor
    digitalWrite(TRIG, LOW);  delayMicroseconds(2); // making sure that trig is 0V
    digitalWrite(TRIG, HIGH); delayMicroseconds(10); // emiting high signal 5V on TRIG pin
    digitalWrite(TRIG, LOW); // return to the 0V

    // check how long ECHO was HIGH
    // pulseIn calculates how long echo pin was on high
    long h_time = pulseIn(ECHO, HIGH); // microseconds

    // calculate distance
    // speed of sound = 343 m/s = 0.0343 cm/us
    // divide by 2 because sound travels to object AND back
    float distance = (h_time * 0.0343) / 2.0;

    // show result on the lcd display
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print(distance);
    lcd.print(" cm");

    delay(500);
}

// library: https://github.com/johnrickman/LiquidCrystal_I2C?tab=readme-ov-file
// sudo usermod -a -G dialout $USER
// sudo chmod 666 /dev/ttyUSB0
