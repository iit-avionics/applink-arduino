/*----------------------------------------------------------------------------------*-
*  'applink.h'
*  Applink library header for APPLINK PROTOCOL
*  Part of the iit-avionics project
*  All rights reserve. MSU-IIT Iligan City
-*----------------------------------------------------------------------------------*/

#ifndef APPLINK_H
#define APPLINK_H

#include  <Arduino.h>
#include <appvar.h>

/*
* AppLink Packet Structure
* <SS0><SS1><PLe>|<MSG CLASS><APPVAR><APPVAR>...<APPVAR><CS>|<ES>
* SS0 [1B]
* SS1 [1B]
* PLe [1B]
* MSG CLASS [1B]
* APPVARn {1...250}
* CS [1B]
* ES [1B]
*/


//packet sequence markers
#define SS0 0x0A
#define SS1 0x0B
#define ES  0xFF


//Message Class Types
#define P_S_STREAM   0x00
#define P_M_STREAM   0x80
#define P_S_APPVAR   0x00
#define P_M_APPVAR   0x40
#define P_BROADCAST  0x00
#define P_QUERY      0x10
#define P_COMMAND    0x20



class AppLinkPacket{
   public:
     AppLinkPacket();
     //AppLinkPacket(byte *msg);
     AppLinkPacket(const AppVar v);
     AppLinkPacket(const AppVar *varArray,const byte sz);
     //AppLinkPacket(MC card format)
     void free(void);
     void Write(void);
     //void Read(void);
     byte payload_length;
     byte message_class;
     byte checksum;
     byte *serial_message;
};


#endif

