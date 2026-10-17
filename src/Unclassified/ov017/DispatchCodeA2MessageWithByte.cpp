#include <globaldefs.h>
extern "C" void* Object_GetGlobalConnectionState();
extern "C" int TestActiveWordAndGlobalStateNonzero(void*);
extern "C" void* ReadGlobalAt02100044();
extern "C" void MoveQueuedRecordAndApplySourceValue(void*, const void*, short);
struct CodeA2Message { unsigned char tag; unsigned char pad[3]; unsigned char value; unsigned char tail[15]; };
// The message byte's meaning is unresolved.
// Original: arm9/ov017 @ 0x021cfc74; symbol: func_ov017_021cfc74; size: 0x40.
extern "C" void DispatchCodeA2MessageWithByte(unsigned char value) {
    void* connection = Object_GetGlobalConnectionState();
    if (TestActiveWordAndGlobalStateNonzero(connection)) return;
    void* queue = ReadGlobalAt02100044();
    CodeA2Message message;
    message.tag = 0xa2;
    message.value = value;
    MoveQueuedRecordAndApplySourceValue(queue, &message, 0);
}
