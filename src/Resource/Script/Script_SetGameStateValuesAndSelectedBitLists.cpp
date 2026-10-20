#include <globaldefs.h>
#include <Resource/Script.h>
#include <GameState/GameState.h>
ARM
#pragma opt_common_subs off
extern "C" {
// Original data: arm9/main @ 0x2108d70; symbol: data_02108d70.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern int ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage[];
void GameState_SetProgressChapter(GameState *,int);void GameState_SetProgressStage(GameState *,int);void GameState_SetProgressStep(GameState *,int);
unsigned char *GameState_GetSerializedProgressState();void Script_ClearCategoryProgressFlags(void *,int);void Script_ClearCategorySecondaryProgressFlags(void *,int);void ClearOwnerFlagBitRange(void *,int,int);void BitArray_SetIndexedBoolean(void *,void *,unsigned short,int);
// Original: arm9/main @ 0x020716A4; symbol: func_020716a4; size: 0x16C.
int Script_SetGameStateValuesAndSelectedBitLists(Script::Parameter *params,int count) {
    if(ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage[5]!=params->ToInt())return 1;
    int a=params[1].ToInt();int c;int b=params[2].ToInt();Script::Parameter *third=params+3;params+=4;c=third->ToInt();
    GameState *state=GameState::GetInstance();GameState_SetProgressChapter(state,a);GameState_SetProgressStage(state,b);GameState_SetProgressStep(state,c);
    unsigned char *p=GameState_GetSerializedProgressState();Script_ClearCategoryProgressFlags(p,p[0x332]);Script_ClearCategorySecondaryProgressFlags(p,p[0x332]);ClearOwnerFlagBitRange(p,0,512);ClearOwnerFlagBitRange(p,910,1000);
    for(int i=0;i<count-4;i++) {
        int value=params->ToInt();params++;switch(value>>16){case 2:BitArray_SetIndexedBoolean(p,p+p[0x332]*28+3,(unsigned short)value,1);break;case 1:BitArray_SetIndexedBoolean(p,p+p[0x332]*28+16,(unsigned short)value,1);break;case 0:BitArray_SetIndexedBoolean(p,p+0x8c,(unsigned short)value,1);break;}
    }
    return 1;
}
}
