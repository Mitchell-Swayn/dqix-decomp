#include <globaldefs.h>
ARM
extern "C" unsigned char* RuntimeUnwind_ReadCompactUnsignedInteger(unsigned char*,unsigned*);
// Original: arm9/main @ 0x0200F1FC; symbol: func_0200f1fc; size: 0xA0.
extern "C" void RuntimeUnwind_DecodeFlagsAndSelectFramePointer(unsigned char* self,unsigned char** descriptor) {
 unsigned char* source=descriptor[1];
 unsigned bits=source[0];
 unsigned hasExtra=bits&0x40;
 self[0x6b]=hasExtra!=0;
 self[0x6a]=(bits&0x20)!=0;
 unsigned alternate=bits&0x80;
 self[0x6c]=alternate!=0;
 *(unsigned short*)(self+0x68)=source[1]<<4;
 *(unsigned short*)(self+0x68)|=0x4000;
 source=RuntimeUnwind_ReadCompactUnsignedInteger(source+2,(unsigned*)(self+0x60));
 if(hasExtra) source=RuntimeUnwind_ReadCompactUnsignedInteger(source,(unsigned*)(self+0x64));
 if(hasExtra) {
  if(alternate) *(unsigned*)(self+0x18)=*(unsigned*)(self+0x38);
  else *(unsigned*)(self+0x18)=*(unsigned*)(self+0x48);
 } else *(unsigned*)(self+0x18)=*(unsigned*)(self+0x14);
}
