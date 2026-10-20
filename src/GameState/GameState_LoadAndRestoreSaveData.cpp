#include <globaldefs.h>
#include <Graphics/Vector.h>
#pragma opt_propagation off
#include <GameState/GameState.h>
#include <System/Matrix.h>
#include <Filesystem/BackgroundLoader.h>

// Original data: arm9/main @ 0x211e33c; symbol: data_0211e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 7889 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant6[];

extern "C" {
char* Zone3D_GetMainInstance();
int SaveData_ReadValidateAndOptionallyRestoreBank(void*, int, int, int);
void* GameState_GetSerializedProgressState();
void SystemState_GetGlobalFlags();
void* memcpy(void*, const void*, unsigned);
void GameState_CopySourceBytesAndSelectedInitialFields(void*, void*, int);
void GameState_CopyTwo512ByteBuffersAndCount(void*);
void GameState_CopyFourHundredByteSaveRecord(void*);
int SaveData_RestoreZoneSnapshot(const void*);
void GameState_ResetGrottoAndTreasureMapInitialFlags(void*);
void* GameState_GetPendingPartyPositionRecord(void*, int);
void GameState_RequestSaveErrorExit(void*);
void func_02013b54(void*, const void*);
}

// Original: arm9/main @ 0x020ABD20; symbol: func_020abd20; size: 0x164.
extern "C" ARM bool GameState_LoadAndRestoreSaveData(void)
{
    unsigned char work[8];
    GameState* game = GameState::GetInstance();
    GameResources_GetInstance();
    char* state = Zone3D_GetMainInstance();
    *(unsigned char*)((char*)game + 0x5cc8) = 0;
    int ok = SaveData_ReadValidateAndOptionallyRestoreBank(work, 0, 0, 1);
    if (!ok) {
        GameState_RequestSaveErrorExit(game);
        return false;
    }

    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    char* save = Main_UnknownRoleZeroInitializedStorage_Variant6;
    save += 0x28000;
    void* serialized = GameState_GetSerializedProgressState();
    GameState_CopySourceBytesAndSelectedInitialFields(save + 0x2cac, serialized, 1);
    memcpy((char*)GameState::GetInstance() + 0x5e6c, save + 0x6c3c, 0x110);
    GameState_CopyTwo512ByteBuffersAndCount(save + 0x5a04);
    GameState_CopyFourHundredByteSaveRecord(save + 0x33c0);
    SaveData_RestoreZoneSnapshot(save + 0x3ec4);

    char* saveWords = save + 4;
    *(unsigned short*)(state + 0x2786) = *(unsigned short*)(saveWords + 0x2c00 + 0x5c);
    *(unsigned short*)(state + 0x2784) = *(short*)(saveWords + 0x2c00 + 0x5e);
    *(Vector3i*)(state + 0x2774) = *(const Vector3i*)(saveWords + 0x0c60 + 0x2000);
    *(unsigned*)(state + 0x2780) = *(unsigned*)(saveWords + 0x2000 + 0xc6c);
    *(unsigned char*)(state + 0x2788) = *(unsigned char*)(saveWords + 0x2000 + 0xc74);
    *(unsigned*)(state + 0x2794) = *(unsigned*)(saveWords + 0x2000 + 0xc70);
    *(unsigned short*)(state + 0x27b4) = (unsigned char)saveWords[0x2000 + 0xc75];
    *(unsigned short*)(state + 0x27b6) = (unsigned char)saveWords[0x2000 + 0xc76];
    char* stateTail = state + 0x1840;
    *(unsigned*)(stateTail + 0xb48) = *(unsigned*)(saveWords + 0x2000 + 0xc80);
    *(unsigned*)(stateTail + 0xb4c) = *(unsigned*)(saveWords + 0x2000 + 0xc84);
    GameState_ResetGrottoAndTreasureMapInitialFlags(game);
    memcpy(GameState_GetPendingPartyPositionRecord(game, 0), save + 0x2c54, 8);
    BackgroundLoader::RemoveLockGlobal();
    return true;
}
