#include <globaldefs.h>
ARM
struct SHA1Context { unsigned state[5]; unsigned low,high; int used; unsigned buffer[16]; };
extern "C" void (*data_020f2154)(SHA1Context*,const void*,unsigned);
extern "C" void MIi_CpuClear32(int,void*,unsigned);
// Original: arm9/main @ 0x020C0A40; symbol: func_020c0a40; size: 0x1FC.
extern "C" void Util_FinalizeSHA1Digest(SHA1Context* context,unsigned char* digest) {
 int count=context->used;
 unsigned* words=context->buffer;
 int index=count>>2;
 if(!(count&3))words[index]=0;
 unsigned char* bytes=(unsigned char*)context->buffer;
 bytes[count++]=0x80;
 while(count&3)bytes[count++]=0;
 index++;
 if(context->used>=56) {
  while(index<16) {words[index]=0;index++;}
  data_020f2154(context,words,64);
  index=0;
 }
 while(index<14) {words[index]=0;index++;}
 unsigned low=context->low;
 bytes[63]=(unsigned char)low; bytes[62]=(unsigned char)(low>>8);bytes[61]=(unsigned char)(low>>16);bytes[60]=(unsigned char)(low>>24);
 unsigned high=context->high;
 bytes[59]=(unsigned char)high;bytes[58]=(unsigned char)(high>>8);bytes[57]=(unsigned char)(high>>16);bytes[56]=(unsigned char)(high>>24);
 data_020f2154(context,words,64);
 { unsigned value=context->state[0];
 digest[0]=(unsigned char)(value>>24);
 digest[1]=(unsigned char)(value>>16);
 digest[2]=(unsigned char)(value>>8);
 digest[3]=(unsigned char)(value);
 }
 { unsigned value=context->state[1];
 digest[4]=(unsigned char)(value>>24);
 digest[5]=(unsigned char)(value>>16);
 digest[6]=(unsigned char)(value>>8);
 digest[7]=(unsigned char)(value);
 }
 { unsigned value=context->state[2];
 digest[8]=(unsigned char)(value>>24);
 digest[9]=(unsigned char)(value>>16);
 digest[10]=(unsigned char)(value>>8);
 digest[11]=(unsigned char)(value);
 }
 { unsigned value=context->state[3];
 digest[12]=(unsigned char)(value>>24);
 digest[13]=(unsigned char)(value>>16);
 digest[14]=(unsigned char)(value>>8);
 digest[15]=(unsigned char)(value);
 }
 { unsigned value=context->state[4];
 digest[16]=(unsigned char)(value>>24);
 digest[17]=(unsigned char)(value>>16);
 digest[18]=(unsigned char)(value>>8);
 digest[19]=(unsigned char)(value);
 }
 context->used=0;
 MIi_CpuClear32(0,&context,4);
}
