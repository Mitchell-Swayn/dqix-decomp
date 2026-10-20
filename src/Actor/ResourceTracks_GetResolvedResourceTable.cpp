#include <globaldefs.h>
// func_02055080: 0x02055080–0x02055090, arm; 16 bytes
// Original: arm9/main @ 0x02055080; symbol: func_02055080; size: 0x10.
extern "C" int ResourceTracks_GetResolvedResourceTable(int self) {
    int value = *(int*)(self + 4);
        if (value == 0) {
            value = 0;
        }
        return value;
}
