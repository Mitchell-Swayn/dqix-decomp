#include <globaldefs.h>
#include <std_library_functions.h>
#include <GameState/GameState.h>
extern "C" {
    extern char data_020f1bf8[];
    bool func_02075910(int,void *,unsigned int,int);
    void func_02075acc(int,void *,unsigned int,int);
    void WriteActive(GameState *);
    void SaveData_InitializeDefaultStateAndPackets();
// Original: arm9/main @ 0x020AC910; symbol: func_020ac910; size: 0x9C.
    bool SaveData_CheckAndInitializeSignature(){
        char text[16];
        memset(text,0,16);
        if(!func_02075910(0,text,16,0)){
            GameState *state=GameState::GetInstance();
            ((unsigned char *)state)[23752]=0;
            WriteActive(state);
            return false;
        }if(strcmp(text,data_020f1bf8)){
            SaveData_InitializeDefaultStateAndPackets();
            memcpy(text,data_020f1bf8,16);
            func_02075acc(0,text,16,0);
        }return true;
    }
}
