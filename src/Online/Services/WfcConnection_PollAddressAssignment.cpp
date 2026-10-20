#include <globaldefs.h>
ARM
extern "C" unsigned Util_ByteSwapSharedValue();
extern "C" void WfcConnection_ApplyProfileDnsForDhcp(void*);
extern "C" unsigned long long _Z19GetCurrentTimestampv();
// Original: arm9/ov031 @ 0x022153BC; symbol: Network_PollRequestAndMarkTimedOutSlot; size: 0x90.
struct Flags {unsigned char low:4;unsigned char status:2;unsigned char rest:2;};
extern "C" int WfcConnection_PollAddressAssignment(char* self) {
 if(Util_ByteSwapSharedValue()){WfcConnection_ApplyProfileDnsForDhcp(self);return ((Flags*)(self+0xd0c))->status==1?15:13;}
 unsigned long long elapsed=_Z19GetCurrentTimestampv()-*(unsigned long long*)(self+0xcb0);
 if((elapsed<<6)/0x01ff6210ULL<10)return 12;
 *(unsigned char*)(self+(*(unsigned char*)(self+0xd13)<<2)+0x444)=1;return 11;
}
