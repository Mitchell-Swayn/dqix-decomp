#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void __clear(void*,unsigned);
extern "C" int GameState_CopyProtagonistPartySlotList(void*,void*);
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" void Script_WriteIntegerReferenceOutput(void*,int);
// Original: arm9/ov023 @ 0x021EA3EC; symbol: func_ov023_021ea3ec; size: 0x80.
extern "C" int GameState_WriteCountOfSecondaryObjectsWithZeroField4(void* output) {
 void* game=_ZN9GameState11GetInstanceEv();
 unsigned char indices[4]={0};
 int size=GameState_CopyProtagonistPartySlotList(game,indices);
 int count=0;
 for(int i=1;i<size;++i) {
  char* object=(char*)GameState_GetObjectWithFlag100(game,indices[i]);
  if(object) { int value=*(unsigned short*)(*(char**)(object+0x130)+4); if(value<=0) ++count; }
 }
 Script_WriteIntegerReferenceOutput(output,count);
 return 1;
}
