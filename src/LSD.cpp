#include "LSD.h"

File myFile;

LSD::LSD(){
}

LSD::~LSD(){
}


void LSD::setup(int pinCS)
{
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
   pinMode(pinCS, OUTPUT);
 
  if (!SD.begin(pinCS)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
}


//writing parameter to sd card
void LSD::write(String nomFichier, String data)
{
  myFile = SD.open(nomFichier, FILE_WRITE);
  if (myFile) 
  {
    myFile.println(data);
   
    myFile.close();
   
  } 
  else 
  {
    Serial.println("write : error opening file");
  }
}


//reading parameter from sd card
void LSD::read(String nomFichier, String* data)
{
  myFile = SD.open(nomFichier);
  if (myFile) 
  {
    while (myFile.available()) 
    {
      *data += myFile.readStringUntil('\n');
    }
    myFile.close();
  }
  else 
  {
    Serial.println("write salle: error opening file");
  }
}

void LSD::writeSalle(String SelectedSalle, String data)
{
  myFile = SD.open("data.csv", O_RDWR);
  if (myFile) 
  {
    int oui = 0;
    while(myFile.available()){
      oui++;
      Serial.println(oui);
      String line = myFile.readStringUntil(';');
      const String test="Mesure";
      myFile.readStringUntil('\n');
      if(line == SelectedSalle) {
        int i = 0;
        Serial.println("found");
        while((line = myFile.readStringUntil('\n')).substring(0,5)==test.substring(0,5)){
          i++;
          Serial.println(line);
        }
        myFile.seek(myFile.position()-line.length());
        Serial.println("Mesure "+ String(i) + ';' + data+"\n"+line+"\n");
        myFile.print("Mesure "+ String(i) + ';' + data+"\n"+line+"\n");
        myFile.close();
        return;
      }
    }
  }
  else
  {
    Serial.println("error opening file");
  }
    
}