#include <globaldefs.h>
ARM
struct GameState;
struct ItemList { char pad[12]; short items[1]; };
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" unsigned char* GameObject_GetLinkedIndexedState(void*);
// Original: arm9/ov002 @ 0x0215707C; symbol: GetInventoryItemByID; size: 0x8C.
extern "C" int GetInventoryItemByID(char* self,int index,int category) {
if(index<0) return -1;
if(category<0) return -1;
GameState* state=(GameState*)_ZN9GameState11GetInstanceEv();
if(category==5) {
char* list=(char*)GameState_GetIndexList(state);
list+=0x204;
list+=0xc00;
list+=index*2;
return *(short*)(list+12);
}
if(category==4) return *(short*)((char*)GameState_GetIndexList(state)+index*2+12);
void* obj=GameState_GetObjectWithFlag100(state,self[0x1c20]);
if(!obj) return -1;
return *(short*)(GameObject_GetLinkedIndexedState(obj)+index*2+0x454);
}
