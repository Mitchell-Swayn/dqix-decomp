#include <globaldefs.h>
ARM
extern "C" void* memset(void*, int, unsigned int);
// Original: arm9/ov000 @ 0x0215FE64; symbol: InitializeZeroedRecordWithInvalidHalfword; size: 0x20.
// Clears a 0x30-byte record, marks its halfword field as unavailable, and returns -1.
extern "C" int InitializeZeroedRecordWithInvalidHalfword(void* record) { memset(record,0,48); *(short*)((char*)record+28)=-1; return -1; }
