#include <globaldefs.h>
ARM
struct PackedRecord { unsigned occupied; unsigned char remaining[60]; };
struct PackedRecordList { PackedRecord records[12]; unsigned char count; inline unsigned ReadOccupied(int i) const { return records[i].occupied; } };
extern "C" void Combat_CopyTimedPresentationRecord(unsigned char*,const unsigned char*);
// Original: arm9/ov025 @ 0x021ED0B8; symbol: func_ov025_021ed0b8; size: 0x44.
// Copies into the first record with a zero first word and increments the byte count.
extern "C" void Combat_AppendTimedPresentationRecord(PackedRecordList* list,const unsigned char* source)
{
 for(int i=0;i<12;i++){
  if(!list->ReadOccupied(i)){
   Combat_CopyTimedPresentationRecord((unsigned char*)&list->records[i],source);
   list->count++;
   return;
  }
 }
}
