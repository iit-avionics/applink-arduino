/*----------------------------------------------------------------------------------*-
*  'applink.cpp'
*  Applink library implementation for APPLINK PROTOCOL
*  Part of the iit-avionics project
*  All rights reserve. MSU-IIT Iligan City
-*----------------------------------------------------------------------------------*/

#include "applink.h"

/*
*  AppLinkPacket Constructor using an AppVar object parameter.
*  AppVar object is converted into an AppLinkPacket serial format
*  ready for deployment at the UART Port
*/

AppLinkPacket::AppLinkPacket(){}

AppLinkPacket::AppLinkPacket(const AppVar v){
  byte m,i=0;
 
  message_class = P_S_STREAM |P_S_APPVAR| P_BROADCAST;
  payload_length = v.data_length + 3 + 2;
  checksum = message_class;
  
  //serial message container
  serial_message = new byte[payload_length + 4];  
  
  serial_message[i++] = SS0;
  serial_message[i++] = SS1;
  serial_message[i++] = payload_length;
  serial_message[i++] = message_class;  

  serial_message[i++] = v.unique_id;
  serial_message[i++] = v.data_class;
  serial_message[i++] = v.data_length;
  for(m=0;m<v.data_length;m++){
    serial_message[i++] = v.data[m];
  }
  
  //compute for checksum
  for(m=4;m<i;m++){
    checksum = checksum ^ serial_message[m];
  }
  serial_message[i++] = checksum;
  serial_message[i++] = ES;    
}



/*
*  AppLinkPacket Constructor using an array of AppVar object as parameter.
*  AppVar object is converted into an AppLinkPacket serial format
*  ready for deployment at the UART Port
*/

AppLinkPacket::AppLinkPacket(const AppVar *varArray,const byte sz){
  
  byte n,m,i=0,z=0;
  
  //find payload length
  for(n=0;n<sz;n++){
    z = z + 3 + varArray[n].data_length;
  }

  message_class = P_S_STREAM |P_M_APPVAR| P_BROADCAST;
  payload_length = z + 2;
  checksum = message_class;
  
  //serial message container
  serial_message = new byte[payload_length + 4];  
  
  serial_message[i++] = SS0;
  serial_message[i++] = SS1;
  serial_message[i++] = payload_length;
  serial_message[i++] = message_class;
  
  //loop through each of AppVar
  for(n=0;n<sz;n++){
    serial_message[i++] = varArray[n].unique_id;
    serial_message[i++] = varArray[n].data_class;
    serial_message[i++] = varArray[n].data_length;
    //Serial.println(varArray[n].data_length);
    for(m=0;m<varArray[n].data_length;m++){
      serial_message[i++] = varArray[n].data[m];
    }
  }
  

  //compute for checksum
  for(n=4;n<i;n++){
    checksum = checksum ^ serial_message[n];
  }
  serial_message[i++] = checksum;
  serial_message[i++] = ES;

}

void AppLinkPacket::free(){
  delete [] serial_message;
}

void AppLinkPacket::Write(){
  byte i;
  for(i=0;i<payload_length + 4;i++){
    Serial.print(serial_message[i],HEX);
    Serial.print(" ");
  }
  Serial.println();
}

