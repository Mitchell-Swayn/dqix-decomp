#include <globaldefs.h>
ARM
extern "C" void __clear(void*,unsigned);
extern "C" int _Z13NextRandomMaxP6Randomi(void*,int);
struct Record { char pad[10]; unsigned char low : 4; unsigned char active : 4; char tail[13]; };
struct Count { unsigned char low : 4; unsigned char count : 2; unsigned char high : 2; };
// Original: arm9/ov000 @ 0x02153C24; symbol: func_ov000_02153c24; size: 0x9C.
extern "C" void Util_ReplaceInactiveIndexWithRandomActiveRecord(char *self, int *index) {
    Record *records = (Record*)(self + 0x81b4);
    if (records[*index].active) return;
    int indices[3] = {};
    int count = 0;
    int *candidates = indices;
    for (int i = 0; i < ((Count*)(self + 0x81b1))->count; i++) {
        if (records[i].active) candidates[count++] = i;
    }
    *index = candidates[_Z13NextRandomMaxP6Randomi(self, count)];
}
