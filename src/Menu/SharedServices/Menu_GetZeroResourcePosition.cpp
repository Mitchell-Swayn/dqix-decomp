#include <globaldefs.h>
ARM
struct ThreeWordRecord {unsigned words[3];};
extern "C" void* __clear(void*,unsigned);
// Original: arm9/ov004 @ 0x0215377C; symbol: func_ov004_0215377c; size: 0x2C.
// Clears a twelve-byte temporary and copies its three words into the destination record.
extern "C" void Menu_GetZeroResourcePosition(ThreeWordRecord* self) {
 ThreeWordRecord cleared={0};
 *self=cleared;
}
