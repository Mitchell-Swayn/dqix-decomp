#include <globaldefs.h>
ARM
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*, int, void**, unsigned*);
extern "C" void ResourceStringTable_CopyEntriesForKeys(void*, unsigned, void*, unsigned, void*, unsigned);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*, int);
struct LoadRequest { int taskId; void* output; unsigned char pad[0x7c]; unsigned index; unsigned char pad2[0x19]; unsigned char completed; };
// Original: arm9/ov000 @ 0x0216FD80; symbol: func_ov000_0216fd80; size: 0x78.
extern "C" void CompleteBackgroundFileLoad(LoadRequest* request, unsigned argument) {
    void* file;
    unsigned size;
    void* loader = _ZN16BackgroundLoader11GetInstanceEv();
    _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader, request->taskId, &file, &size);
    ResourceStringTable_CopyEntriesForKeys((char*)request + 0x88, argument, file, size, (char*)request + 4, request->index & 0xffff);
    _ZN16BackgroundLoader10RemoveTaskEi(loader, request->taskId);
    request->taskId = -1;
    request->completed = 1;
}
