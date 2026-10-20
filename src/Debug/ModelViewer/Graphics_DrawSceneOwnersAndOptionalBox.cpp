#include <globaldefs.h>
ARM
struct Vec {int x,y,z;};struct GameState;
extern "C" {
void* _ZN9GameState11GetInstanceEv();void* GameState_ReadUnknownB0(GameState*);
void Graphics_DrawColoredRotatedBox(Vec,unsigned,int,int,int,short);
void CharacterViewer_DrawModelByKind(void*);
}
// Original: arm9/ov015 @ 0x02190348; symbol: func_ov015_02190348; size: 0xE0.
// Sets optional geometry state, draws a camera-position box and dispatches each linked owner payload.
extern "C" void Graphics_DrawSceneOwnersAndOptionalBox(unsigned char* self) {
 if(self[0x19d]) {
 
 (*(volatile unsigned*)0x40004a4)=0x001f00c0;(*(volatile unsigned*)0x4000444)=0;(*(volatile unsigned*)0x4000500)=1;(*(volatile unsigned*)0x4000480)=0x5294;
 volatile unsigned* commands=(volatile unsigned*)0x0400048c;
 *commands=0x3000;*commands=0x3000;*commands=0x3000;
 *commands=0xd000;*commands=0xd000;*commands=0xd000;*commands=0xd000;*commands=0x3000;
 (*(volatile unsigned*)0x4000504)=0;(*(volatile unsigned*)0x4000448)=1;
 }
 if(self[0x19c]) {
 unsigned char* camera=(unsigned char*)GameState_ReadUnknownB0((GameState*)_ZN9GameState11GetInstanceEv());
 Graphics_DrawColoredRotatedBox(*(Vec*)(camera+0x10),0x3dff,0x800,0x800,0x800,0);
 }
 unsigned char* node=*(unsigned char**)(self+0x2c);
 while(node){CharacterViewer_DrawModelByKind(*(void**)node);node=*(unsigned char**)(node+4);}
}
