#include <globaldefs.h>
#include <Resource/Script.h>
#include <GameState/GameState.h>
ARM
#pragma opt_common_subs off
extern "C" {
extern int data_02108d70[];
void GameState_SetField5CB0AndSelectedRecordFirstByte(GameState *,int);void GameState_WriteField5CB4AndIndexedRecordValue(GameState *,int);void GameState_SetWord5CB8AndSelectedRecordByte(GameState *,int);
unsigned char *ReadGlobalValueAt02108844();void ClearIndexedTwentyEightByteRecordPayload(void *,int);void Object_ClearTrailingTwelveBytesOfTwentyEightByteEntry(void *,int);void ClearOwnerFlagBitRange(void *,int,int);void BitArray_SetIndexedBoolean(void *,void *,unsigned short,int);
// Original: arm9/main @ 0x020716A4; symbol: func_020716a4; size: 0x16C.
int Script_SetGameStateValuesAndSelectedBitLists(Script::Parameter *params,int count) {
    if(data_02108d70[5]!=params->ToInt())return 1;
    int a=params[1].ToInt();int c;int b=params[2].ToInt();Script::Parameter *third=params+3;params+=4;c=third->ToInt();
    GameState *state=GameState::GetInstance();GameState_SetField5CB0AndSelectedRecordFirstByte(state,a);GameState_WriteField5CB4AndIndexedRecordValue(state,b);GameState_SetWord5CB8AndSelectedRecordByte(state,c);
    unsigned char *p=ReadGlobalValueAt02108844();ClearIndexedTwentyEightByteRecordPayload(p,p[0x332]);Object_ClearTrailingTwelveBytesOfTwentyEightByteEntry(p,p[0x332]);ClearOwnerFlagBitRange(p,0,512);ClearOwnerFlagBitRange(p,910,1000);
    for(int i=0;i<count-4;i++) {
        int value=params->ToInt();params++;switch(value>>16){case 2:BitArray_SetIndexedBoolean(p,p+p[0x332]*28+3,(unsigned short)value,1);break;case 1:BitArray_SetIndexedBoolean(p,p+p[0x332]*28+16,(unsigned short)value,1);break;case 0:BitArray_SetIndexedBoolean(p,p+0x8c,(unsigned short)value,1);break;}
    }
    return 1;
}
}
