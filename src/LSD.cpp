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

void LSD::readfile(String SelectedSalle){
  myFile = SD.open(SelectedSalle);
  if (myFile) 
  {
    while (myFile.available()) 
    {
      n_batiment += myFile.position();
      Serial.println(n_batiment[0]);
      myFile.readStringUntil('\n');
      String test;
      while((test = myFile.readStringUntil(';')) == "" && myFile.available()){
        myFile.readStringUntil('\n');
      }
      if(myFile.available()){
        myFile.seek(myFile.position()-test.length()-1);
      }
      
    }
    myFile.close();
    n_batiment += -1;
    return;
  }
  else 
  {
    Serial.println("error opening file");
  }
}

void LSD::readBatimentName(int SelectedBatiment){
  myFile = SD.open(CSV);
  if (myFile) 
  {
    Serial.println(n_batiment[SelectedBatiment]);
    myFile.seek(n_batiment[SelectedBatiment]);
    Serial.println(myFile.readStringUntil(';'));
    Serial.println(myFile.readStringUntil(';'));
    myFile.close();
  }
  else 
  {
    Serial.println("error opening file");
  }
}