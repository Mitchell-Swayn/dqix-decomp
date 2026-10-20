#include <globaldefs.h>
ARM
struct RelativeRecordTable { unsigned unknown[3]; int recordsOffset; int count; };
struct RecordTableOwner { unsigned char unknown[0x44]; RelativeRecordTable* table; };
struct KeyValueRecord { unsigned key; unsigned unknown; };
// Original: arm9/ov017 @ 0x021D4DF8; symbol: func_ov017_021d4df8; size: 0x40.
// Scans eight-byte records addressed relative to their header for a matching word key.
extern "C" int ContainsKeyInRelativeEightByteRecordTable(const RecordTableOwner* owner,unsigned key) {
 KeyValueRecord* record;
 int i;
 RelativeRecordTable* table=owner->table;
 record=(KeyValueRecord*)((char*)table+table->recordsOffset);
 for(i=0;i<table->count;i++,record++)if(record->key==key)return 1;
 return 0;
}
