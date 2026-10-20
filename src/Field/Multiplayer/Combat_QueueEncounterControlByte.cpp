#include <globaldefs.h>
ARM
// If the embedded field returned for the game resource is present, queues a 0x5b record containing its halfword at +8 and the input byte; the object comes from ReadGlobalAt02100044.
// Original: arm9/ov017 @ 0x021CA2F8; symbol: QueueEmbeddedResourceFieldAndInputByte; size: 0x60.
#pragma optimization_level 3
extern "C" void *Network_GetCommandRecordPool();
extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" void *GameResources_GetInstance();
extern "C" void *FieldBattle_GetEncounterRequest(void *);
extern "C" void Network_QueueOutgoingRecord(void *, const void *, short);
struct Payload { unsigned short field; unsigned char value; };
struct QueueRecord { unsigned char type; unsigned char pad[3]; Payload payload; unsigned char padding[0xc]; };

extern "C" void Combat_QueueEncounterControlByte(unsigned char value) {
    void *object = Network_GetCommandRecordPool();
    _ZN9GameState11GetInstanceEv();
    unsigned char *resources = (unsigned char *)GameResources_GetInstance() + 0x3000;
    void *embedded = FieldBattle_GetEncounterRequest(*(void **)(resources + 0x718));
    if (embedded != 0) {
        QueueRecord record;
        record.type = 0x5b;
        Payload *payload = &record.payload;
        payload->field = *(unsigned short *)((unsigned char *)embedded + 8);
        payload->value = value;
        Network_QueueOutgoingRecord(object, &record, 0);
    }
}
