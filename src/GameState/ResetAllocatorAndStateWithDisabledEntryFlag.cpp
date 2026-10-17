#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
extern "C" void ClearRecordAndInvalidateTwoIndices(void*);
extern "C" unsigned char* GameState_GetIndexList(GameState*);
struct State {
    SafeAllocator allocator;
    char pad[0x2c-sizeof(SafeAllocator)];
    int id;
    short code, value;
    unsigned char a,b,c,flags,kind,d,e,f;
};
// Original: arm9/main @ 0x02092AA4; symbol: func_02092aa4; size: 0x90.
extern "C" void ResetAllocatorAndStateWithDisabledEntryFlag(State* p,unsigned char kind) {
    p->allocator.ResetAllocatorPointer();
    ClearRecordAndInvalidateTwoIndices((char*)p+0x14);
    p->id=-1; p->code=-1; p->value=0;
    p->a=0; p->b=0; p->c=0; p->flags=0;
    p->kind=kind; p->d=0; p->e=0; p->f=0;
    unsigned char* list=GameState_GetIndexList(GameState::GetInstance());
    for(unsigned char i=0;i<list[0xf7c];i++) {
        if(!(list+i)[0xf78]) {p->flags|=1;return;}
    }
}
