#include "LSD.h"

File myFile;


LSD::LSD():n_batiment(),n_salle(nullptr),n_pbatiment(0),n_psalle(0),n_coneluminance(0){
}

LSD::~LSD(){
  delete[] n_salle;
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
  //le fichier
  myFile = SD.open(nomFichier, FILE_WRITE);
  if (myFile) 
  {
    myFile.write(n_pbatiment%256);
    myFile.write(n_pbatiment/256);
    myFile.write(n_psalle%256);
    myFile.write(n_psalle/256);
    //Red
    myFile.write(Color[0]%256);
    //Green
    myFile.write(Color[1]%256);
    //Blue
    myFile.write(Color[2]%256);
    //Temperature de couleur
    myFile.write(Color[3]%256);
    myFile.write(Color[3]/256);
    //Eclairement
    myFile.write(Color[4]%256);
    myFile.write(Color[4]/256);
    //Luminance
    myFile.write(Color[5]%256);
    myFile.write(Color[5]/256);
    myFile.write(n_coneluminance);
    myFile.close();
  } 
  else 
  {
    Serial.println("write : error opening file");
    myFile.close();
  }
}


void LSD::addBatiment(int Batiment)
{
  List* salle = new List[Batiment];
  for(int i = 0; i < Batiment-1; i++)
  {
    salle[i] = n_salle[i];
  }
  if(n_salle != nullptr)
    delete[] n_salle;
  n_salle = salle;
}

void LSD::readfile(String SalleFile){
  myFile = SD.open(SalleFile);
  if (myFile) 
  {
    int batiment = 0;
    while (myFile.available()) 
    {
      n_batiment += myFile.position();
      myFile.readStringUntil('\n');
      String test;
      addBatiment(batiment+1);
      while((test = myFile.readStringUntil(';')) == "" && myFile.available()){
        n_salle[batiment] += myFile.position();
        myFile.readStringUntil('\n');
      }
      if(myFile.available()){
        myFile.seek(myFile.position()-test.length()-1);
      }
      batiment++;
    }
    myFile.close();
    return;
  }
  else 
  {
    Serial.println("error opening file");
    myFile.close();
  }
}


void LSD::BatimentSuivant(){
  n_psalle = 0;
  n_pbatiment++;
  if(n_pbatiment == n_batiment.size())
    n_pbatiment = 0;
}


void LSD::BatimentPrecedent(){
  n_psalle = 0;
  if(n_pbatiment == 0)
    n_pbatiment = n_batiment.size();
  n_pbatiment--;
}

void LSD::SallePrecedente(){
  if(n_psalle == 0)
    n_psalle = n_salle[n_pbatiment].size();
  n_psalle--;
}


void LSD::SalleSuivante(){
  n_psalle++;
  if(n_psalle == n_salle[n_pbatiment].size())
    n_psalle = 0;
}


String LSD::getBatiment(){
  String a = getName(n_batiment[n_pbatiment],0);
  Serial.println(n_batiment[n_pbatiment]);
  Serial.println(a);
  return a;
}

String LSD::getSalle(){
  return getName(n_salle[n_pbatiment][n_psalle],1);
}


String LSD::getName(int pos,int type){
  myFile = SD.open(CSV);
  if (myFile) 
  {
    myFile.seek(pos);
    String a;
    if(type == 0)
       a = myFile.readStringUntil(';');
    else
      a = myFile.readStringUntil('\n');
    myFile.close();
    return a;
  }
  else 
  {
    Serial.println("error opening file");
    myFile.close();
    return "";
  }
}
