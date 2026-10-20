#include <globaldefs.h>
ARM
struct BytePrefix22 { unsigned char bytes[22]; };
// Original: arm9/ov000 @ 0x02161DFC; symbol: func_ov000_02161dfc; size: 0x34.
// Copies 22 bytes and two trailing byte fields to the record at offset 0x3E.
// The copied field meanings remain unknown.
extern "C" void MonsterStats_CopyDefinitionRecord(unsigned char* self,const unsigned char* source)
{
 *(BytePrefix22*)(self+0x3e)=*(const BytePrefix22*)source;
 self[0x54]=source[22];
 self[0x55]=source[23];
}
