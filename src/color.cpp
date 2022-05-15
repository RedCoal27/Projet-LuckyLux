#include "color.h"


//
// Gain/time combinations to use and the min/max limits for hysteresis
// that avoid saturation. They should be in order from dim to bright.
//
// Also set the first min count and the last max count to 0 to indicate
// the start and end of the list.
//
const tcs34725::tcs_agc tcs34725::agc_lst[] = {
  { TCS34725_GAIN_60X, TCS34725_INTEGRATIONTIME_614MS,     0, 20000 },
  { TCS34725_GAIN_60X, TCS34725_INTEGRATIONTIME_154MS,  4990, 63000 },
  { TCS34725_GAIN_16X, TCS34725_INTEGRATIONTIME_154MS, 16790, 63000 },
  { TCS34725_GAIN_4X,  TCS34725_INTEGRATIONTIME_154MS, 15740, 63000 },
  { TCS34725_GAIN_1X,  TCS34725_INTEGRATIONTIME_154MS, 15740, 0 }
};
tcs34725::tcs34725() : agc_cur(0), isAvailable(0), isSaturated(0) {
}

// initialize the sensor
boolean tcs34725::begin(void) {
  tcs = Adafruit_TCS34725(agc_lst[agc_cur].at, agc_lst[agc_cur].ag);
  if ((isAvailable = tcs.begin()))
    setGainTime();
  return(isAvailable);
}

// Set the gain and integration time
void tcs34725::setGainTime(void) {
  tcs.setGain(agc_lst[agc_cur].ag);
  tcs.setIntegrationTime(agc_lst[agc_cur].at);
  atime = int(agc_lst[agc_cur].at);
  atime_ms = ((256 - atime) * 2.4);
  switch(agc_lst[agc_cur].ag) {
  case TCS34725_GAIN_1X:
    againx = 1;
    break;
  case TCS34725_GAIN_4X:
    againx = 4;
    break;
  case TCS34725_GAIN_16X:
    againx = 16;
    break;
  case TCS34725_GAIN_60X:
    againx = 60;
    break;
  }
}

// Retrieve data from the sensor and do the calculations
void tcs34725::getData(void) {
  // read the sensor and autorange if necessary
  tcs.getRawData(&r, &g, &b, &c);
  while(1) {
    if (agc_lst[agc_cur].maxcnt && c > agc_lst[agc_cur].maxcnt)
      agc_cur++;
    else if (agc_lst[agc_cur].mincnt && c < agc_lst[agc_cur].mincnt)
      agc_cur--;
    else break;

    setGainTime();
    delay((256 - atime) * 2.4 * 2); // shock absorber
    tcs.getRawData(&r, &g, &b, &c);
    break;
  }

  // DN40 calculations
  ir = (r + g + b > c) ? (r + g + b - c) / 2 : 0;
  r_comp = r - ir;
  g_comp = g - ir;
  b_comp = b - ir;
  c_comp = c - ir;
  cratio = float(ir) / float(c);

  saturation = ((256 - atime) > 63) ? 65535 : 1024 * (256 - atime);
  saturation75 = (atime_ms < 150) ? (saturation - saturation / 4) : saturation;
  isSaturated = (atime_ms < 150 && c > saturation75) ? 1 : 0;
  cpl = (atime_ms * againx) / (TCS34725_GA * TCS34725_DF);
  maxlux = 65535 / (cpl * 3);

  lux = (TCS34725_R_Coef * float(r_comp) + TCS34725_G_Coef * float(g_comp) + TCS34725_B_Coef * float(b_comp)) / cpl;
  ct = TCS34725_CT_Coef * float(b_comp) / float(r_comp) + TCS34725_CT_Offset;
}


void tcs34725::ColorSetup(byte *gammatable)
{
  Serial.begin(115200);
  begin();
}

// The commented out code in loop is example of getRawData with clear value.
// Processing example colorview.pde can work with this kind of data too, but It requires manual conversion to
// [0-255] RGB value. You can still uncomments parts of colorview.pde and play with clear value.
void tcs34725::ColorRead(byte *gammatable,int* &colorInfo)
{
  Serial.println("Reading color...");
  getData();

  Serial.print(F("Gain:"));
  Serial.print(againx);
  Serial.print(F("x "));
  Serial.print(F("Time:"));
  Serial.print(atime_ms);
  Serial.print(F("ms (0x"));
  Serial.print(atime, HEX);
  Serial.println(F(")"));

  Serial.print(F("Raw R:"));
  Serial.print(r);
  Serial.print(F(" G:"));
  Serial.print(g);
  Serial.print(F(" B:"));
  Serial.print(b);
  Serial.print(F(" C:"));
  Serial.println(c);

  Serial.print(F("IR:"));
  Serial.print(ir);
  Serial.print(F(" CRATIO:"));
  Serial.print(cratio);
  Serial.print(F(" Sat:"));
  Serial.print(saturation);
  Serial.print(F(" Sat75:"));
  Serial.print(saturation75);
  Serial.print(F(" "));
  Serial.println(isSaturated ? "*SATURATED*" : "");

  Serial.print(F("CPL:"));
  Serial.print(cpl);
  Serial.print(F(" Max lux:"));
  Serial.println(maxlux);

  Serial.print(F("Compensated R:"));
  Serial.print(r_comp);
  Serial.print(F(" G:"));
  Serial.print(g_comp);
  Serial.print(F(" B:"));
  Serial.print(b_comp);
  Serial.print(F(" C:"));
  Serial.println(c_comp);

  Serial.print(F("Lux:"));
  Serial.print(lux);
  Serial.print(F(" CT:"));
  Serial.print(ct);
  Serial.println(F("K"));

  Serial.println();
  float r,g,b;
  // Avoid divide by zero errors ... if clear = 0 return black
  if (c_comp == 0) {
    r = g = b = 0;
  }
  else{
    r = (float)r_comp / c_comp * 255.0;
    g = (float)g_comp / c_comp * 255.0;
    b = (float)b_comp / c_comp * 255.0;
  }

  colorInfo[0] = u_int8_t(r);
  colorInfo[1] = u_int8_t(g);
  colorInfo[2] = u_int8_t(b);
  colorInfo[3] = u_int16_t(lux);
  colorInfo[4] = u_int16_t(0);
}