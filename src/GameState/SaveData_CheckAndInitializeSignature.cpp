#include <globaldefs.h>
#include <std_library_functions.h>
#include <GameState/GameState.h>
extern "C" {
    extern char SaveData_CheckAndInitializeSignature_TextDRAGONQUESTIX[];
    bool SaveData_ReadCardSaveBytes(int,void *,unsigned int,int);
    void SaveData_WriteBackupBytes(int,void *,unsigned int,int);
    void GameState_RequestSaveErrorExit(GameState *);
    void SaveData_InitializeDefaultStateAndPackets();
// Original: arm9/main @ 0x020AC910; symbol: func_020ac910; size: 0x9C.
    bool SaveData_CheckAndInitializeSignature(){
        char text[16];
        memset(text,0,16);
        if(!SaveData_ReadCardSaveBytes(0,text,16,0)){
            GameState *state=GameState::GetInstance();
            ((unsigned char *)state)[23752]=0;
            GameState_RequestSaveErrorExit(state);
            return false;
        }if(strcmp(text,SaveData_CheckAndInitializeSignature_TextDRAGONQUESTIX)){
            SaveData_InitializeDefaultStateAndPackets();
            memcpy(text,SaveData_CheckAndInitializeSignature_TextDRAGONQUESTIX,16);
            SaveData_WriteBackupBytes(0,text,16,0);
        }return true;
    }
}
