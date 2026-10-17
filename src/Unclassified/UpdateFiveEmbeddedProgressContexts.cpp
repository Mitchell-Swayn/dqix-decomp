#include <globaldefs.h>
extern "C" void func_0208b0f8(void);
extern "C" int ReadZoneCachedResultAndInvalidateOnZoneChange(int);
extern "C" void UpdateIndexedProgressAndStreakThresholds(void*, int);
// Original: arm9/main @ 0x0208B088; symbol: func_0208b088; size: 0x70.
extern "C" int UpdateFiveEmbeddedProgressContexts(void* object) {
    func_0208b0f8();
    *(unsigned int*)((char*)object+0x20)=(*(unsigned char*)((char*)object+0x9C)==0);
    int value=ReadZoneCachedResultAndInvalidateOnZoneChange((int)object);
    UpdateIndexedProgressAndStreakThresholds((char*)object+0x04,value);
    UpdateIndexedProgressAndStreakThresholds((char*)object+0x24,value);
    UpdateIndexedProgressAndStreakThresholds((char*)object+0x40,value);
    UpdateIndexedProgressAndStreakThresholds((char*)object+0x5C,value);
    UpdateIndexedProgressAndStreakThresholds((char*)object+0x78,value);
    return 1;
}
