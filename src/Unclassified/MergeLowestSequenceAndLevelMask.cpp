#include <globaldefs.h>

struct Request {
    unsigned short unknown_0;
    unsigned short error;
    unsigned char unknown_4[4];
    unsigned short level;
    unsigned short sequence;
};

struct State {
    unsigned char unknown_0[6];
    unsigned short sequence;
    unsigned char unknown_8[4];
    unsigned short levelMask;
    unsigned char unknown_e[2];
    int status;
};

extern "C" State data_021015a0;
extern "C" {
void SetGlobalValueExceptModesNineAndTen(unsigned short error);
int Network_SelectAvailableChannelAndStartRequest(unsigned short level);
}

// Original: arm9/main @ 0x0202D840; symbol: func_0202d840; size: 0xA8.
extern "C" ARM void MergeLowestSequenceAndLevelMask(Request* req) {
    if (req->error) {
        SetGlobalValueExceptModesNineAndTen(req->error);
        data_021015a0.status = 9;
        return;
    }
    unsigned short sequence = req->sequence;
    unsigned short level = req->level;
    if (data_021015a0.sequence > sequence) {
        data_021015a0.sequence = sequence;
        data_021015a0.levelMask = 1 << (level - 1);
    } else if (data_021015a0.sequence == sequence) {
        data_021015a0.levelMask |= 1 << (level - 1);
    }
    int result = Network_SelectAvailableChannelAndStartRequest(level + 1);
    if (result == 0x18) {
        data_021015a0.status = 7;
        return;
    }
    if (result != 2) data_021015a0.status = 9;
}
