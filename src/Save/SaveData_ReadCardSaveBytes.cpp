#include <globaldefs.h>
#include <Filesystem/CardReadManager.h>
#include <System/Memory.h>
ARM

// Original data: arm9/main @ 0x02108DFC; symbol: SaveDataWriteBackupBytes_UnknownRoleZeroInitializedStorage.
// Backup access state: idle flag, card lock owner and an optional in-memory save image.
struct SaveBackupAccessState {
    unsigned char idle;
    unsigned char reserved01;
    unsigned short lockOwner;
    unsigned char* memoryImage;
};

extern "C" {
extern SaveBackupAccessState SaveDataWriteBackupBytes_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x020F0DC8; set once card backup access is initialized.
extern unsigned char SaveDataWriteBackupBytes_UnknownRoleInitializedBytes;
void LockCardReadManagerModeTwo(unsigned short a);
void Card_WaitForIdleAndUnlockReadManager(unsigned short id);
unsigned int CardReadManager_GetBackupDeviceType();
bool WaitForCardReadManagerIdle();
void CardRead_IgnoreCompletion(void* context);
int CardReadManager_DispatchBackupTransfer(unsigned int source, unsigned int destination, unsigned int length,
    void (*callback)(void*), void* context, int async, int requestType, int retryCount, int requestMode);
}

static inline int SaveData_IsBackupDevice(unsigned int device)
{
    return (unsigned char)CardReadManager_GetBackupDeviceType() == device ? 1 : 0;
}

// Original: arm9/main @ 0x02075910; symbol: func_02075910; size: 0x1BC.
// Reads save bytes from the in-memory image when present, otherwise from the card backup
// (EEPROM, flash or FRAM read request). Synchronous reads wait, unlock and mark the state idle.
extern "C" int SaveData_ReadCardSaveBytes(int offset, void* destination, unsigned int length, int async)
{
    if (SaveDataWriteBackupBytes_UnknownRoleZeroInitializedStorage.memoryImage != 0) {
        if (offset >= 0x8000)
            offset -= 0x8000;
        MI_CpuCopy8(SaveDataWriteBackupBytes_UnknownRoleZeroInitializedStorage.memoryImage + offset, destination, length);
        return 1;
    }
    if (SaveDataWriteBackupBytes_UnknownRoleInitializedBytes == 0)
        return 0;
    SaveDataWriteBackupBytes_UnknownRoleZeroInitializedStorage.idle = 0;
    int result = 1;
    LockCardReadManagerModeTwo(SaveDataWriteBackupBytes_UnknownRoleZeroInitializedStorage.lockOwner);
    if (SaveData_IsBackupDevice(1))
        CardReadManager_DispatchBackupTransfer(offset, (unsigned int)destination, length, CardRead_IgnoreCompletion, 0, 1, 6, 1, 0);
    else if (SaveData_IsBackupDevice(2))
        CardReadManager_DispatchBackupTransfer(offset, (unsigned int)destination, length, CardRead_IgnoreCompletion, 0, 1, 6, 1, 0);
    else if (SaveData_IsBackupDevice(3))
        CardReadManager_DispatchBackupTransfer(offset, (unsigned int)destination, length, CardRead_IgnoreCompletion, 0, 1, 6, 1, 0);
    if (async) {
        if (GetCardReadManagerSharedStatus() != 0)
            result = 0;
    } else {
        WaitForCardReadManagerIdle();
        if (GetCardReadManagerSharedStatus() != 0)
            result = 0;
        Card_WaitForIdleAndUnlockReadManager(SaveDataWriteBackupBytes_UnknownRoleZeroInitializedStorage.lockOwner);
        SaveDataWriteBackupBytes_UnknownRoleZeroInitializedStorage.idle = 1;
    }
    return result;
}
