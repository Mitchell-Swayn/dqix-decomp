#include <globaldefs.h>
ARM
extern "C" char* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_ReadPResources(void*);
extern "C" char* GameState_GetField3B0ObjectWithFlag4(void*);
extern "C" int Object_TestNewlySetHalfwordMask(unsigned short*,unsigned);
extern "C" void UpdateEmbeddedDisplayContextWhenEnabled(unsigned char*,int);
extern "C" int Selection_ReadEnabledIndexFromEmbeddedControl(unsigned char*);
extern "C" void UpdateContextPairForEmbeddedDisplay(unsigned char*);
extern "C" bool SaveContextReadFadePredicateAndRestoreContext(unsigned char*);
extern "C" int Object_ReadSelectionResultWhenGridReady(unsigned char*);
extern "C" int ReadWordFieldAtOffset23C(void*);
extern "C" int IsOverlayRecordFieldAt4354NonPositive(void*);
extern "C" unsigned short data_02114e30[];
class Screen {};
typedef void (Screen::*Handler)(int);
extern "C" Handler data_020f08b8[];
// Original: arm9/main @ 0x020676E0; symbol: func_020676e0; size: 0x1DC.
extern "C" void Graphics_UpdateReadySelectionAndDispatch(char* self,int elapsed) {
 if(*(int*)(self+0x9a0)!=6) return;
 if(!*(unsigned char*)(self+0x19ba)) return;
 UpdateEmbeddedDisplayContextWhenEnabled((unsigned char*)self+0x90,elapsed);
 if(!SaveContextReadFadePredicateAndRestoreContext((unsigned char*)self+0x90)) {
 UpdateContextPairForEmbeddedDisplay((unsigned char*)self+0x90);
 return;
 }
 int ready=1;
 int confirm=Object_TestNewlySetHalfwordMask(data_02114e30,0x401)!=0;
 int cancel=Object_TestNewlySetHalfwordMask(data_02114e30,2)!=0;
 char* game;
 char* resources;
 int mode=*(int*)(self+0x98c);
 game=_ZN9GameState11GetInstanceEv();
 char* object=GameState_GetField3B0ObjectWithFlag4(game);
 resources=GameState_ReadPResources(game);
 if(mode!=1 && *(unsigned char*)(self+0x19d2)) {
 if(object) {
 if((*(unsigned char*)(object+0x244)&2) || !ReadWordFieldAtOffset23C(object)) confirm=(confirm | Object_TestNewlySetHalfwordMask(data_02114e30,0x200))!=0;
 } else confirm=(confirm | Object_TestNewlySetHalfwordMask(data_02114e30,0x200))!=0;
 }
 int special=0;
 if(*(unsigned char*)(game+0x5cc8)==2) special=1;
 if(!special && resources) {
 if(!IsOverlayRecordFieldAt4354NonPositive(resources)) ready=cancel=confirm=0;
 }
 if(!special && *(char**)(self+0x8c)) {
 if(*(unsigned short*)(*(char**)(self+0x8c)+0xda)&0x20) ready=cancel=confirm=0;
 }
 int result=-1;
 if(ready) result=Object_ReadSelectionResultWhenGridReady((unsigned char*)self+0x90);
 if(confirm) result=Selection_ReadEnabledIndexFromEmbeddedControl((unsigned char*)self+0x90);
 else if(cancel) result=-2;
 *(int*)(self+0x954)=result;
 (((Screen*)self)->*data_020f08b8[mode])(result);
}
