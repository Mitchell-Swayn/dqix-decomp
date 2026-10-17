#include <globaldefs.h>
ARM
struct Entry { unsigned char pad[0xa4]; };
extern "C" { void* memcpy(void*,const void*,unsigned); int GameState_ReadProtagonistObjectIndex(void*); unsigned char* OV017_ReadWordField6B0(void*); }
// Original: arm9/ov017 @ 0x021CA918; symbol: func_ov017_021ca918; size: 0xA4.
extern "C" void GameState_ApplyRemoteIndexedRecordData(void* unused,unsigned char* packet,void* state,unsigned char* context) {
 unsigned char* owner=OV017_ReadWordField6B0(*(void**)(context+0x3718));
 unsigned char* object;
 if(!owner || !(object=*(unsigned char**)(owner+0x8e18))) return;
 if(*(signed char*)(object+0x2a)==GameState_ReadProtagonistObjectIndex(state)) return;
 if(*(unsigned short*)(object+8)!=*(unsigned short*)(packet+4)) return;
 int index=*(unsigned short*)(packet+6)-0xc0;
 if(index<0 || index>=8) return;
 unsigned char* entry=(unsigned char*)&((Entry*)(object+0x158))[index];
 memcpy(entry+0x58,packet+8,4);
 *(short*)(entry+0x28)=*(short*)(packet+12);
 *(short*)(entry+0x2a)=*(short*)(packet+14);
 *(short*)(entry+0x2c)=*(short*)(packet+16);
 *(short*)(entry+0x2e)=*(short*)(packet+18);
}
