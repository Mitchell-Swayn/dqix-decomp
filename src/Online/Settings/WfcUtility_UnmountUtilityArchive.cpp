#include <globaldefs.h>
ARM
#pragma force_active on

#include <Filesystem/LowNitroHandle.h>
struct ArchiveContext { void *tables; char prefix[0x84]; NitroHandle handle; unsigned short lockOwner; };
// Original data: arm9/ov031 @ 0x02290D24; symbol: data_ov031_02290d24.
// Zero-initialized archive pointer; handle and lock offsets are 0x88 and 0xE4.
extern "C" ArchiveContext *WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage;
namespace ContextStorageAddress { extern "C" ArchiveContext *WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage; }
// Original data: arm9/ov031 @ 0x0224C564; symbol: data_ov031_0224c564.
// Initialized filesystem root string: "rom:/".
extern "C" const char WfcUtility_UnmountUtilityArchive_TextRom[];
extern "C" void _Z20SetROMFilesystemRootPKc(const char *);
extern "C" void _Z18ReleaseLockOwnerIDt(unsigned short);
extern "C" void WfcUtility_FreeAllocationAndClearPointer(void **);
// Original: arm9/ov031 @ 0x0223B4D4; symbol: func_ov031_0223b4d4; size: 0x8C.
// Restores the ROM root, destroys the utility archive, releases its lock and clears owned allocations.
extern "C" void WfcUtility_UnmountUtilityArchive(void)
{
    _Z20SetROMFilesystemRootPKc(WfcUtility_UnmountUtilityArchive_TextRom);
    NitroHandle_ReleaseFileTables(&WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage->handle);
    NitroHandle_Destroy(&WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage->handle);
    NitroHandle_RemoveFromHandleList(&WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage->handle);
    _Z18ReleaseLockOwnerIDt(WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage->lockOwner);
    WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage->lockOwner = 0;
    WfcUtility_FreeAllocationAndClearPointer(&WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage->tables);
    WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage->tables = 0;
    WfcUtility_FreeAllocationAndClearPointer((void **)&ContextStorageAddress::WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage);
}
#pragma force_active reset
