#include <globaldefs.h>
struct Flags { unsigned char p[0x1c]; unsigned char b0:1,b1:1,b2:1,b3:1,b4:1,b5:1,b6:1,b7:1; };
#pragma force_active on
// Original: arm9/ov024 @ 0x021E8BF0; symbol: func_ov024_021e8bf0; size: 0x58.
// Describes observed operations; underlying field roles remain uncertain.
extern "C" void ClearHalfwordForRecordFlags(void*, Flags* record, unsigned short* out)
{
    if (record->b2 || record->b1 || record->b3 || record->b4 || record->b5 || record->b6) *out=0;
}
