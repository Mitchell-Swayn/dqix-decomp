#include <globaldefs.h>
// Original: arm9/ov000 @ 0x0217199c; symbol: func_ov000_0217199c; size: 0x24.
extern "C" void* GetIndexedFieldA4(void* records, int index) { if (index < 0 || index >= 0x93) return 0; return *(void**)((char*)records + index * 4 + 0x1a4); }
