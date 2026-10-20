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

// Original data: arm9/main @ 0x21015a0; symbol: data_021015a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" State NetworkGetAssociationId_UnknownRoleZeroInitializedStorage;
extern "C" {
void Network_RecordWirelessErrorUnlessTerminal(unsigned short error);
int Network_SelectAvailableChannelAndStartRequest(unsigned short level);
}

// Original: arm9/main @ 0x0202D840; symbol: func_0202d840; size: 0xA8.
extern "C" ARM void Network_AccumulateLeastBusyChannels(Request* req) {
    if (req->error) {
        Network_RecordWirelessErrorUnlessTerminal(req->error);
        NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.status = 9;
        return;
    }
    unsigned short sequence = req->sequence;
    unsigned short level = req->level;
    if (NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.sequence > sequence) {
        NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.sequence = sequence;
        NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.levelMask = 1 << (level - 1);
    } else if (NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.sequence == sequence) {
        NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.levelMask |= 1 << (level - 1);
    }
    int result = Network_SelectAvailableChannelAndStartRequest(level + 1);
    if (result == 0x18) {
        NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.status = 7;
        return;
    }
    if (result != 2) NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.status = 9;
}
