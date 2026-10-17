#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" int GameState_CopyByteBufferAtOffset5718(void*,void*);
extern "C" void SetNestedSecondWordForTypeThree(void*,int);
// Original: arm9/ov023 @ 0x021EA46C; symbol: func_ov023_021ea46c; size: 0xB0.
extern "C" int Script_CountListedObjectsInSelectedStates(void* output) {
 void* state=_ZN9GameState11GetInstanceEv();
 unsigned char ids[4]={};
 int count=GameState_CopyByteBufferAtOffset5718(state,ids);
 int selected=0;
 for(int i=0;i<count;i++) {
  char* object=(char*)GameState_GetObjectWithFlag100(state,ids[i]);
  if(object) {
   switch(*(unsigned*)(*(char**)(object+0x150)+0x950)) {
   case 0: break;
   case 1: case 4: case 7: case 9: selected++; break;
   case 2: case 3: case 5: case 6: case 8: break;
   }
  }
 }
 SetNestedSecondWordForTypeThree(output,selected);
 return 1;
}
