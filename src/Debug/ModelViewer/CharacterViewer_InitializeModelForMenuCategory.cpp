#include <globaldefs.h>
ARM
extern "C" int Memory_CreateModeSelectedArenas(unsigned char*);
// Original: arm9/ov015 @ 0x0218EF7C; symbol: func_ov015_0218ef7c; size: 0xB0.
extern "C" int CharacterViewer_InitializeModelForMenuCategory(unsigned char* self,unsigned char* owner,unsigned char* descriptor) {
 *(unsigned char**)self=owner;
 switch(*(unsigned*)(owner+0x1a4)) {
 case 4:
  if(*(unsigned short*)(descriptor+8)==0) self[0x1c]=0;
  else self[0x1c]=1;
  break;
 case 11: self[0x1c]=2; break;
 case 12: self[0x1c]=2; break;
 case 6: self[0x1c]=3; break;
 case 7: self[0x1c]=4; break;
 case 13: self[0x1c]=5; break;
 case 14: self[0x1c]=6; break;
 }
 return Memory_CreateModeSelectedArenas(self);
}
