#pragma optimization_level 4
#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" {
    unsigned char *GameState_GetIndexList(GameState *);
// Original: arm9/main @ 0x020686E0; symbol: func_020686e0; size: 0x88.
    bool GameState_TestListedQualifyingMemberCountNotOne(GameState *state,unsigned char *entry){
        unsigned char *p=GameState_GetIndexList(state);
        signed char count=*(signed char *)(entry+49);
        if(count<0){
            count=0;
            for(int i=0;i<p[0xf7c];i++){
                unsigned char *obj=(unsigned char *)state->GetPartyMemberByIndex(p[0xf78+i]);
                if(!obj)continue;
                unsigned char *q=*(unsigned char **)(obj+0x130);
                if(*(int *)q&1)continue;
                if(*(unsigned short *)(q+4))count++;
            }
        }return count!=1;
    }
}
