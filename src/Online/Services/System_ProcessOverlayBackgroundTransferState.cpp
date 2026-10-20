#include <globaldefs.h>
extern "C" int _ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" int _ZN16BackgroundLoader17GetNumQueuedTasksEv(void);
extern "C" void* memset(void*, int, unsigned int);
extern "C" void OnlineTransfer_SetOperationMode(unsigned char*, int);
extern "C" unsigned int WirelessSettings_LoadAndClassifyIdentifierInitialization(unsigned char*);
extern "C" void Ov031_SetGlobalPair(unsigned int, unsigned int);
extern "C" char* OnlineTransfer_AllocateDownloadWorkspace(void*, unsigned int);
extern "C" void Memory_FreeSafeAllocatorPointer(void*);
// Original data: arm9/main @ 0x211e33c; symbol: data_0211e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 7889 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant6[];
// Original: arm9/ov031 @ 0x02243C10; symbol: System_ProcessOverlayBackgroundTransferState; size: 0x110.
// Advances overlay transfer state and initializes its background buffer when requested.
extern "C" ARM void System_ProcessOverlayBackgroundTransferState(unsigned char* self) {
    switch (self[0x35]) {
    case 0:
        if ((self[0x374] & 1) || (self[0x374] & 2)) {
            if (*(unsigned int*)(self + 0x37c) == 0) {
                _ZN16BackgroundLoader11GetInstanceEv();
                if (_ZN16BackgroundLoader17GetNumQueuedTasksEv() > 0) {
                    OnlineTransfer_SetOperationMode(self, 0);
                    return;
                }
                *(unsigned int*)(self + 0x37c) = (unsigned int)Main_UnknownRoleZeroInitializedStorage_Variant6;
                *(unsigned int*)(self + 0x380) = 0x30000;
            }
            memset(*(void**)(self + 0x37c), 0, *(unsigned int*)(self + 0x380));
            *(unsigned int*)(self + 0x48) = *(unsigned int*)(self + 0x37c);
        }
        {
            unsigned int result = WirelessSettings_LoadAndClassifyIdentifierInitialization(*(unsigned char**)(self + 0x4c));
            self[0x439] = 1;
            if (result == 3) {
                self[0x35] = 8;
                self[0x438] = 1;
            } else {
                self[0x35] = 6;
            }
        }
        return;
    case 6:
        Ov031_SetGlobalPair((unsigned int)OnlineTransfer_AllocateDownloadWorkspace, (unsigned int)Memory_FreeSafeAllocatorPointer);
        OnlineTransfer_SetOperationMode(self, 2);
        return;
    case 7:
        OnlineTransfer_SetOperationMode(self, 0);
        return;
    case 8:
        OnlineTransfer_SetOperationMode(self, 0);
        return;
    default:
        return;
    }
}
