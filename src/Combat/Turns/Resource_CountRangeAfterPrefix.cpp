#include <globaldefs.h>
ARM
extern "C" unsigned Combat_CollectEligiblePartyIds(void*,unsigned short*,unsigned,unsigned);
extern "C" unsigned Combat_CollectGroupIndicesByDescriptorFlags(void*,unsigned short*,unsigned,unsigned);
// Original: arm9/ov000 @ 0x02153E40; symbol: Resource_CountRangeAfterPrefix; size: 0x38.
// Uses the first helper to count a prefix, passes the remaining halfword range to the second helper, and returns both counts added together.
extern "C" unsigned Resource_CountRangeAfterPrefix(void* self,unsigned short* values,unsigned count,unsigned flags) {
    unsigned prefix=(unsigned)((unsigned char*)0 + Combat_CollectEligiblePartyIds(self,values,count,flags));
    return prefix+Combat_CollectGroupIndicesByDescriptorFlags(self,values+prefix,count-prefix,flags);
}
