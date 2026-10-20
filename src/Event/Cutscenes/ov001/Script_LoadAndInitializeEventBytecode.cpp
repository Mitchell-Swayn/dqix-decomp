#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
ARM
extern "C" unsigned Script_ReadParameterString(void* self);

extern "C" int sprintf(char* buffer, const char* format, ...);
extern "C" unsigned Event_LoadFileIntoSharedScratch(const char* path,void** out);
extern "C" unsigned* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void* memcpy(void* dest, const void* source, unsigned int count);
extern "C" void Event_ResetSceneSessions(void);
extern "C" void Memory_InitializeContextBuffersWhenEnabled(void *script, int unused, void *allocator);
extern "C" unsigned char Script_LoadEventTextTable_PathDataS[], EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov001 @ 0x0215F1FC; symbol: Script_LoadAndInitializeEventBytecode; size: 0xec.
// Loads a named background file, copies it into the configured allocator, then initializes dependent buffers.
extern "C" int Script_LoadAndInitializeEventBytecode(void *parameter) {
    unsigned index = Script_ReadParameterString(parameter);
    if (!((void *)GameState::GetInstance())) return 0;
    char path[32];
    sprintf(path, (const char *)Script_LoadEventTextTable_PathDataS, index);
    void *allocator;
    void *loaded;
    unsigned size;
    register int locked = 0;
    allocator = *(void **)EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage;
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    loader->GetLoadedFileByName(path, &loaded, &size);
    if (!loaded) {
        BackgroundLoader::AddLockGlobal();
        locked = 1;
        if (!Event_LoadFileIntoSharedScratch(path, &loaded)) {
            BackgroundLoader::RemoveLockGlobal();
            return 0;
        }
    }
    char *copy = (char *)_ZN13SafeAllocator8AllocateEj(allocator, size);
    if (!copy) {
        if (locked) BackgroundLoader::RemoveLockGlobal();
        return 0;
    }
    memcpy(copy, loaded, size);
    if (locked) BackgroundLoader::RemoveLockGlobal();
    Event_ResetSceneSessions();
    Memory_InitializeContextBuffersWhenEnabled(copy, 0, allocator);
    return 1;
}
