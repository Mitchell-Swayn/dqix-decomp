#include <globaldefs.h>
ARM
#include <std_library_functions.h>
struct State;
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
extern "C" unsigned _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*,const char*,const char*,void*);
extern "C" void* func_ov011_021849c8(State* self);
extern "C" void OV023_WriteWordField04(void*, unsigned);
extern "C" int OV023_ReadWordField04(void*);
extern "C" char data_ov023_021fec3c[];
// Original: arm9/ov023 @ 0x021FA8FC; symbol: func_ov023_021fa8fc; size: 0xA8.
extern "C" int Filesystem_QueuePendingFileOrArchiveLoad(char *self, State *state) {
    void *entry = func_ov011_021849c8(state);
    if (OV023_ReadWordField04(entry) < 0) {
        void *loader = _ZN16BackgroundLoader11GetInstanceEv();
        char path[80];
        if (*(char **)(self + 0x20)) sprintf(path, data_ov023_021fec3c, *(char **)(self + 0x20));
        else sprintf(path, data_ov023_021fec3c, *(char **)(self + 0x10));
        unsigned task;
        if (*(char **)(self + 0x20)) task = _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,path,*(char **)(self + 0x10),0);
        else task = _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,path,0);
        OV023_WriteWordField04(entry, task);
        return 1;
    }
    return *(int *)(self + 0x1c);
}
