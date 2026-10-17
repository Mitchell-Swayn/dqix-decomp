#include <globaldefs.h>

ARM
extern "C" {
struct State { unsigned char pad[28]; unsigned char first:4; unsigned char second:4; };
typedef int (*Callback)(void *,void *);
extern Callback data_020f01b8[4][4];
// Original: arm9/main @ 0x0204B5E8; symbol: func_0204b5e8; size: 0x38.
int Graphics_InvokeTwoIndexTransferCallback(State *p, void *a, void *b) { return data_020f01b8[p->first][p->second](a,b); }
}
