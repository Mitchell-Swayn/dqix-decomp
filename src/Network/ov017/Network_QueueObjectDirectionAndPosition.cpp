#include <globaldefs.h>
ARM
struct Object;
extern "C" void* ReadGlobalAt02100044();
extern "C" void MoveQueuedRecordAndApplySourceValue(Object* object,const void* source,short value);
struct Position { int x,y,z; };
struct Request { unsigned char type; char pad[3]; unsigned short id; unsigned char action : 6; unsigned char reserved : 2; unsigned char mode : 4; signed char target : 4; short angle,y; int x,z; };
// Original: arm9/ov017 @ 0x021C927C; symbol: func_ov017_021c927c; size: 0xB8.
extern "C" void Network_QueueObjectDirectionAndPosition(unsigned id, int mode, int unused, Position position, int angle, unsigned short action, int target) {
    Object *queue = (Object*)ReadGlobalAt02100044();
    Request request;
    request.type = 0x88;
    request.id = id;
    request.mode = (unsigned char)mode;
    request.target = (signed char)target;
    request.action = (unsigned char)action;
    request.x = position.x;
    request.y = position.y >> 4;
    request.z = position.z;
    request.angle = angle;
    MoveQueuedRecordAndApplySourceValue(queue, &request, 0);
}
