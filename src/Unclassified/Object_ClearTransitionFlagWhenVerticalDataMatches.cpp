#include <globaldefs.h>
ARM
extern "C" void* Object_GetGlobalThirtyTwoEntryContainer(void);
extern "C" unsigned int* GetBoundedSlotUnlessFlag8000(unsigned int**, unsigned int);
extern "C" void* Object_ReadDataFromFirstAvailableRenderTarget(unsigned char*);
extern "C" int ReadFirstAvailableVerticalCoordinate(void*);
extern "C" void WriteFirstAvailableVerticalCoordinate(void*, unsigned int);
// Original: arm9/main @ 0x020656E4; symbol: func_020656e4; size: 0x74.
extern "C" int Object_ClearTransitionFlagWhenVerticalDataMatches(unsigned char* object) {
    if (object[0x1000 + 0x9b6] == 0) return 0;
    unsigned int** container = (unsigned int**)Object_GetGlobalThirtyTwoEntryContainer();
    unsigned int* slot = GetBoundedSlotUnlessFlag8000(container, *(unsigned int*)(object + 0x1000 + 0x838));
    if (slot == 0) return 0;
    unsigned char result = 1;
    WriteFirstAvailableVerticalCoordinate(slot, *(unsigned int*)(object + 0x1000 + 0x844));
    void* data = Object_ReadDataFromFirstAvailableRenderTarget((unsigned char*)slot);
    int coordinate = ReadFirstAvailableVerticalCoordinate(slot);
    if (data == (void*)coordinate) {
        object[0x1000 + 0x9b6] = 0;
        result = 0;
    }
    return result;
}
