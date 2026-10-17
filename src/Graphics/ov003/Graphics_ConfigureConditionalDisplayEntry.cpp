#include <globaldefs.h>
ARM
struct List;struct Entry;struct Lookup;
extern "C" void ApplyValueToAllHalfwordCountedEntries(char*,unsigned int);
extern "C" void Object_ResetSelectedEntryCoordinatesAndFlags(void*,int);
extern "C" Entry* FindRecordPointerByKey(List*,unsigned int);
extern "C" void Object_WriteSelectedEntryByte14(void*,int,unsigned char);
extern "C" void Object_UpdateAllCountedResourceEntries(unsigned char*);
extern "C" void WriteResolvedLookupEntryXY(Lookup*,unsigned int,unsigned int,unsigned int);
// Original: arm9/ov003 @ 0x0215C464; symbol: func_ov003_0215c464; size: 0xAC.
extern "C" void Graphics_ConfigureConditionalDisplayEntry(unsigned char* object) {
if(object[0x59f]&2){
void* list=*(void**)(object+0xd4);
if(list){
Object_ResetSelectedEntryCoordinatesAndFlags(list,1);
unsigned char* entry=(unsigned char*)FindRecordPointerByKey((List*)list,1);
if(entry)entry[0x15]|=8;
ApplyValueToAllHalfwordCountedEntries((char*)list,*(unsigned int*)(object+0x574));
WriteResolvedLookupEntryXY((Lookup*)list,1,215,150);
Object_WriteSelectedEntryByte14(list,1,6);
}
Object_UpdateAllCountedResourceEntries(object+0x98);
}else{
void* list=*(void**)(object+0xd4);
if(list){unsigned char* entry=(unsigned char*)FindRecordPointerByKey((List*)list,1);if(entry)entry[0x15]&=~8;}
}
}
