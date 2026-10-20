#include <globaldefs.h>
ARM
struct Record { unsigned first; unsigned code:12,rest:20; unsigned low:29,requiresCode1F9:1,high:2; };
// Original: arm9/ov024 @ 0x021EA7FC; symbol: func_ov024_021ea7fc; size: 0x60.
// Rejects zero counts, codes 0x70/0x48, and flagged records whose code is not 0x1f9.
extern "C" bool Combat_ShouldRandomizeCriticalDamage(void*,const Record* record,int count) {
 if(!count)return false;
 if(record->requiresCode1F9 && record->code!=0x1f9)return false;
 if(record->code==0x70)return false;
 if(record->code==0x48)return false;
 return true;
}
