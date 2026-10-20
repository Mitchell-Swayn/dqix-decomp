#include <globaldefs.h>
ARM
extern "C" int ContainsKeyInRelativeEightByteRecordTable(void*,int);
extern "C" void Script_StartArchiveEntry(void*,int);
extern "C" void GameState_ProcessPendingOperationIfPresent(void*);
struct State {char pad[12];char object[60];int flag;char pad4c[20];int pending,current;};
// Original: arm9/main @ 0x0209FF6C; symbol: func_0209ff6c; size: 0x74.
extern "C" void ScriptListContext_UpdateExecution(State* p) {
    if(p->pending>=0) {
        if(!ContainsKeyInRelativeEightByteRecordTable(p->object,p->pending)){p->pending=-1;return;}
        Script_StartArchiveEntry(p->object,p->pending);
        p->current=p->pending;p->pending=-1;return;
    }
    if(p->current<0)return;
    GameState_ProcessPendingOperationIfPresent(p->object);
    if(p->flag)p->current=-1;
}
