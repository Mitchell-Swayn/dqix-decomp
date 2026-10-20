#include <globaldefs.h>
ARM
extern "C" void *GameResources_GetInstance(void);
extern "C" unsigned short FieldEvent_GetPendingContinuationEventId(char *);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov001 @ 0x02163164; symbol: func_ov001_02163164; size: 0x40.
extern "C" int UpdateTypeThreeFromResourceFlag(void *object) {
    unsigned short active = FieldEvent_GetPendingContinuationEventId(*(char **)((char *)GameResources_GetInstance() + 0x3734));
    if (active) {
        Script_WriteIntegerReferenceOutput(object, 1);
    } else {
        Script_WriteIntegerReferenceOutput(object, 0);
    }
    return 1;
}
