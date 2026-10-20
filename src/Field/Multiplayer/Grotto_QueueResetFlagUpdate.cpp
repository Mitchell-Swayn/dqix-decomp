#include <globaldefs.h>
ARM
extern "C" void* Network_GetConnectionManager();
extern "C" bool Network_IsClientSession(unsigned int*);
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void*, const void*, short);
// Original: arm9/ov017 @ 0x021CFCEC; symbol: func_ov017_021cfcec; size: 0x40.
extern "C" void Grotto_QueueResetFlagUpdate(unsigned char value) {
    if (!Network_IsClientSession((unsigned int*)Network_GetConnectionManager())) {
        char record[0x14];
        void* object = Network_GetCommandRecordPool();
        *(unsigned char*)record = 0xa3;
        record[4] = (char)value;
        Network_QueueOutgoingRecord(object, record, 0);
    }
}
