#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" char* ResourceManager_GetIndexedHeaderTable24Entry(int);
extern "C" void SoundStream_SelectFileOrMemoryBackend(void*,unsigned);
typedef int (*Resolve)(int,void*,void*,unsigned);
typedef void (*Close)(void*);
typedef int (*Open)(void*,unsigned);
// Original: arm9/main @ 0x020BF658; symbol: func_020bf658; size: 0x144.
extern "C" void Resource_AdvanceResolvedFileAndRescalePosition(unsigned char* self) {
 unsigned input[2];unsigned output[2];
 input[0]=*(unsigned*)(self+0x148);
 input[1]=*(unsigned*)(self+0x144);
 output[0]=*(unsigned*)(self+0x144);output[1]=0;
 if(!(*(Resolve*)(self+0x13c))(0,input,output,*(unsigned*)(self+0x140)))return;
 char* entry=ResourceManager_GetIndexedHeaderTable24Entry(output[0]);
 if(!entry)return;
 unsigned char oldMode=self[0xc0];
 unsigned short oldRate=*(unsigned short*)(self+0xc4);
 (*(Close*)(self+0x168))(self);
 SoundStream_SelectFileOrMemoryBackend(self,*(unsigned*)entry);
 if(!(*(Open*)(self+0x164))(self,*(unsigned*)entry))return;
 if(oldRate!=*(unsigned short*)(self+0xc4))return;
 if(!oldMode && self[0xc0])return;
 if(oldMode && !self[0xc0])return;
 *(unsigned*)(self+0x144)=output[0];
 *(unsigned*)(self+0x160)=((unsigned long long)*(unsigned short*)(self+0xc4)*output[1])/1000;
 if(*(unsigned*)(self+0x160) && self[0xc0]==2) *(unsigned*)(self+0x110)|=0x10;
 else *(unsigned*)(self+0x110)&=~0x10;
 *(unsigned*)(self+0x110)&=~0x20;
}
