#include <globaldefs.h>
ARM
struct GameState;struct List;struct Entry {char pad[4];short x,y;char pad2[13];unsigned char flags;};
extern "C" {void* _ZN9GameState11GetInstanceEv();unsigned _ZNK9GameState12GetTickCountEv(GameState*);void ApplyValueToAllHalfwordCountedEntries(char*,unsigned);void Object_ResetSelectedEntryCoordinatesAndFlags(void*,int);Entry* FindRecordPointerByKey(List*,unsigned);void Object_WriteSelectedEntryByte14(void*,int,unsigned char);void Object_UpdateAllCountedResourceEntries(unsigned char*);}
// Original: arm9/ov023 @ 0x021ECF78; symbol: func_ov023_021ecf78; size: 0x9C.
extern "C" void ResetFlaggedSelectedResourceEntry(unsigned char* p){
if(!(*(unsigned short*)(p+0x438)&0x80))return;
GameState* game=(GameState*)_ZN9GameState11GetInstanceEv();
Object_WriteSelectedEntryByte14(*(void**)(p+0x42c),0,0x40);
Object_ResetSelectedEntryCoordinatesAndFlags(*(void**)(p+0x42c),0);
Entry* entry=FindRecordPointerByKey(*(List**)(p+0x42c),0);
if(entry)entry->flags|=8;
unsigned ticks=_ZNK9GameState12GetTickCountEv(game);
ApplyValueToAllHalfwordCountedEntries(*(char**)(p+0x42c),ticks);
short x=*(short*)(p+0x448);
entry=FindRecordPointerByKey(*(List**)(p+0x42c),0);
if(entry){entry->x=x;entry->y=0x24;}
Object_UpdateAllCountedResourceEntries(*(unsigned char**)(p+0x424));
}
