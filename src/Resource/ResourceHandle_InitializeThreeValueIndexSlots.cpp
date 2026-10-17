#include <globaldefs.h>
ARM
extern "C" void InitializeHandleAndSignedIndexDefaults(void*); extern "C" void ApplyScaledValueToChannelIndices(void*,unsigned); extern "C" void SetStateWithinOneThroughFiveAndDispatch(void*,int);
struct Slot { unsigned value; short index,pad; }; struct Object { unsigned char padding[0xb0]; Slot slots[3]; };
// Original: arm9/main @ 0x0205E88C; symbol: func_0205e88c; size: 0x48.
extern "C" void ResourceHandle_InitializeThreeValueIndexSlots(Object* object) { InitializeHandleAndSignedIndexDefaults(object); object->slots[0].value=0; object->slots[0].index=-1; object->slots[1].value=0; object->slots[1].index=-1; object->slots[2].value=0; object->slots[2].index=-1; ApplyScaledValueToChannelIndices(object,0x7f); SetStateWithinOneThroughFiveAndDispatch(object,3); }
