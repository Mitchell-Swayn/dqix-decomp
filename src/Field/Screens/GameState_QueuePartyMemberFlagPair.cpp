#include <globaldefs.h>
ARM
class GameState; class Object3D; struct GameResources; struct Object;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" Object3D* _ZN9GameState21GetPartyMemberByIndexEi(GameState*, int);
extern "C" void* Network_GetCommandRecordPool();
extern "C" unsigned char *GameObject_GetLinkedIndexedState(void *);
extern "C" void Network_QueueOutgoingRecord(Object* object,const void* source,short value);
extern "C" GameResources* GameResources_GetInstance();
extern "C" unsigned int Field_TestPartyMemberMessageFlag(void *object, unsigned int bit);
struct Payload { unsigned char index; unsigned char resourceFlag : 1; unsigned char testedFlag : 1; unsigned char reserved : 6; char pad[14]; };
struct Record { unsigned char type; char pad[3]; Payload payload; };
// Original: arm9/ov017 @ 0x021D25F4; symbol: func_ov017_021d25f4; size: 0xB0.
extern "C" void GameState_QueuePartyMemberFlagPair(int index) {
    GameResources *resources = GameResources_GetInstance();
    Object *queue = (Object *)Network_GetCommandRecordPool();
    Record record;
    record.type = 0x20;
    Payload *payload = &record.payload;
    GameState *state = (GameState *)_ZN9GameState11GetInstanceEv();
    if (state) {
        Object3D *object = _ZN9GameState21GetPartyMemberByIndexEi(state,index);
        if (object) {
            unsigned char *resource = GameObject_GetLinkedIndexedState(object);
            if (resource) {
                payload->index = index;
                payload->resourceFlag = resource[0x56c];
                payload->testedFlag = Field_TestPartyMemberMessageFlag(resources,index) != 0;
                Network_QueueOutgoingRecord(queue,&record,0);
            }
        }
    }
}
