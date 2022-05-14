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
void LSD::write(String nomFichier, int* Color)
{
  //random test
    n_pbatiment++;
    Serial.println(n_batiment[n_pbatiment]);
    if(n_batiment[n_pbatiment] == -1)
      n_pbatiment = 0;
    n_psalle = rand()%2;

  //le fichier
  myFile = SD.open(nomFichier, FILE_WRITE);
  if (myFile) 
  {
    myFile.write(n_pbatiment%256);
    myFile.write(n_pbatiment/256);
    myFile.write(n_psalle%256);
    myFile.write(n_psalle/256);
    myFile.write(Color[0]%256);
    myFile.write(Color[1]%256);
    myFile.write(Color[2]%256);
    myFile.write(Color[3]%256);
    myFile.write(Color[3]/256);
    myFile.write(Color[4]%256);
    myFile.write(Color[4]/256);
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
    myFile.close();
    return myFile.readStringUntil(';');
  }
  else 
  {
    Serial.println("error opening file");
    myFile.close();
  }
}