#include "color.h"

void ColorSetup(byte *gammatable, Adafruit_TCS34725 *tcs)
{
  // Serial.println("Color View Test!");

  if (tcs->begin())
  {
    // Serial.println("Found sensor");
  }
  else
  {
    Serial.println("No TCS34725 found ... check your connections");
    while (1)
      ; // halt!
  }

  // thanks PhilB for this gamma table!
  // it helps convert RGB colors to what humans see
  for (int i = 0; i < 256; i++)
  {
    float x = i;
    x /= 255;
    x = pow(x, 2.5);
    x *= 255;

    if (commonAnode)
    {
      gammatable[i] = 255 - x;
    }
    else
    {
      gammatable[i] = x;
    }
    // Serial.println(gammatable[i]);
  }
}

// The commented out code in loop is example of getRawData with clear value.
// Processing example colorview.pde can work with this kind of data too, but It requires manual conversion to
// [0-255] RGB value. You can still uncomments parts of colorview.pde and play with clear value.
void ColorRead(byte *gammatable, Adafruit_TCS34725 *tcs,int* &colorInfo)
{
  float red, green, blue;

  tcs->setInterrupt(false); // turn on LED

  delay(60); // takes 50ms to read

  tcs->getRGB(&red, &green, &blue);

  tcs->setInterrupt(true); // turn off LED
  colorInfo[0] = int(red);
  colorInfo[1] = int(green);
  colorInfo[2] = int(blue);
  
}