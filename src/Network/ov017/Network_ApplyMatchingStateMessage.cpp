#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" int ReadIndexedSignedField1038(char* p);
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(void*);
extern "C" void Network_QueueSelectedSourceAndDayTimer(unsigned,int);
extern "C" void QueueDayTimerMessage93();
extern "C" void Network_QueueGrottoStateRecord(char type,unsigned char flag);
struct Message { char pad[4]; unsigned char index : 4; unsigned char type : 4; char pad5[3]; unsigned flags; };
// Original: arm9/ov017 @ 0x021CD9E8; symbol: func_ov017_021cd9e8; size: 0xB4.
extern "C" void Network_ApplyMatchingStateMessage(void *unused0, Message *message, void *state, int unused3, char *connection) {
    if (ReadIndexedSignedField1038(connection) != message->index) return;
    if (message->flags & 1) QueueDayTimerMessage93();
    if (message->flags & 0x20) Network_QueueGrottoStateRecord((char)message->type,0);
    int id = -1;
    if (message->flags & 0x10) {
        void *object = _ZN9GameState20GetGameObjectByIndexEi(state,ReadIndexedSignedField1038(connection));
        if (object) id = _ZNK8Object3D10GetField06Ev(object);
    }
    if (message->flags & 4) Network_QueueSelectedSourceAndDayTimer(message->type,id);
}
