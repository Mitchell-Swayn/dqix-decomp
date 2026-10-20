#include <globaldefs.h>
ARM
#pragma optimization_level 4
struct Position { int x,y,z; };
extern "C" void* Network_GetCommandRecordPool();
struct Object;
extern "C" void Network_QueueOutgoingRecord(Object* object,const void* source,short value);
struct Request { unsigned char type; Position position; unsigned short zone; unsigned char flag1 : 1; unsigned char flag2 : 1; unsigned char reserved : 6; signed char value; };
// Original: arm9/ov017 @ 0x021CF3C0; symbol: func_ov017_021cf3c0; size: 0x88.
extern "C" void GameState_QueuePositionAndZoneRequest(Position position, unsigned short zone, unsigned char flag1, unsigned char flag2, signed char value) {
    Object *object = (Object*)Network_GetCommandRecordPool();
    Request request;
    request.type = 0x38;
    request.position.x = position.x;
    request.position.y = position.y;
    request.position.z = position.z;
    request.zone = zone;
    request.flag1 = flag1;
    request.flag2 = flag2;
    request.value = value;
    Network_QueueOutgoingRecord(object, &request, 0);
}
