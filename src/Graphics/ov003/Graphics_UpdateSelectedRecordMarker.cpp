#include <globaldefs.h>
ARM
#pragma optimization_level 4
#pragma opt_common_subs off
struct A;struct Entry;struct List;struct Lookup;
extern "C" int AreBothWordFieldsD4And9CNonzero(char*);
extern "C" void ApplyValueToAllHalfwordCountedEntries(char*,unsigned);
extern "C" void Object_ResetSelectedEntryCoordinatesAndFlags(void*,int);
extern "C" Entry* FindRecordPointerByKey(List*,unsigned);
extern "C" void Object_WriteSelectedEntryByte14(void*,int,unsigned char);
extern "C" void Object_UpdateAllCountedResourceEntries(unsigned char*);
extern "C" unsigned Object_GetSelectedRecordWhenBuffersEnabled(char*);
extern "C" void WriteResolvedLookupEntryXY(Lookup*,unsigned,unsigned,unsigned);
extern "C" unsigned ReadBit(A**);
// Original: arm9/ov003 @ 0x0215C32C; symbol: func_ov003_0215c32c; size: 0x138.
extern "C" void Graphics_UpdateSelectedRecordMarker(unsigned char* self) {
 if(self[0x59f]&1) {
  if(*(A***)(self+0x570) && ReadBit(*(A***)(self+0x570))) {
   Object_UpdateAllCountedResourceEntries(self+0x98);
   return;
  }
  char* record=(char*)Object_GetSelectedRecordWhenBuffersEnabled((char*)self+0xf4);
  if(!record)return;
  if(!AreBothWordFieldsD4And9CNonzero(record))return;
  if(((unsigned char*)record)[0xc5]&0x20)return;
  short x=*(short*)(record+0xac)*8;
  short y=*(short*)(record+0xae)*8;
  x+=*(short*)(record+0xbc);
  y+=*(short*)(record+0xbe);
  char* list=*(char**)(self+0xd4);
  if(list) {
   Object_ResetSelectedEntryCoordinatesAndFlags(list,0);
   unsigned char* entry=(unsigned char*)FindRecordPointerByKey((List*)list,0);
   if(entry)entry[0x15]|=8;
   ApplyValueToAllHalfwordCountedEntries(list,*(unsigned*)(self+0x574));
   WriteResolvedLookupEntryXY((Lookup*)list,0,(short)(x-8),(short)(y-2));
   Object_WriteSelectedEntryByte14(list,0,0);
  }
  Object_UpdateAllCountedResourceEntries(self+0x98);
 } else {
  if(!*(List**)(self+0xd4))return;
  unsigned char* entry=(unsigned char*)FindRecordPointerByKey(*(List**)(self+0xd4),0);
  if(entry)entry[0x15]&=~8;
 }
}
