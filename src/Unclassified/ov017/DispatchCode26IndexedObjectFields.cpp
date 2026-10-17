#include <globaldefs.h>
extern "C" void* ReadGlobalAt02100044();
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_FindIndexedObjectWithFlag1000(void*, int);
extern "C" unsigned char ReadFieldAtOffset2D0(void*);
extern "C" unsigned char ReadWordAtOffset2D1(void*);
extern "C" unsigned char ReadWordAtOffset1C8(void*);
extern "C" unsigned char Object_ReadCharAtOffset1C9(void*);
extern "C" void MoveQueuedRecordAndApplySourceValue(void*, const void*, short);
struct Code26Message { unsigned char tag; unsigned char pad[3]; unsigned short index; unsigned char fields[5]; unsigned char tail[9]; };
// The five payload bytes are described by their source offsets; their meaning is unresolved.
// Original: arm9/ov017 @ 0x021ce32c; symbol: func_ov017_021ce32c; size: 0x80.
extern "C" void DispatchCode26IndexedObjectFields(unsigned short index) {
    void* queue = ReadGlobalAt02100044();
    void* state = _ZN9GameState11GetInstanceEv();
    unsigned char* object = (unsigned char*)GameState_FindIndexedObjectWithFlag1000(state, index);
    if (!object) return;
    Code26Message message;
    message.tag = 0x26;
    message.index = index;
    message.fields[0] = ReadFieldAtOffset2D0(object);
    message.fields[1] = ReadWordAtOffset2D1(object);
    message.fields[2] = ReadWordAtOffset1C8(object);
    message.fields[3] = Object_ReadCharAtOffset1C9(object);
    message.fields[4] = object[0x2d2];
    MoveQueuedRecordAndApplySourceValue(queue, &message, 0);
}
