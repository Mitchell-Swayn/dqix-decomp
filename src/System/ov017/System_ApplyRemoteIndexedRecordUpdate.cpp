#include <globaldefs.h>
ARM
struct GameState;
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
extern "C" char* OV017_ReadWordField6B0(void*);
struct BitsA {unsigned char b0:1,b1:1,b2:1,b3:1,high:4;};
struct BitsB {unsigned char b0:1,b1:1,b2:1,b3:1,b4:1,b5:1,b6:1,b7:1;};
struct Record {char pad[12];unsigned short command;char gap[0x22];unsigned short value30;short value32,value34;char gap36[2];unsigned char value38,reset39,pad3a;BitsA flagsA;BitsB flagsB;unsigned char value3d;char tail[0x66];};
// Original: arm9/ov017 @ 0x021CAC7C; symbol: func_ov017_021cac7c; size: 0x22C.
extern "C" void System_ApplyRemoteIndexedRecordUpdate(void*,const char* packet,GameState* state,char* resources) {
 char* root=OV017_ReadWordField6B0(*(void**)(resources+0x3718));
 char* owner;
 if(!root || !(owner=*(char**)(root+0x8e18)))return;
 if(*(signed char*)(owner+0x2a)==GameState_ReadProtagonistObjectIndex(state))return;
 if(*(unsigned short*)(owner+8)!=*(unsigned short*)(packet+4))return;
 int index=*(unsigned short*)(packet+6)-192;
 if(index<0||index>=8)return;
 Record* out=(Record*)(owner+0x158)+index;
 out->value32=*(short*)(packet+8);
 out->value34=*(short*)(packet+10);
 out->value30=*(unsigned short*)(packet+14);
 out->value38=*(unsigned char*)(packet+16);
 out->flagsA.b0=((BitsA*)(packet+17))->b0;
 out->flagsA.b1=((BitsA*)(packet+17))->b1;
 out->flagsA.b2=((BitsA*)(packet+17))->b2;
 out->flagsA.b3=((BitsA*)(packet+17))->b3;
 out->flagsA.high=((BitsA*)(packet+17))->high;
 out->reset39=0;
 out->flagsB.b0=((BitsB*)(packet+19))->b0;
 out->flagsB.b1=((BitsB*)(packet+19))->b1;
 out->flagsB.b2=((BitsB*)(packet+19))->b2;
 out->flagsB.b3=((BitsB*)(packet+19))->b3;
 out->flagsB.b4=((BitsB*)(packet+19))->b4;
 out->flagsB.b5=((BitsB*)(packet+19))->b5;
 out->flagsB.b6=((BitsB*)(packet+19))->b6;
 out->value3d=*(unsigned char*)(packet+18);
 out->command=*(unsigned short*)(packet+12);
}
