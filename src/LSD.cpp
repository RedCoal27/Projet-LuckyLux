#include "LSD.h"

File myFile;
void SDsetup()
{
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin 
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output 
  // or the SD library functions will not work. 
   pinMode(10, OUTPUT);
 
  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  
}



//writing parameter to sd card
void SDwrite(String data)
{
  myFile = SD.open("data.csv", FILE_WRITE);
  if (myFile) 
  {
    myFile.println(data);
   
    myFile.close();
   
  } 
  else 
  {
    Serial.println("error opening file");
  }
}

//writing bullshit to sd card
void SDwriteBullshit(String data)
{
  myFile = SD.open("data.csv", FILE_WRITE);
  if (myFile) 
  {
    myFile.println(data);
   
    myFile.close();
   
  } 
  else 
  {
    Serial.println("error opening file");
  }
}
