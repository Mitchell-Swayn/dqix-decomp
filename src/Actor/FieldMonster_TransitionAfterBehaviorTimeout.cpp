#include <globaldefs.h>
ARM
extern "C" void* Network_GetConnectionManager();extern "C" int Network_IsSessionActive(void*);extern "C" int Network_GetLocalMemberId(void*);
extern "C" int Object_InvokeStateMethodAndRecordSuccessfulTransition(char*,unsigned);extern "C" unsigned short Object_SelectAvailableRandomChoiceAndUpdateIndex(char*,unsigned char*);
// Original: arm9/main @ 0x02078D84; symbol: func_02078d84; size: 0xDC.
extern "C" void FieldMonster_TransitionAfterBehaviorTimeout(char* p){
    void* state=Network_GetConnectionManager();if(Network_IsSessionActive(state)&&Network_GetLocalMemberId(state))return;
    if(*(unsigned*)(p+0x14c)<=3000)return;
    unsigned char local=0;
    switch(*(unsigned char*)(p+0x138)){
    case 0:Object_InvokeStateMethodAndRecordSuccessfulTransition(p,1);return;
    case 1:case 3:case 4:case 5:
        if(!Object_InvokeStateMethodAndRecordSuccessfulTransition(p,2)){*(unsigned short*)(p+0x164)=Object_SelectAvailableRandomChoiceAndUpdateIndex(p,&local);Object_InvokeStateMethodAndRecordSuccessfulTransition(p,2);}return;
    case 2:*(unsigned short*)(p+0x164)=Object_SelectAvailableRandomChoiceAndUpdateIndex(p,&local);Object_InvokeStateMethodAndRecordSuccessfulTransition(p,3);return;
    }
}
