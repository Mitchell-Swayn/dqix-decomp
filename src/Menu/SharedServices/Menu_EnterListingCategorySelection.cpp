#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void*, unsigned int);
// Original: arm9/ov004 @ 0x0215C0AC; symbol: func_ov004_0215c0ac; size: 0x14.
extern "C" int Menu_EnterListingCategorySelection(void* self) { Menu_QueueScriptEntry(self, 0x65); return 0; }
