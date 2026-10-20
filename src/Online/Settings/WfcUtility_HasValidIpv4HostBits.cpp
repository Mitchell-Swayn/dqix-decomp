#include <globaldefs.h>
ARM
extern "C" int WfcUtility_IsValidIpv4LeadingOctet(const void*);
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
// Original: arm9/ov031 @ 0x0221B1F4; symbol: HasBitsOutsideSecondMask; size: 0x64.
// Validates the first input, copies both four-byte values, and tests for bits set only in the first.
extern "C" int WfcUtility_HasValidIpv4HostBits(const void* first,const void* second) {
 if(!WfcUtility_IsValidIpv4LeadingOctet(first))return 0;
 unsigned a,b;
 MI_CpuCopy8(first,&a,4);
 MI_CpuCopy8(second,&b,4);
 return (a&~b)!=0;
}
