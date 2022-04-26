#pragma once
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include "Adafruit_TCS34725.h"

// Pick analog outputs, for the UNO these three work well
// use ~560  ohm resistor between Red & Blue, ~1K for green (its brighter)
#define redpin 3
#define greenpin 5
#define bluepin 6
// for a common anode LED, connect the common pin to +5V
// for common cathode, connect the common to ground

#define PIN_RED 10
#define PIN_GREEN 9
#define PIN_BLUE 8

// set to false if using a common cathode LED
#define commonAnode true



void ColorSetup(byte *gammatable, Adafruit_TCS34725 *tcs);
void ColorRead(byte *gammatable, Adafruit_TCS34725 *tcs, int* &colorInfo);

