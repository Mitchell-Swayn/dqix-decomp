#include <globaldefs.h>
ARM
extern "C" char Graphics_LoadAnimationArchiveById_PathDataEventLv5SChr[];
// Original data: arm9/main @ 0x211e33c; symbol: data_0211e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 7889 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant6[];
extern "C" int sprintf(char*, const char*, ...);
extern "C" void* __clear(void*, unsigned);
extern "C" void Object3D_ResetArchiveLoadInfo(unsigned*);
extern "C" void _ZN8Object3D26RemoveAnimationPackageByIDEi(void*, int);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*, void*, unsigned);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv();
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv();
extern "C" void* _Z18LoadFileIntoMemoryPKcPvPj(const char*, void*, unsigned*);
extern "C" void _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(void*, void*, void*);
extern "C" void _ZN8Object3D20StopCurrentAnimationEv(void*);
extern "C" bool _ZN8Object3D23SetBCFGAnimationByIndexEii(void*, int, int);
struct LocalArchiveInfo { unsigned zero; const void* file; unsigned size; void* allocator; unsigned option, reserved1, reserved2, packageId; };
struct LocalAllocator { unsigned words[5]; };
struct LocalFrame { unsigned loadedSize; LocalArchiveInfo info; LocalAllocator allocator; char path[128]; };
// Original: arm9/ov015 @ 0x0218CB2C; symbol: func_ov015_0218cb2c; size: 0xF8.
// Removes package 3, loads the requested CCHR/CMOT file under a temporary allocator, then selects animation state.
extern "C" void Graphics_LoadAnimationArchiveById(void* self, int fileId) {
    LocalFrame frame;
    _ZN8Object3D26RemoveAnimationPackageByIDEi(*(void**)((char*)self + 0x24), 3);
    if (fileId != 0) {
        _ZN13SafeAllocator21ResetAllocatorPointerEv(&frame.allocator);
        _ZN13SafeAllocator11CreateTypeAEPvj(&frame.allocator, *(void**)((char*)self + 0x14), *(unsigned*)((char*)self + 0x18));
        _ZN13SafeAllocator5ResetEv(&frame.allocator);
        __clear(frame.path, 0x80);
        _ZN16BackgroundLoader13AddLockGlobalEv();
        frame.loadedSize = 0;
        sprintf(frame.path, Graphics_LoadAnimationArchiveById_PathDataEventLv5SChr, fileId);
        if (_Z18LoadFileIntoMemoryPKcPvPj(frame.path, Main_UnknownRoleZeroInitializedStorage_Variant6, &frame.loadedSize) != 0) {
            Object3D_ResetArchiveLoadInfo((unsigned*)&frame.info);
frame.info.allocator=&frame.allocator;
frame.info.file=Main_UnknownRoleZeroInitializedStorage_Variant6;
frame.info.size=frame.loadedSize;
frame.info.option=1;frame.info.packageId=3;
            _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(*(void**)((char*)self + 0x24), &frame.info, 0);
        }
        _ZN16BackgroundLoader16RemoveLockGlobalEv();
        _ZN13SafeAllocator7DestroyEv(&frame.allocator);
    }
    _ZN8Object3D20StopCurrentAnimationEv(*(void**)((char*)self + 0x24));
    _ZN8Object3D23SetBCFGAnimationByIndexEii(*(void**)((char*)self + 0x24), 0, *(int*)((char*)self + 0x44));
}
