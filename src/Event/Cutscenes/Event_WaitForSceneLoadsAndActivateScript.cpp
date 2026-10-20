#include <globaldefs.h>
ARM
extern "C" void * _ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void *, unsigned);
extern "C" void Event_InstantiateLoadedSceneObjects(char *);
extern "C" int Filesystem_QueuePendingLoadsInBatchesOfFive(unsigned char *);
extern "C" int Event_SelectScriptEntryAndRefreshSessions(void *);
// Original: arm9/ov001 @ 0x02155BB8; symbol: func_ov001_02155bb8; size: 0xF0.
// Waits for queued loader tasks, processes scene object lists, then advances pending overlay work.
extern "C" int Event_WaitForSceneLoadsAndActivateScript(char *state) {
    void *loader = _ZN16BackgroundLoader11GetInstanceEv();
    char *entry = *(char **)(state + 0xd0);
    while (entry) {
        int task = *(int *)(entry + 0x2c);
        if (task > -1 && !*(unsigned char *)(entry + 0x31) && _ZN16BackgroundLoader13GetTaskStatusEi(loader, (unsigned)task) == 0)
            return *(unsigned short *)(state + 0x0a);
        entry = *(char **)(entry + 0x34);
    }
    entry = *(char **)(state + 0xd4);
    while (entry) {
        int task = *(int *)(entry + 0x24);
        if (task > -1 && !*(unsigned char *)(entry + 0x2c) && _ZN16BackgroundLoader13GetTaskStatusEi(loader, (unsigned)task) == 0)
            return *(unsigned short *)(state + 0x0a);
        entry = *(char **)(entry + 0x28);
    }
    int finalTask = *(int *)(state + 0xf4);
    if (finalTask > -1 && _ZN16BackgroundLoader13GetTaskStatusEi(loader, (unsigned)finalTask) == 0)
        return *(unsigned short *)(state + 0x0a);
    Event_InstantiateLoadedSceneObjects(state);
    if (!*(unsigned char *)(state + 0x100)) {
        Filesystem_QueuePendingLoadsInBatchesOfFive((unsigned char *)state);
        return *(unsigned short *)(state + 0x0a);
    }
    Event_SelectScriptEntryAndRefreshSessions((void *)(unsigned long)*(unsigned short *)(state + 0x4a));
    return 4;
}
