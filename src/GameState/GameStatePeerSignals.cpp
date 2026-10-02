#pragma always_inline on
#include "GameState/GameState.h"

#if defined(usa)

struct PeerSignalBody {
    unsigned char target_ : 7;
    unsigned char reply_ : 1;
    unsigned char mode_;
    char unknown_02_[14];
    inline void Configure(int target, bool reply, int mode) {
        target_ = target;
        reply_ = reply;
        mode_ = mode;
    }
};

struct PeerSignalPacket {
    unsigned char kind_;
    char unknown_01_[3];
    PeerSignalBody body_;
};

typedef char PeerSignalSizeCheck[sizeof(PeerSignalPacket) == 20 ? 1 : -1];
typedef char PeerSignalModeOffsetCheck[
    offsetof(PeerSignalPacket, body_) == 4 &&
    offsetof(PeerSignalBody, mode_) == 1 ? 1 : -1];

extern "C" void* func_0202ae24();
extern "C" void func_0205e330(void* connection, const void* packet,
                                unsigned int flags);
extern "C" int func_0202c1a4(void* connection);
extern "C" bool func_0202b7d8(void* connection);
extern "C" void func_020ac4f8(bool value);
extern "C" void func_ov017_021d1118(int objectIndex, unsigned char flags,
                                      int value, int selector);
extern "C" void* func_020936f8();
extern "C" void func_02094030(void* object, int value, int unknown,
                                signed char objectIndex);

extern "C" void func_ov017_021d1014(int target, bool reply, int mode)
{
    void* connection = func_0202ae24();
    // Only these fields are assigned in the release; other packet bytes retain
    // their stack contents. The sender's stronger framing contract is unknown.
    PeerSignalPacket packet;
    packet.kind_ = 0x19;
    PeerSignalBody* body = &packet.body_;
    body->Configure(target, reply, mode);
    func_0205e330(connection, &packet, 0);
}

extern "C" void func_ov017_021d1078(int objectIndex, const PeerSignalPacket* packet,
                                     GameState*, void*, void* connection)
{
    int target = func_0202c1a4(connection);
    if (!packet->body_.reply_) {
        if (target != packet->body_.target_)
            return;
        func_020ac4f8(func_0202b7d8(connection) != 0);
        func_ov017_021d1118(objectIndex, 0xff, 0, 0);
        void* object = func_020936f8();
        func_02094030(object, 20000, -1, (signed char)objectIndex);
    } else {
        unsigned char flags = 1;
        if (packet->body_.mode_ == 1)
            flags |= 4;
        func_ov017_021d1118(objectIndex, flags, 1, packet->body_.mode_);
    }
}

#endif
