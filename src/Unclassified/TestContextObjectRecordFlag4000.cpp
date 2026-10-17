#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" int Object_GetGlobalConnectionState(void);
extern "C" void GameResources_GetInstance(void);
extern "C" int IsFirstWordNonzero(int);
extern "C" int GetRecordAtResolvedIndexWithStride116(int, int);
// Original: arm9/main @ 0x02034340; symbol: func_02034340; size: 0x60.
extern "C" int TestContextObjectRecordFlag4000(const char *object) {
    int handle = Object_GetGlobalConnectionState();
    GameResources_GetInstance();
    int result = 0;
    if (IsFirstWordNonzero(handle) != 0) {
        int id = *(const short *)(object + 4);
        if (GetRecordAtResolvedIndexWithStride116(handle, id) != 0) {
            id = *(const short *)(object + 4);
            int record = GetRecordAtResolvedIndexWithStride116(handle, id);
            unsigned int flag = *(const unsigned short *)(record + 2);
            if ((flag << 17) >> 31) {
                result = 1;
            }
        }
    }
    return result;
}
