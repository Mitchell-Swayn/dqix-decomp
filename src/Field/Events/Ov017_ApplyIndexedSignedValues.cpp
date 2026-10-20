#include <globaldefs.h>
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetIndexList(void*);
extern "C" void Field_QueueMemberPresenceToken(int, void*);
// Original: arm9/ov017 @ 0x021C3F70; symbol: func_ov017_021c3f70; size: 0x44.
extern "C" ARM void Ov017_ApplyIndexedSignedValues(void* object) {
    void* state = _ZN9GameState11GetInstanceEv();
    unsigned char* list = (unsigned char*)GameState_GetIndexList(state);
    for (int i = 0; i < list[0xf7c]; ++i)
        Field_QueueMemberPresenceToken(*(signed char*)(list + 0xf78 + i), object);
}
