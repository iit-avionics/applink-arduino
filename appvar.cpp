/*----------------------------------------------------------------------------------*-
*  'appvar.cpp'
*  AppVar library implementation for APPLINK PROTOCOL
*  Part of the iit-avionics project
*  All rights reserve. MSU-IIT Iligan City
-*----------------------------------------------------------------------------------*/

#include "appvar.h"


AppVar::AppVar(){}

AppVar::AppVar(const byte id,const byte dc,const byte dl){
    unique_id = id;
    data_class = dc;
    data_length = dl;
    data = new byte[dl];
}

void AppVar::free(void){
  delete [] data;
}

byte AppVar::SetData(byte *val){
  byte i;
  for(i=0;i<data_length;i++){
    data[i]=val[i];
  }
  return 0;
}


byte* AppVar::GetData(){
  return data;
}

