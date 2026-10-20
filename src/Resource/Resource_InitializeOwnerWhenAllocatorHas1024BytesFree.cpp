#pragma thumb off
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

extern "C" {
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];
extern const char Resource_InitializeOwnerWhenAllocatorHas1024BytesFree_PathDataBinQtutomsgGp2[];
extern const char Resource_InitializeOwnerWhenAllocatorHas1024BytesFree_MarkupQtutomsgLGNat[];
unsigned Memory_ReadMaximumAlignedAllocation(void*);
void* AllocatorUnion_AllocateFourByteAligned(void*, unsigned);
void* SystemState_GetGlobalFlags();
void SystemState_SetFlags(void*, int);
void GameObject_DisableMovementInput(void*, int);
void Resource_ResetGameResourcesAndReturnSignedAllocatorBlock(void*);
void ResourceStringTable_CopySerializedData(void*, void*, void*, unsigned);
int DisplayContext_GetGlobalInstance();
void DisplayContext_IgnoreHook();
void BackgroundLoader_CancelEightTasksAndResetState(int);
void DisplayContext_IgnoreRequest(int, int, int);
int DisplayContext_ReportRequestComplete();
int TextContext_GetSharedInstance();
void TextLayout_ResetFormattingWorkspace();
void TextContext_SetStringArgument(int, int, void*);
int ResourceStringTable_GetTextByKey(void*, int);
void TextWindow_StartFormattedMessage(int, int, int, int);
}

// Original: arm9/main @ 0x020D9B34; symbol: func_020d9b34; size: 0x22C.
extern "C" void Resource_InitializeOwnerWhenAllocatorHas1024BytesFree(unsigned char* self) {
    if (self[9] == 0) {
        if (Memory_ReadMaximumAlignedAllocation(Main_UnknownRoleZeroInitializedStorage_Variant3) < 0x400) {
            self[1] = 1;
            return;
        }
        GameObject* object = GameState::GetInstance()->GetUnknownGameObject();
        GameObject_DisableMovementInput(object, 1);
        void* map = SystemState_GetGlobalFlags();
        SystemState_SetFlags(map, 14);
        SafeAllocator* allocator = (SafeAllocator*)(self + 0x58);
        allocator->ResetAllocatorPointer();
        void* buffer = AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3, 0x400);
        allocator->CreateTypeA(buffer, 0x400);
        allocator->Reset();
        *(int*)(self + 0x0c) = BackgroundLoader::GetInstance()->QueueLoadFileInGP2(
            &Resource_InitializeOwnerWhenAllocatorHas1024BytesFree_PathDataBinQtutomsgGp2[0], &Resource_InitializeOwnerWhenAllocatorHas1024BytesFree_MarkupQtutomsgLGNat[0], 0);
        ++self[9];
    } else if (self[9] == 1) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (loader->GetTaskStatus(*(int*)(self + 0x0c)) != 0) {
            if (loader->GetDetailedTaskStatus(*(int*)(self + 0x0c)) != 2) {
                loader->RemoveTask(*(int*)(self + 0x0c));
                *(int*)(self + 0x0c) = -1;
                Resource_ResetGameResourcesAndReturnSignedAllocatorBlock(self);
                self[1] = 1;
                return;
            }
            void* data;
            unsigned size;
            loader->GetLoadedFileByID(*(int*)(self + 0x0c), &data, &size);
            ResourceStringTable_CopySerializedData(self + 0x40, self + 0x58, data, size);
            loader->RemoveTask(*(int*)(self + 0x0c));
            *(int*)(self + 0x0c) = -1;
            ++self[9];
        }
    } else if (self[9] == 2) {
        int value = DisplayContext_GetGlobalInstance();
        DisplayContext_IgnoreHook();
        BackgroundLoader_CancelEightTasksAndResetState(value);
        DisplayContext_IgnoreRequest(value, 0x207, 0);
        ++self[9];
    } else if (self[9] == 3) {
        DisplayContext_GetGlobalInstance();
        if (DisplayContext_ReportRequestComplete() != 0) {
            int object = TextContext_GetSharedInstance();
            TextLayout_ResetFormattingWorkspace();
            TextContext_SetStringArgument(object, 0, self + 0x10);
            // Preserve the observed index load before computing the resource subobject.
            signed char index = ((volatile signed char*)self)[8];
            int resource = ResourceStringTable_GetTextByKey(self + 0x40, index);
            TextWindow_StartFormattedMessage(object, resource, 0, 0xe3);
            *(int*)(object + 0x998) = 1;
            ++self[9];
        }
    } else if (self[9] == 4) {
        int object = TextContext_GetSharedInstance();
        if (*(int*)(object + 0x998) == 0) {
            Resource_ResetGameResourcesAndReturnSignedAllocatorBlock(self);
            self[1] = 1;
        }
    }
}
