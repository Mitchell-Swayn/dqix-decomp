#include "globaldefs.h"
#pragma optimize_for_size off
ARM
extern "C" void _Z21InitializeCardReadingv(); extern "C" void _Z22SetReadContextPriorityj(unsigned); extern "C" int _Z19GenerateLockOwnerIDv(); extern "C" void DisableInterruptsAndHaltForever(); extern "C" void LockCardReadManagerModeTwo(unsigned short); extern "C" void Card_WaitForIdleAndUnlockReadManager(unsigned short); extern "C" void CardReadManager_ExecuteModeCommandSynchronously(unsigned);
// Original data: arm9/main @ 0x20f0dc8; symbol: data_020f0dc8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 01000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2108dfc; symbol: data_02108dfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct State {unsigned short a,owner;}; extern "C" State SaveDataWriteBackupBytes_UnknownRoleZeroInitializedStorage; extern "C" unsigned char SaveDataWriteBackupBytes_UnknownRoleInitializedBytes;
// Original: arm9/main @ 0x020758A8; symbol: func_020758a8; size: 0x68.
extern "C" void Filesystem_InitializeCardReadingAndLockOwner(){_Z21InitializeCardReadingv();_Z22SetReadContextPriorityj(8);int owner=_Z19GenerateLockOwnerIDv();if(owner==-3)DisableInterruptsAndHaltForever();SaveDataWriteBackupBytes_UnknownRoleZeroInitializedStorage.owner=owner;LockCardReadManagerModeTwo(SaveDataWriteBackupBytes_UnknownRoleZeroInitializedStorage.owner);CardReadManager_ExecuteModeCommandSynchronously(0x1001);Card_WaitForIdleAndUnlockReadManager(SaveDataWriteBackupBytes_UnknownRoleZeroInitializedStorage.owner);SaveDataWriteBackupBytes_UnknownRoleInitializedBytes=1;}
