#include "LSD.h"

File myFile;
void SDsetup(int pinCS)
{
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin 
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output 
  // or the SD library functions will not work. 
   pinMode(pinCS, OUTPUT);
 
  if (!SD.begin(pinCS)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
}



//writing parameter to sd card
void SDwrite(String nomFichier, String data)
{
  myFile = SD.open(nomFichier, FILE_WRITE);
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


//reading parameter from sd card
void SDread(String nomFichier, String* data)
{
  myFile = SD.open(nomFichier);
  if (myFile) 
  {
    if(nomFichier == "config.txt" && myFile.available())
      myFile.readStringUntil('\n');
    while (myFile.available()) 
    {
      *data += myFile.readStringUntil('\n');
    }
    myFile.close();
  }
  else 
  {
    Serial.println("error opening file");
  }
}
