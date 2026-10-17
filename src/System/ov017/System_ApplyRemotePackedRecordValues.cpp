#include <globaldefs.h>
ARM
struct GameState;
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
extern "C" char* OV017_ReadWordField6B0(void*);
struct First {unsigned a0:3,a1:3,a2:3,a3:3,a4:3,a5:3,a6:3,a7:3,a8:3,a9:3,pad:2;};
struct Second {unsigned a0:3,a1:3,a2:3,a3:3,a4:4,pad:16;};
struct Record {char data[0xa4];};
// Original: arm9/ov017 @ 0x021CB974; symbol: func_ov017_021cb974; size: 0x25C.
extern "C" void System_ApplyRemotePackedRecordValues(void*,const char* packet,GameState* state,char* resources) {
 char* root=OV017_ReadWordField6B0(*(void**)(resources+0x3718));
 char* owner;
 if(!root || !(owner=*(char**)(root+0x8e18)))return;
 if(*(signed char*)(owner+0x2a)==GameState_ReadProtagonistObjectIndex(state))return;
 if(*(unsigned short*)(owner+8)!=*(unsigned short*)(packet+4))return;
 int index=*(unsigned short*)(packet+6)-192;
 if(index<0||index>=8)return;
 Record* out=(Record*)(owner+0x158)+index;
 if(*(unsigned char*)(packet+16)==1) {
  out->data[112]=((First*)(packet+8))->a0;
  out->data[113]=((First*)(packet+8))->a1;
  out->data[114]=((First*)(packet+8))->a2;
  out->data[115]=((First*)(packet+8))->a3;
  out->data[116]=((First*)(packet+8))->a4;
  out->data[117]=((First*)(packet+8))->a5;
  out->data[118]=((First*)(packet+8))->a6;
  out->data[119]=((First*)(packet+8))->a7;
  out->data[120]=((First*)(packet+8))->a8;
  out->data[121]=((First*)(packet+8))->a9;
  out->data[122]=((Second*)(packet+12))->a0;
  out->data[123]=((Second*)(packet+12))->a1;
  out->data[124]=((Second*)(packet+12))->a2;
  out->data[125]=((Second*)(packet+12))->a3;
  out->data[126]=((Second*)(packet+12))->a4;
 }else {
  out->data[147]=((First*)(packet+8))->a0;
  out->data[148]=((First*)(packet+8))->a1;
  out->data[149]=((First*)(packet+8))->a2;
  out->data[150]=((First*)(packet+8))->a3;
  out->data[151]=((First*)(packet+8))->a4;
  out->data[152]=((First*)(packet+8))->a5;
  out->data[153]=((First*)(packet+8))->a6;
  out->data[154]=((First*)(packet+8))->a7;
  out->data[155]=((First*)(packet+8))->a8;
  out->data[156]=((First*)(packet+8))->a9;
  out->data[157]=((Second*)(packet+12))->a0;
  out->data[158]=((Second*)(packet+12))->a1;
  out->data[159]=((Second*)(packet+12))->a2;
  out->data[160]=((Second*)(packet+12))->a3;
  out->data[161]=((Second*)(packet+12))->a4;
 }
}
