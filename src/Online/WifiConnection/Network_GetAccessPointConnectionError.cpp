#include <globaldefs.h>
ARM
extern "C" int Network_GetConnectionWorkspace(unsigned);
extern "C" unsigned Network_GetConnectionFailureCategory(void);
extern "C" int Network_MapStartupFailureToError(unsigned);
extern "C" int Util_ReturnMinusSixForSmallSelector(void);
extern "C" unsigned Network_MapAssociationFailureToError(void*);
extern "C" int Network_MapConnectionProgressToError(void*);
// Original: arm9/ov031 @ 0x02214358; symbol: func_ov031_02214358; size: 0x50.
extern "C" int Network_GetAccessPointConnectionError(void) {
    int workspace = Network_GetConnectionWorkspace(1);
    int category = (int)Network_GetConnectionFailureCategory();
    if (category < 4) return Network_MapStartupFailureToError((unsigned)category);
    if (category < 5) return Util_ReturnMinusSixForSmallSelector();
    if (category == 5) return (int)Network_MapAssociationFailureToError((void*)workspace);
    return Network_MapConnectionProgressToError((void*)workspace);
}
