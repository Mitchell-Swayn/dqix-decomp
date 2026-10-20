#include <globaldefs.h>
ARM
extern "C" void* Network_GetConnectionManager();
extern "C" int Network_IsSessionActive(void*);
extern "C" bool Network_IsClientSession(unsigned int*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void*, const void*, short);
// Original: arm9/ov017 @ 0x021CFABC; symbol: func_ov017_021cfabc; size: 0x50.
extern "C" void Grotto_QueueClientExitRequest(void) {
    void* state = Network_GetConnectionManager();
    if (Network_IsSessionActive(state) && !Network_IsClientSession((unsigned int*)state)) {
        char record[0x14];
        _ZN9GameState11GetInstanceEv();
        void* object = Network_GetCommandRecordPool();
        *(unsigned char*)record = 0xa1;
        Network_QueueOutgoingRecord(object, record, 0);
    }
}
