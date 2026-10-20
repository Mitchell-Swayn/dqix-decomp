#include <globaldefs.h>
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" void* Zone3D_GetMainInstance(void);
extern "C" void* GameResources_GetInstance(void);
extern "C" void* GameState_ReadUnkF8(void*);
extern "C" unsigned int EventListScript_LoadDescriptorById(unsigned int, unsigned int);
extern "C" void* GameState_GetSerializedProgressState(void);
extern "C" unsigned int BitArray_ReadNonnegativeIndexMask(void*, unsigned char*, int);
extern "C" void InitializeTypeFourStateAndBuffers(void*, int);
extern "C" void WorldMap_SetFadeInBlocked(char*, int);
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned int*, unsigned int);
extern "C" void FieldEvent_MarkScriptDispatchRequested(void*);
extern "C" unsigned int Script_ExecuteEventKindThreeTriggers(void*, void*);
extern "C" void Script_DispatchResultCommandsToWorld(void*);
// Original: arm9/ov017 @ 0x0219FC88; symbol: System_LoadRecordAndUpdateOverlayNode; size: 0x118.
// Loads a record, updates an eligible overlay node, and reports whether it was accepted.
extern "C" ARM unsigned int Field_QueueZoneEntryEventOrRunFallbackTriggers(void*, unsigned int id) {
    void* gameState = _ZN9GameState11GetInstanceEv();
    void* zone = Zone3D_GetMainInstance();
    void* resources = GameResources_GetInstance();
    unsigned char* tint;
    unsigned int accepted;
    unsigned int* activeList;
    unsigned char local[0x9c];
    activeList = *(unsigned int**)((unsigned char*)resources + 0x36fc);
    tint = (unsigned char*)GameState_ReadUnkF8(gameState);
    accepted = 0;
    if (EventListScript_LoadDescriptorById((unsigned short)id, (unsigned int)(local + 0x34)) != 0) {
        void* progress = GameState_GetSerializedProgressState();
        int bit = *(short*)(local + 0x7a) + 0x38e;
        if (BitArray_ReadNonnegativeIndexMask(progress, (unsigned char*)progress + 0x8c, bit) == 0) {
            unsigned char* node = *(unsigned char**)((unsigned char*)resources + 0x3734);
            if (node[2] != 0) {
                *(unsigned short*)(node + 8) = (unsigned short)id;
            } else if (node[3] == 0) {
                InitializeTypeFourStateAndBuffers(node, 1);
                *(unsigned short*)(node + 8) = (unsigned short)id;
                WorldMap_SetFadeInBlocked(*(char**)((unsigned char*)resources + 0x36d0), 1);
                LinkedQueue_AppendAndMarkActive(activeList, (unsigned int)node);
            }
            FieldEvent_MarkScriptDispatchRequested(node);
            if (tint[0x0d] != 0) node[0x10a] = 1;
            accepted = 1;
        }
    }
    if (accepted == 0) {
        void* progress = GameState_GetSerializedProgressState();
        *(unsigned int*)(local + 0x0c) = *(unsigned short*)zone;
        if (Script_ExecuteEventKindThreeTriggers(progress, local) != 0) Script_DispatchResultCommandsToWorld(local);
    }
    return accepted;
}
