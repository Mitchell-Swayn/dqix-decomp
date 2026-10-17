#include <globaldefs.h>
#include <Graphics/Vector.h>
#pragma opt_propagation off
#include <GameState/GameState.h>
#include <System/Matrix.h>
#include <Filesystem/BackgroundLoader.h>

extern "C" char data_0211e33c[];

extern "C" {
char* ReadGlobalValueAt020FB3F0();
int func_020aaf84(void*, int, int, int);
void* ReadGlobalValueAt02108844();
void GetGlobalStatePointer();
void* memcpy(void*, const void*, unsigned);
void GameState_CopySourceBytesAndSelectedInitialFields(void*, void*, int);
void GameState_CopyTwo512ByteBuffersAndCount(void*);
void GameState_CopyFourHundredByteSaveRecord(void*);
void func_020a9b2c(void*);
void GameState_ResetGrottoAndTreasureMapInitialFlags(void*);
void* Object_GetBoundedEightByteRecordAtOffset74DE(void*, int);
void WriteActive(void*);
void func_02013b54(void*, const void*);
}

// Original: arm9/main @ 0x020ABD20; symbol: func_020abd20; size: 0x164.
extern "C" ARM bool SaveData_LoadAndRestoreGameAndZoneState(void)
{
    unsigned char work[8];
    GameState* game = GameState::GetInstance();
    GameResources_GetInstance();
    char* state = ReadGlobalValueAt020FB3F0();
    *(unsigned char*)((char*)game + 0x5cc8) = 0;
    int ok = func_020aaf84(work, 0, 0, 1);
    if (!ok) {
        WriteActive(game);
        return false;
    }

    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    char* save = data_0211e33c;
    save += 0x28000;
    void* serialized = ReadGlobalValueAt02108844();
    GameState_CopySourceBytesAndSelectedInitialFields(save + 0x2cac, serialized, 1);
    memcpy((char*)GameState::GetInstance() + 0x5e6c, save + 0x6c3c, 0x110);
    GameState_CopyTwo512ByteBuffersAndCount(save + 0x5a04);
    GameState_CopyFourHundredByteSaveRecord(save + 0x33c0);
    func_020a9b2c(save + 0x3ec4);

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
    memcpy(Object_GetBoundedEightByteRecordAtOffset74DE(game, 0), save + 0x2c54, 8);
    BackgroundLoader::RemoveLockGlobal();
    return true;
}
