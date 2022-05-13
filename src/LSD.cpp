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
void LSD::write(String nomFichier,u_int16_t Batiment,u_int16_t Salle, int* Color,  u_int16_t Eclairement, u_int16_t Luminance)
{
  myFile = SD.open(nomFichier, FILE_WRITE);
  if (myFile) 
  {
    myFile.write(Batiment/256);
    myFile.write(Batiment%256);
    myFile.write(Salle/256);
    myFile.write(Salle%256);
    myFile.write(Color[0]);
    myFile.write(Color[1]);
    myFile.write(Color[2]);
    myFile.write(Eclairement/256);
    myFile.write(Eclairement%256);
    myFile.write(Luminance/256);
    myFile.write(Luminance%256);
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
    myFile.close();
  }
}

String LSD::readBatimentName(int SelectedBatiment){
  myFile = SD.open(CSV);
  if (myFile) 
  {
    Serial.println(n_batiment[SelectedBatiment]);
    myFile.seek(n_batiment[SelectedBatiment]);
    return myFile.readStringUntil(';');
  }
  else 
  {
    Serial.println("error opening file");
  }
  myFile.close();
}