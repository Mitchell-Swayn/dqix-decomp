#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <Filesystem/GPC.h>
#include <std_library_functions.h>
struct ResourceManager;
struct ResourceLock;
struct ResourcePair { SafeAllocator *allocator; ResourceLock *lock; };
extern "C" {
ResourceManager *Object_GetGlobalSixteenEntryDisplayState();
void Graphics_RestoreTextureImageAndPaletteVRAMState(ResourceLock *);
void Object_InvokeSaveTextureImageVRAMState(ResourceLock *);
int AllocateInitializeAndAppendLinkedNode(ResourceManager *,int,SafeAllocator *,void *,unsigned,ResourceLock *);
extern char data_020f28cb[];
}
// Original: arm9/main @ 0x020DAA58; symbol: func_020daa58; size: 0x110.
extern "C" int ResourceLoader_LoadTwoNamedGP2FilesUnderLocks(ResourcePair *pair, GPCFile *gpc, int first, int second) {
    ResourceManager *manager = Object_GetGlobalSixteenEntryDisplayState();
    void *loaded;
    SafeAllocator *allocator = pair->allocator;
    ResourceLock *lock = pair->lock;
    if (!manager || !allocator || !lock) return 0;
    {
        unsigned size = 0;
        void *data = 0;
        char name[32];
        sprintf(name, data_020f28cb, first);
        if (GetUnknownGP2InnerFileDataByName(&data, &size, gpc, name)) {
            loaded = data;
            Graphics_RestoreTextureImageAndPaletteVRAMState(lock);
            AllocateInitializeAndAppendLinkedNode(manager, 0x14, allocator, loaded, size, lock);
            Object_InvokeSaveTextureImageVRAMState(lock);
        }
        sprintf(name, data_020f28cb, second);
        if (GetUnknownGP2InnerFileDataByName(&data, &size, gpc, name)) {
            loaded = data;
            Graphics_RestoreTextureImageAndPaletteVRAMState(lock);
            AllocateInitializeAndAppendLinkedNode(manager, 0x15, allocator, loaded, size, lock);
            Object_InvokeSaveTextureImageVRAMState(lock);
        }
        return 1;
    }

}
