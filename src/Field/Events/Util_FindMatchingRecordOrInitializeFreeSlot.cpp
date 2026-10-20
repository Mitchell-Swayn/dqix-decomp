#include <globaldefs.h>
ARM
struct Record { unsigned short field0; unsigned char active,busy; unsigned unknown; short id; unsigned char tail[0x3e]; };
struct Owner { unsigned char pad[0x373c]; Record entries[12]; };
extern "C" void Resource_InitializeTypeNineteenRecord(Record*);
// Original: arm9/ov017 @ 0x021A4658; symbol: func_ov017_021a4658; size: 0xA8.
extern "C" Record* Util_FindMatchingRecordOrInitializeFreeSlot(Owner* owner,int id) {
 for(int i=0;i<12;++i) if(owner->entries[i].active && !owner->entries[i].busy && owner->entries[i].id==id) return &owner->entries[i];
 for(int i=0;i<12;++i) if(!owner->entries[i].active) {
  Resource_InitializeTypeNineteenRecord(&owner->entries[i]);
  return &owner->entries[i];
 }
 while(1) {}
}
