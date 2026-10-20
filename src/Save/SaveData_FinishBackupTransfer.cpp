#include <globaldefs.h>
struct State {unsigned char active,pad;unsigned short id;};
// Original data: arm9/main @ 0x2108dfc; symbol: data_02108dfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" State SaveDataWriteBackupBytes_UnknownRoleZeroInitializedStorage;
extern "C" void Card_WaitForIdleAndUnlockReadManager(unsigned short);
// Original: arm9/main @ 0x02075CB8; symbol: func_02075cb8; size: 0x24.
extern "C" void SaveData_FinishBackupTransfer() {Card_WaitForIdleAndUnlockReadManager(SaveDataWriteBackupBytes_UnknownRoleZeroInitializedStorage.id);SaveDataWriteBackupBytes_UnknownRoleZeroInitializedStorage.active=1;}
