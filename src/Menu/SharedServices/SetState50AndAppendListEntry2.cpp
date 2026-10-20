#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void*, unsigned int);
extern "C" void* GameState_AppendValueAndSetNodeFlags(void*, unsigned short, unsigned int);
// Original: arm9/ov004 @ 0x0215C064; symbol: SetState50AndAppendListEntry2; size: 0x28.
// Sets state value 0x50 and appends list value 2 with flag 8.
extern "C" int SetState50AndAppendListEntry2(void* self) { Menu_QueueScriptEntry(self, 0x50); GameState_AppendValueAndSetNodeFlags(self, 2, 8); return 0; }
