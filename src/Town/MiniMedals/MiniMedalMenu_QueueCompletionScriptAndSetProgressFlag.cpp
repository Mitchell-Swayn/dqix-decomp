#include <globaldefs.h>
ARM
extern "C" void* GameResources_GetInstance(void);
extern "C" void InitializeTypeFourStateAndBuffers(void*, int);
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned int*, unsigned int);
extern "C" void* GameState_GetSerializedProgressState(void);
extern "C" void Script_SetMappedUpperEntryFlag(int, int, int);
// Original: arm9/ov004 @ 0x02167FD4; symbol: AppendRecord6FAEAndDispatchDerivedIndex; size: 0x50.
// Initializes the resource record, sets type 0x6FAE, appends it, then dispatches the global derived index with parameters 0x17 and 1.
extern "C" int MiniMedalMenu_QueueCompletionScriptAndSetProgressFlag(void) {
    char* resources = (char*)GameResources_GetInstance() + 0x3000;
    unsigned int* list = *(unsigned int**)(resources + 0x6FC);
    void* record = *(void**)(resources + 0x734);
    InitializeTypeFourStateAndBuffers(record, 1);
    *(unsigned short*)((char*)record + 8) = 0x6FAE;
    LinkedQueue_AppendAndMarkActive(list, (unsigned int)record);
    Script_SetMappedUpperEntryFlag((int)GameState_GetSerializedProgressState(), 0x17, 1);
    return 0;
}
