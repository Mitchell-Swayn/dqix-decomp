#include <globaldefs.h>
ARM
extern "C" void* NavigationMessage_GetGlobalInstance(void);
extern "C" int NavigationMessage_EnqueueWithFormattedMemberName(unsigned char*, short, int, signed char);
// Original: arm9/ov017 @ 0x021D1854; symbol: func_ov017_021d1854; size: 0x20.
extern "C" int NavigationMessage_ApplyMemberNotificationPacket(void* unused, unsigned char* record) { void* manager = NavigationMessage_GetGlobalInstance(); return NavigationMessage_EnqueueWithFormattedMemberName((unsigned char*)manager, *(short*)(record + 4), *(short*)(record + 6), *(signed char*)(record + 8)); }
