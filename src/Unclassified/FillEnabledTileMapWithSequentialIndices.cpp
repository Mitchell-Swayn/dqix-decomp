#include <globaldefs.h>

extern "C" void func_0204c87c(void*, int);
extern "C" void FillTileRectangleWithSequentialIndices(void*);

// Original: arm9/main @ 0x0204C964; symbol: func_0204c964; size: 0x1C.
extern "C" ARM void FillEnabledTileMapWithSequentialIndices(void* object) {
    func_0204c87c(object, 1);
    FillTileRectangleWithSequentialIndices(object);
}
