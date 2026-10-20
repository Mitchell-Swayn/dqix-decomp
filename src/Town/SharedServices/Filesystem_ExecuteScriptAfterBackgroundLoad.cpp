#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*, const char*, void*);
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*, unsigned);
extern "C" unsigned _ZN16BackgroundLoader21GetDetailedTaskStatusEi(void*, unsigned);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*, int);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*, unsigned, void**, unsigned*);
extern "C" void _ZN6Script10InitializeEv(void*);
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void*, void*);
extern "C" void _ZN6Script4LoadEPKvj(void*, const void*, unsigned);
extern "C" void _ZN6Script7ExecuteEv(void*);
extern "C" void _Z13SetBrightnessP13GameResourcesii(void*, int, int);
extern "C" void* GameResources_GetInstance();
// Original data: arm9/ov003 @ 0x2180cd0; symbol: data_ov003_02180cd0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" unsigned char FilesystemExecuteScriptAfterBackgroundLoad_UnknownRoleZeroInitializedStorage[];
extern "C" const char Filesystem_ExecuteScriptAfterBackgroundLoad_PathDataMenuRbEventBin[];
// Original data: arm9/ov003 @ 0x2180bc8; symbol: data_ov003_02180bc8.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 690000001cbb17020000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" void* FilesystemExecuteScriptAfterBackgroundLoad_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/ov003 @ 0x0217BE40; symbol: func_ov003_0217be40; size: 0x138.
extern "C" void Filesystem_ExecuteScriptAfterBackgroundLoad(unsigned char *p) {
    unsigned char script[0x430];
    void *loader = _ZN16BackgroundLoader11GetInstanceEv();
    void *resources = GameResources_GetInstance();
    if ((signed char)*(signed char*)(p + 0x141) == 0) {
        _ZN9GameState11GetInstanceEv();
        int file = (signed char)*(signed char*)(p + 0x12d);
        if (file >= 0) {
            FilesystemExecuteScriptAfterBackgroundLoad_UnknownRoleZeroInitializedStorage[0] = (unsigned char)file;
            unsigned id = _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader, Filesystem_ExecuteScriptAfterBackgroundLoad_PathDataMenuRbEventBin, 0);
            *(unsigned*)(p + 0x13c) = id;
            _Z13SetBrightnessP13GameResourcesii(resources, -16, 10);
            p[0x141] = *(signed char*)(p + 0x141) + 1;
        }
    } else if ((signed char)*(signed char*)(p + 0x141) == 1) {
        if (_ZN16BackgroundLoader13GetTaskStatusEi(loader, *(unsigned*)(p + 0x13c)) != 0) {
            unsigned status = _ZN16BackgroundLoader21GetDetailedTaskStatusEi(loader, *(unsigned*)(p + 0x13c));
            if (status != 2) {
                _ZN16BackgroundLoader10RemoveTaskEi(loader, *(unsigned*)(p + 0x13c));
                p[0x140] = 4;
                p[0x141] = 0;
            }
            void *data;
            unsigned length;
            _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader, *(unsigned*)(p + 0x13c), &data, &length);
            _ZN6Script10InitializeEv(script);
            _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(script, FilesystemExecuteScriptAfterBackgroundLoad_UnknownRoleProcedureReferenceRecords);
            _ZN6Script4LoadEPKvj(script, data, length);
            _ZN6Script7ExecuteEv(script);
            p[0x140] = 1;
            p[0x141] = 0;
        }
    }
}
