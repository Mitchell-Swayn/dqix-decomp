#include <globaldefs.h>
// func_02053dc0: 0x02053dc0–0x02053dd0, arm; 16 bytes
// Original: arm9/main @ 0x02053DC0; symbol: func_02053dc0; size: 0x10.
extern "C" int ReadField19C(int self) {
    int value = *(int*)(self + 0x19c);
        if (value == 0) {
            value = 0;
        }
        return value;
}
