#include <globaldefs.h>
ARM
struct State;
extern "C" int Object_FindValueInSelectedOrAllKeyGroups(const State* s,int key,unsigned type);
extern "C" int GameState_SumListedObjectDerivedValues(unsigned char* p);
extern "C" int ReadSignedByteValueForNonnegativeHalfwordKey(char* p,int key);
// Original: arm9/ov004 @ 0x0215799C; symbol: func_ov004_0215799c; size: 0x8C.
extern "C" int GameState_ComputeKeyedValueDeficit(unsigned char *self, int key, unsigned type, int scale) {
    int result = 0;
    int special;
    if (type >= 8 && type <= 9) special = 1;
    else special = 0;
    if (special) {
        char *values = (char*)self;
        if (type == 9) values = (char*)self + 0xe04;
        int value = ReadSignedByteValueForNonnegativeHalfwordKey(values, key);
        int sum = GameState_SumListedObjectDerivedValues(self);
        return (scale * 8 + 99) - (value + sum);
    }
    int grouped;
    if (type <= 7) grouped = 1;
    else grouped = 0;
    if (grouped) result = 99 - Object_FindValueInSelectedOrAllKeyGroups((State*)(self + 0x1d4), key, 9);
    return result;
}
