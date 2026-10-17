#include <globaldefs.h>
ARM
struct Object;
struct Record { unsigned char type; unsigned char pad[3]; unsigned char index; char text[15]; };
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" void* ReadGlobalAt02100044(void);
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" unsigned char* ClearAndDecodeTwelveByteField141(unsigned char*);
extern "C" char* strcpy(char*, const char*);
extern "C" void MoveQueuedRecordAndApplySourceValue(Object*, const void*, short);
// Original: arm9/ov017 @ 0x021C45B4; symbol: func_ov017_021c45b4; size: 0x64.
extern "C" void GameState_QueueDecodedObjectName(unsigned index) {
    void* state = _ZN9GameState11GetInstanceEv();
    Object* target = (Object*)ReadGlobalAt02100044();
    void* object = GameState_GetObjectWithFlag100(state, index);
    if (!object) return;
    Record record;
    record.type = 3;
    record.index = (unsigned char)index;
    strcpy(record.text, (char*)ClearAndDecodeTwelveByteField141((unsigned char*)object));
    MoveQueuedRecordAndApplySourceValue(target, &record, 0);
}
