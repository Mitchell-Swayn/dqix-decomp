#pragma thumb off
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

extern "C" {
extern unsigned char data_02114e20[];
extern const char data_020f2810[];
extern const char data_020f2826[];
unsigned Memory_ReadMaximumAlignedAllocation(void*);
void* AllocatorUnion_AllocateFourByteAligned(void*, unsigned);
void* GetGlobalStatePointer();
void SetWordMaskBits_Main020466E4(void*, int);
void Object_ClearTwoStateFieldsAndOptionallyResetAnimation(void*, int);
void Object_ResetGameResourcesAndReturnSignedAllocatorBlock(void*);
void func_020dfec0(void*, void*, void*, unsigned);
int Object_ReadGlobalDisplayContextWord();
void IgnoreDisplayContextHook();
void BackgroundLoader_CancelEightTasksAndResetState(int);
void IgnoreDisplayContextRequest(int, int, int);
int ReturnOne_Main02094B4C();
int ReadWordFieldAtOffset1C();
void ClearOwnerBuffersAndResetSignedByteSentinels();
void CopyBoundedNameToIndexedSlot(int, int, void*);
int ResolveIndexedRecordAndReturnSecondWord(void*, int);
void func_0204500c(int, int, int, int);
}

// Original: arm9/main @ 0x020D9B34; symbol: func_020d9b34; size: 0x22C.
extern "C" void InitializeOwnerWhenAllocatorHas1024BytesFree(unsigned char* self) {
    if (self[9] == 0) {
        if (Memory_ReadMaximumAlignedAllocation(data_02114e20) < 0x400) {
            self[1] = 1;
            return;
        }
        GameObject* object = GameState::GetInstance()->GetUnknownGameObject();
        Object_ClearTwoStateFieldsAndOptionallyResetAnimation(object, 1);
        void* map = GetGlobalStatePointer();
        SetWordMaskBits_Main020466E4(map, 14);
        SafeAllocator* allocator = (SafeAllocator*)(self + 0x58);
        allocator->ResetAllocatorPointer();
        void* buffer = AllocatorUnion_AllocateFourByteAligned(data_02114e20, 0x400);
        allocator->CreateTypeA(buffer, 0x400);
        allocator->Reset();
        *(int*)(self + 0x0c) = BackgroundLoader::GetInstance()->QueueLoadFileInGP2(
            &data_020f2810[0], &data_020f2826[0], 0);
        ++self[9];
    } else if (self[9] == 1) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (loader->GetTaskStatus(*(int*)(self + 0x0c)) != 0) {
            if (loader->GetDetailedTaskStatus(*(int*)(self + 0x0c)) != 2) {
                loader->RemoveTask(*(int*)(self + 0x0c));
                *(int*)(self + 0x0c) = -1;
                Object_ResetGameResourcesAndReturnSignedAllocatorBlock(self);
                self[1] = 1;
                return;
            }
            void* data;
            unsigned size;
            loader->GetLoadedFileByID(*(int*)(self + 0x0c), &data, &size);
            func_020dfec0(self + 0x40, self + 0x58, data, size);
            loader->RemoveTask(*(int*)(self + 0x0c));
            *(int*)(self + 0x0c) = -1;
            ++self[9];
        }
    } else if (self[9] == 2) {
        int value = Object_ReadGlobalDisplayContextWord();
        IgnoreDisplayContextHook();
        BackgroundLoader_CancelEightTasksAndResetState(value);
        IgnoreDisplayContextRequest(value, 0x207, 0);
        ++self[9];
    } else if (self[9] == 3) {
        Object_ReadGlobalDisplayContextWord();
        if (ReturnOne_Main02094B4C() != 0) {
            int object = ReadWordFieldAtOffset1C();
            ClearOwnerBuffersAndResetSignedByteSentinels();
            CopyBoundedNameToIndexedSlot(object, 0, self + 0x10);
            // Preserve the observed index load before computing the resource subobject.
            signed char index = ((volatile signed char*)self)[8];
            int resource = ResolveIndexedRecordAndReturnSecondWord(self + 0x40, index);
            func_0204500c(object, resource, 0, 0xe3);
            *(int*)(object + 0x998) = 1;
            ++self[9];
        }
    } else if (self[9] == 4) {
        int object = ReadWordFieldAtOffset1C();
        if (*(int*)(object + 0x998) == 0) {
            Object_ResetGameResourcesAndReturnSignedAllocatorBlock(self);
            self[1] = 1;
        }
    }
}
