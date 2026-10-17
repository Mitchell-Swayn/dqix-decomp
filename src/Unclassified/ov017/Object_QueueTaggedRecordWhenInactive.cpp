#include <globaldefs.h>
ARM
extern "C" void* Object_GetGlobalConnectionState();
extern "C" bool TestActiveWordAndGlobalStateNonzero(unsigned int*);
extern "C" void* ReadGlobalAt02100044();
extern "C" void MoveQueuedRecordAndApplySourceValue(void*, const void*, short);
// Original: arm9/ov017 @ 0x021CFCEC; symbol: func_ov017_021cfcec; size: 0x40.
extern "C" void Object_QueueTaggedRecordWhenInactive(unsigned char value) {
    if (!TestActiveWordAndGlobalStateNonzero((unsigned int*)Object_GetGlobalConnectionState())) {
        char record[0x14];
        void* object = ReadGlobalAt02100044();
        *(unsigned char*)record = 0xa3;
        record[4] = (char)value;
        MoveQueuedRecordAndApplySourceValue(object, record, 0);
    }
}
