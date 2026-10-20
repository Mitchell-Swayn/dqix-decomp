#include <globaldefs.h>
// Returns null or the pointer stored at offset 0x24 advanced by 0x50.
// Original: arm9/ov017 @ 0x021b1fc0; symbol: func_ov017_021b1fc0; size: 0x14.
extern "C" void* OnlineDownload_GetArchiveEntryTable(unsigned char* p) { void* q = *(void**)(p + 0x24); return q ? (unsigned char*)q + 0x50 : 0; }
