#include <globaldefs.h>
ARM
extern "C" int Object_TestNewlySetHalfwordMask(unsigned short* p,unsigned int mask);
extern "C" void DispatchStoredHalfwordIndexWithTwoArguments(char* p,int a,void* b);
extern "C" void ResolveAndResetPresentEntry(unsigned char *p,int value);
extern "C" void ResetPointedHalfwordAndSynchronizeSignedByteState(unsigned char* p);
extern "C" void SetLinkedFlagStateAndResetOwner(void **p);
extern "C" int UpdateSelectionFromNewInputOrCoordinates(void*);
extern "C" int TestInputOrAssociatedObjectGate(void*);
extern "C" unsigned short data_02114e30[];
extern "C" char data_02108760[];
// Original: arm9/ov006 @ 0x02159E50; symbol: func_ov006_02159e50; size: 0xBC.
extern "C" int Graphics_UpdateSelectionAndFinalizeInputResult(unsigned char *self) {
    int result = 0;
    self[0x42c] = 0;
    *(void**)(self + 0x44) = self + 0x36c;
    if (UpdateSelectionFromNewInputOrCoordinates(self) || Object_TestNewlySetHalfwordMask(data_02114e30,0x200)) {
        DispatchStoredHalfwordIndexWithTwoArguments(data_02108760,1,0);
        result = -1;
        if (*(short*)(self + 0x36c) == 34) result = 1;
    } else if (TestInputOrAssociatedObjectGate(self)) result = -1;
    if (result) {
        ResolveAndResetPresentEntry(*(unsigned char**)(self + 0x14), *(short*)(self + 0x36e));
        ResetPointedHalfwordAndSynchronizeSignedByteState(self + 0x9c);
        *(void**)(self + 0x44) = 0;
    }
    if (*(void***)(self + 0x18) && result) SetLinkedFlagStateAndResetOwner(*(void***)(self + 0x18));
    return result;
}
