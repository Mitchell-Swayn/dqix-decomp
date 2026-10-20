#include <globaldefs.h>
ARM
#pragma optimization_level 4
// Original: arm9/ov031 @ 0x02207DD4; symbol: func_ov031_02207dd4; size: 0x50.
// Reads a short-form size or a high-bit-prefixed count of big-endian size bytes.
// Returns -1 on 32-bit overflow without advancing the caller's pointer.
extern "C" int Network_ReadVariableLengthBigEndianSize(const unsigned char** cursor)
{
 const unsigned char* input = *cursor;
 unsigned value = *input++;
 if (value & 0x80) {
  unsigned count = value & 0x7f;
  unsigned remaining = count - 1;
  value = 0;
  if (count) do {
   if (value & 0xff000000) return -1;
   value = (value << 8) + *input++;
  } while (remaining--);
 }
 *cursor = input;
 return value;
}
