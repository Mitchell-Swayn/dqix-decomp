#include <globaldefs.h>
ARM
#pragma optimization_level 3
extern "C" void *Object_GetGlobalConnectionState(void);
extern "C" void GameResources_GetInstance(void);
extern "C" int IsFirstWordNonzero(void *);
extern "C" int TestInactiveOrPrimaryIndexState(void *);
extern "C" unsigned short *GetRecordAtResolvedIndexWithStride116(void *, int);
extern "C" int ReadIndexedSignedField1038(void *);
// Original: arm9/main @ 0x020342AC; symbol: func_020342ac; size: 0x94.
extern "C" unsigned int Object_ReadRemoteMemberStateOrLocalByteBE(void *object) {
    void *state = Object_GetGlobalConnectionState();
    GameResources_GetInstance();
    if (IsFirstWordNonzero(state) != 0 && TestInactiveOrPrimaryIndexState(state) != 0 &&
        GetRecordAtResolvedIndexWithStride116(state, *(short *)((char *)object + 4)) != 0) {
        short key = *(short *)((char *)object + 4);
        int mode = ReadIndexedSignedField1038(state);
        if (mode != key) {
            unsigned int flag = *(volatile unsigned char *)((char *)object + 0xc1);
            unsigned int shifted = flag << 30;
            shifted = shifted >> 30;
            if ((shifted & 2) != 0) {
            unsigned short *record = GetRecordAtResolvedIndexWithStride116(state, *(short *)((char *)object + 4));
                return ((unsigned int)*record << 16) >> 24;
            }
        }
    }
    return *(unsigned char *)((char *)object + 0xbe);
}
