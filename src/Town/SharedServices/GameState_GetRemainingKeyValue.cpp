#include <globaldefs.h>
ARM
struct State;
extern "C" int Inventory_GetItemQuantityAcrossTypeGroups(const State*,int,unsigned);
extern "C" int GameState_SumListedObjectDerivedValues(unsigned char*);
extern "C" int Inventory_GetItemCount(char*,int);
// Original: arm9/ov003 @ 0x021784BC; symbol: func_ov003_021784bc; size: 0x8C.
extern "C" int GameState_GetRemainingKeyValue(unsigned char* self,int key,unsigned type,int level) {
 int result=0;
 int valid;
 if(type>=8 && type<=9) valid=1; else valid=0;
 if(valid) {
  char* source=(char*)self;
  if(type==9) source+=0xe04;
  int value=Inventory_GetItemCount(source,key);
  int total=GameState_SumListedObjectDerivedValues(self);
  return level*8+99-(value+total);
 }
 if(type<=7) valid=1; else valid=0;
 if(valid) result=99-Inventory_GetItemQuantityAcrossTypeGroups((State*)(self+0x1d4),key,9);
 return result;
}
