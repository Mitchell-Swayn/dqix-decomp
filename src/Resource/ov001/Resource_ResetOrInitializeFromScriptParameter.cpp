#include <globaldefs.h>
ARM

extern "C" int ReadScriptParameterAsInteger(void *parameter);
extern "C" void ResourceHandle_ResetSlotsAndReleaseState(void *);
extern "C" void ResetObjectStateAndReleaseLinkedResource(void *);
extern "C" void LoadFixedOverlayResourceBuffer(void *);
extern "C" void ResourceHandle_InitializeFromOverlayDataAnd57000Buffer(void *);
extern "C" void LoadResourceForIds100And101AndSetState(void *, int);
extern "C" unsigned char data_02108760[];
extern "C" unsigned char data_02109bf4[];

// Original: arm9/ov001 @ 0x02163A5C; symbol: func_ov001_02163a5c; size: 0x58.
extern "C" int Resource_ResetOrInitializeFromScriptParameter(void *parameter) {
    if (ReadScriptParameterAsInteger(parameter) != 0) {
        ResourceHandle_ResetSlotsAndReleaseState(data_02108760);
        ResetObjectStateAndReleaseLinkedResource(data_02109bf4);
        LoadFixedOverlayResourceBuffer(data_02109bf4);
    } else {
        ResetObjectStateAndReleaseLinkedResource(data_02109bf4);
        ResourceHandle_InitializeFromOverlayDataAnd57000Buffer(data_02109bf4);
        LoadResourceForIds100And101AndSetState(data_02108760, 100);
    }
    return 1;
}
