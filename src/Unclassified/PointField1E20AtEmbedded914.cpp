#include <globaldefs.h>
// func_02042b1c: 0x02042b1c–0x02042b30, arm; 20 bytes
// Original: arm9/main @ 0x02042B1C; symbol: func_02042b1c; size: 0x14.
extern "C" void PointField1E20AtEmbedded914(int self) {
    *(int*)(self + 0x1e20) = self + 0x914;
}
