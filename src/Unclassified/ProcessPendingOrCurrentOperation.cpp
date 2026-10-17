#include <globaldefs.h>
ARM
extern "C" int func_ov017_021d4df8(void*,int);
extern "C" void func_ov017_021d4ce4(void*,int);
extern "C" void GameState_ProcessPendingOperationIfPresent(void*);
struct State {char pad[16];char object[60];int flag;char pad50[20];int pending,current;};
// Original: arm9/main @ 0x0209FE18; symbol: func_0209fe18; size: 0x74.
extern "C" void ProcessPendingOrCurrentOperation(State* p) {
    if(p->pending>=0) {
        if(!func_ov017_021d4df8(p->object,p->pending)){p->pending=-1;return;}
        func_ov017_021d4ce4(p->object,p->pending);
        p->current=p->pending;p->pending=-1;return;
    }
    if(p->current<0)return;
    GameState_ProcessPendingOperationIfPresent(p->object);
    if(p->flag)p->current=-1;
}
