#ifndef GLOBALS_H // header guards
#define GLOBALS_H

#define S_BUF_LENGTH 1024
#define PV_BUF_LENGTH 256
#define T_BUF_LENGTH S_BUF_LENGTH+PV_BUF_LENGTH
//index of Bufferstart;
extern int sBufStart;


//Token musst be matching S_Buf And PV_buf_LEGNTH!!!
typedef struct Token
{
   unsigned int offset:10;
   unsigned int length:8;
   unsigned char c;
}Token;


#endif
