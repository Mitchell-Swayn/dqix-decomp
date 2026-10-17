#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" unsigned char data_0210cfc0[];
extern "C" unsigned char data_0210cfd0[];
extern "C" unsigned char data_0210cfdc[];
extern "C" void InitializeGlobalCommandMutexAndTablesOnce(void);
extern "C" void FlushResourceStateAndSynchronizeCommandCounter(void);
extern "C" void ResourceManager_InvokeGlobalReset(void);
extern "C" void InvokeGlobalHeadListHandler(unsigned int);
extern "C" void LinkedList_AppendEntryToGlobalPendingList(unsigned int);
extern "C" void Object_ClearElement2AndClearElement0AndClearElement1(void);
extern "C" void ClearGlobal0210FD74Indices0And18(void);
extern "C" void InitializeTwoAllocatorListsAndSixteenSlots(void);
// Original: arm9/main @ 0x020BBD14; symbol: func_020bbd14; size: 0x88.
extern "C" void InitializeGlobalResourceCallbacksOnce(void) {
    if (*(int *)(data_0210cfc0 + 0xc) != 0) return;
    *(int *)(data_0210cfc0 + 0xc) = 1;
    InitializeGlobalCommandMutexAndTablesOnce();
    *(unsigned int *)(data_0210cfc0 + 0x10) = (unsigned int)FlushResourceStateAndSynchronizeCommandCounter;
    *(int *)(data_0210cfc0 + 0x14) = 0;
    *(unsigned int *)(data_0210cfc0 + 0x1c) = (unsigned int)ResourceManager_InvokeGlobalReset;
    *(int *)(data_0210cfc0 + 0x20) = 0;
    InvokeGlobalHeadListHandler((unsigned int)data_0210cfd0);
    LinkedList_AppendEntryToGlobalPendingList((unsigned int)data_0210cfdc);
    Object_ClearElement2AndClearElement0AndClearElement1();
    ClearGlobal0210FD74Indices0And18();
    InitializeTwoAllocatorListsAndSixteenSlots();
    ((signed char *)data_0210cfc0)[0] = -1;
    *(int *)(data_0210cfc0 + 4) = 1;
}
