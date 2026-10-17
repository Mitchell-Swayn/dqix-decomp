#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" char* GameState_FindIndexedObjectWithFlag400(void*,unsigned);
extern "C" void _ZN8Object3D11MakeVisibleEv(void*);
extern "C" void _ZN8Object3D10MakeHiddenEv(void*);
extern "C" int ReadIndirectComponentByte56OrZero(char*);
extern "C" unsigned ToggleMaskedFlagsAtOffset34(unsigned char*,unsigned);
extern "C" void Object_SetRemappedBitInHalfwordA26(unsigned char*,int);
extern "C" void ClearRemappedObjectSlotBit(char*,int);
extern "C" int ClassifyField81FE(unsigned char*);
extern "C" void* ResolveOverrideOrIndexedRecord(char*);
extern "C" int DispatchCombatSelectionProcedure(void*,void*,int,int*);
struct ComponentFlags { unsigned a:27, hidden:1, b:4; };
// Original: arm9/ov000 @ 0x021626A0; symbol: func_ov000_021626a0; size: 0x15C.
extern "C" void Combat_UpdateSelectedObjectVisibility(char* self,int selection,int visible) {
 void* game=_ZN9GameState11GetInstanceEv();
 char* obj;
 int show;
 unsigned char* record=*(unsigned char**)(self+0x29c);
 char* owner=*(char**)(self+0xea4);
 void* resolved=ResolveOverrideOrIndexedRecord(self);
 if(owner) {
 int ids[16];
 int count=DispatchCombatSelectionProcedure(*(void**)(self+0x29c),resolved,selection,ids);
 for(int i=0;i<count;i++) {
 obj=_ZN9GameState20GetGameObjectByIndexEi(game,ids[i]);
 if(obj) {
 show=visible;
 if(*(unsigned short*)obj&0x400) {
 char* flagged=GameState_FindIndexedObjectWithFlag400(game,ids[i]);
 if(flagged) {
 char* component=*(char**)(flagged+0x148);
 if(!ReadIndirectComponentByte56OrZero(flagged)) {
 if(((ComponentFlags*)(component+0x10))->hidden) show=0;
 }
 }
 }
 if(show) {
 _ZN8Object3D11MakeVisibleEv(obj);
 Object_SetRemappedBitInHalfwordA26((unsigned char*)owner,ids[i]);
 } else {
 _ZN8Object3D10MakeHiddenEv(obj);
 ClearRemappedObjectSlotBit(owner,ids[i]);
 }
 }
 }
 if(ClassifyField81FE(record)) {
 for(show=1;show<4;show++) {
 obj=_ZN9GameState20GetGameObjectByIndexEi(game,show);
 if(obj && ToggleMaskedFlagsAtOffset34(*(unsigned char**)(self+0x2a0),(unsigned char)show)) {
 _ZN8Object3D10MakeHiddenEv(obj);
 ClearRemappedObjectSlotBit(owner,show);
 }
 }
 }
 }
}
