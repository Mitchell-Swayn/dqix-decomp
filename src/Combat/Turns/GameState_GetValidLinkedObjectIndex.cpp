#include <globaldefs.h>
ARM
extern "C" { void* _ZN9GameState11GetInstanceEv(); unsigned char* _ZN9GameState20GetGameObjectByIndexEi(void*,int); unsigned char* Combat_GetCommandActorSnapshot(void*,int); }
// Original: arm9/ov000 @ 0x021819C8; symbol: func_ov000_021819c8; size: 0x94.
extern "C" int GameState_GetValidLinkedObjectIndex(void* owner,int slot,int* output,int kind) {
 void* state=_ZN9GameState11GetInstanceEv();
 unsigned char* record=Combat_GetCommandActorSnapshot(owner,slot);
 if(record) {
  int index=0;
  if(kind==0) index=*(unsigned short*)(record+0x20)*12+0x1c;
  else if(kind==1) index=*(unsigned short*)(record+0x20)*12+0x1d;
  unsigned char* object=_ZN9GameState20GetGameObjectByIndexEi(state,index);
  if(object && *(short*)(object+2)>-1) { *output=index; return 1; }
 }
 return 0;
}
