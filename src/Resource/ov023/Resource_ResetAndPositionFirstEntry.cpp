#include <globaldefs.h>
ARM
extern "C" {
void* _ZN9GameState11GetInstanceEv();
unsigned _ZNK9GameState12GetTickCountEv(void*);
void ApplyValueToAllHalfwordCountedEntries(char*,unsigned);
void Object_ResetSelectedEntryCoordinatesAndFlags(void*,int);
unsigned char* FindRecordPointerByKey(void*,unsigned);
void Object_WriteSelectedEntryByte14(void*,int,unsigned char);
void Object_UpdateAllCountedResourceEntries(unsigned char*);
}
// Original: arm9/ov023 @ 0x021E3304; symbol: func_ov023_021e3304; size: 0x88.
extern "C" void Resource_ResetAndPositionFirstEntry(unsigned char* object,short x,short y) {
 void* state=_ZN9GameState11GetInstanceEv();
 Object_WriteSelectedEntryByte14(*(void**)(object+0xd0),0,0);
 Object_ResetSelectedEntryCoordinatesAndFlags(*(void**)(object+0xd0),0);
 unsigned char* entry=FindRecordPointerByKey(*(void**)(object+0xd0),0);
 if(entry) entry[0x15]|=8;
 ApplyValueToAllHalfwordCountedEntries(*(char**)(object+0xd0),_ZNK9GameState12GetTickCountEv(state));
 entry=FindRecordPointerByKey(*(void**)(object+0xd0),0);
 if(entry) { *(short*)(entry+4)=x; *(short*)(entry+6)=y; }
 Object_UpdateAllCountedResourceEntries(*(unsigned char**)(object+0xc8));
}
