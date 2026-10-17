#include <globaldefs.h>
extern "C" void BackgroundLoader_RemoveTaskAndClearLoadedPointer(void);
extern "C" void ProcessStateOneOrRemoveRecordForStateTwo(int);
extern "C" void InitializeRecordWithInvalidWordC(int);

// Original: arm9/main @ 0x020DBEBC; symbol: func_020dbebc; size: 0x20.
extern "C" void UpdateObjectThroughThreeHandlers(int object) {
    BackgroundLoader_RemoveTaskAndClearLoadedPointer();
    ProcessStateOneOrRemoveRecordForStateTwo(object);
    InitializeRecordWithInvalidWordC(object);
}
