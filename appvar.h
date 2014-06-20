/*----------------------------------------------------------------------------------*-
*  'appvar.h'
*  AppVar library header for APPLINK PROTOCOL
*  Part of the iit-avionics project
*  All rights reserve. MSU-IIT Iligan City
-*----------------------------------------------------------------------------------*/

#ifndef APPVAR_H
#define APPVAR_H

#include<Arduino.h>
/*
* AppVar  Structure
* <ID><MC><DL><D>
* ID [1B]
* MC [1B]
* DL [1B]
* D {1...247}
*/

//message attributes
#define READ  0x80
#define WRITE 0x40
#define MGVAR 0x20
#define STVAR 0x10

//message types
#define T_VOID     0x00
#define T_BOOLEAN  0x01
#define T_CHAR     0x02
#define T_U_CHAR   0x03
#define T_BYTE     0x04
#define T_INT      0x05
#define T_U_INT    0x06
#define T_U_WORD   0x07
#define T_LONG     0x08
#define T_U_LONG   0x09
#define T_SHORT    0x0A
#define T_U_FLOAT  0x0B
#define T_DOUBLE   0x0C
#define T_STRING_O 0x0D
#define T_STRING_C 0x0E
#define T_ARRAY    0x0F

//message data length
#define S_BYTE       0x01
#define S_CHAR       0x01
#define S_U_LONG     0x04
#define S_U_INT      0x02

class AppVar{
  public:
    AppVar(const byte id,const byte dc,const byte dl);
    AppVar();
    void free();
    byte SetData(byte *val);
    byte *GetData();
    byte unique_id;
    byte data_class;
    byte data_length;
    byte *data;
};

#endif

