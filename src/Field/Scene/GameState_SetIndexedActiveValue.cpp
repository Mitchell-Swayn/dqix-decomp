#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x02191BA0; symbol: GameState_SetIndexedActiveValue; size: 0x3C.
// For indices 0 through 3, stores the halfword value in the indexed state slot and marks its active byte.
extern "C" void GameState_SetIndexedActiveValue(void *base, int index, unsigned short value) {
 int valid;
 if (index < 0) goto invalid;
 if (index <= 3) {
  valid = 1;
  goto checked;
 }
invalid:
 valid = 0;
checked:
 if (valid) {
  unsigned char *slot = (unsigned char *)base + index * 4;
  *(unsigned short *)(slot + 0x449e) = value;
  *((unsigned char *)base + index * 4 + 0x449c) = 1;
 }
}
