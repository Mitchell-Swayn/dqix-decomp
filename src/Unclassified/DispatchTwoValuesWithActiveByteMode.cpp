#include <globaldefs.h>
extern "C" int Object_GetGlobalConnectionState(void);
extern "C" int IsFirstWordNonzero(void);
extern "C" unsigned int ReadIndexedSignedField1038(int);
extern "C" void ClearMatchingActiveContextEntry(int, int, unsigned char);

// Original: arm9/main @ 0x020E3428; symbol: func_020e3428; size: 0x40.
extern "C" void DispatchTwoValuesWithActiveByteMode(int first, int second) {
    int value = Object_GetGlobalConnectionState();
    if (IsFirstWordNonzero() == 0) {
        return;
    }
    int mode = ReadIndexedSignedField1038(value);
    ClearMatchingActiveContextEntry(first, second, (unsigned char)mode);
}
