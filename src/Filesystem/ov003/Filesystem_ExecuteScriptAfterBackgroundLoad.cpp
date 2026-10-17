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
extern "C" unsigned char data_ov003_02180cd0[];
extern "C" const char data_ov003_02180bd8[];
extern "C" void* data_ov003_02180bc8[];
// Original: arm9/ov003 @ 0x0217BE40; symbol: func_ov003_0217be40; size: 0x138.
extern "C" void Filesystem_ExecuteScriptAfterBackgroundLoad(unsigned char *p) {
    unsigned char script[0x430];
    void *loader = _ZN16BackgroundLoader11GetInstanceEv();
    void *resources = GameResources_GetInstance();
    if ((signed char)*(signed char*)(p + 0x141) == 0) {
        _ZN9GameState11GetInstanceEv();
        int file = (signed char)*(signed char*)(p + 0x12d);
        if (file >= 0) {
            data_ov003_02180cd0[0] = (unsigned char)file;
            unsigned id = _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader, data_ov003_02180bd8, 0);
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
            _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(script, data_ov003_02180bc8);
            _ZN6Script4LoadEPKvj(script, data, length);
            _ZN6Script7ExecuteEv(script);
            p[0x140] = 1;
            p[0x141] = 0;
        }
    }
}
