struct WirelessEvent {
    unsigned short reserved0, error;
    unsigned short reserved4[2];
    unsigned short code;
    unsigned short reservedA[3];
    unsigned short peer;
};
struct WirelessState {
    unsigned short reserved0[5];
    unsigned short peerMask;
    unsigned int reservedC;
    int state;
    unsigned int reserved14;
    void (*eventCallback)(WirelessEvent*);
    unsigned int reserved1C[2];
    int (*acceptPeer)(WirelessEvent*);
    unsigned int reserved28;
    unsigned int firstLength;
    unsigned int reserved30[2];
    unsigned int secondLength;
};
extern "C" WirelessState data_021015a0;
extern "C" char data_02101f80[], data_021017a0[];
extern "C" void func_0202cb50(WirelessEvent*);
extern "C" void SetGlobalValueExceptModesNineAndTen(unsigned int error);
extern "C" int ValidateSlotAgainstSharedMaskAndSubmit(void (*callback)(WirelessEvent*), unsigned int peer);
extern "C" int BuildModeThreeHalfwordPairAndDispatchRequest(void (*callback)(WirelessEvent*), void*, unsigned int, void*, unsigned int, unsigned int);
// Original: arm9/main @ 0x0202C9AC; symbol: func_0202c9ac; size: 0x1A4.
extern "C" void Network_HandlePeerJoinLeaveAndStartEvents(WirelessEvent* event)
{
    unsigned int error;
    unsigned short peerMask;
    peerMask = 1 << event->peer;
    error = event->error;
    if (error) {
        SetGlobalValueExceptModesNineAndTen(error);
        data_021015a0.state = 9;
    } else {
        int code = event->code;
        switch (code) {
        case 7:
            if (data_021015a0.acceptPeer && !data_021015a0.acceptPeer(event)) {
                int result = ValidateSlotAgainstSharedMaskAndSubmit(0, event->peer);
                if (result != 2) {
                    SetGlobalValueExceptModesNineAndTen(result);
                    data_021015a0.state = 9;
                }
            } else {
                data_021015a0.peerMask |= peerMask;
                if (data_021015a0.eventCallback) data_021015a0.eventCallback(event);
            }
            break;
        case 9:
            data_021015a0.peerMask &= ~peerMask;
            if (data_021015a0.eventCallback) data_021015a0.eventCallback(event);
            break;
        case 0: {
            bool success;
            if (data_021015a0.state == 4 || data_021015a0.state == 6 || data_021015a0.state == 5) {
                success = true;
            } else {
                data_021015a0.state = 4;
                int result = BuildModeThreeHalfwordPairAndDispatchRequest(func_0202cb50, data_02101f80,
                    (unsigned short)data_021015a0.firstLength, data_021017a0,
                    (unsigned short)data_021015a0.secondLength, 1);
                if (result == 2) success = true;
                else { SetGlobalValueExceptModesNineAndTen(result); success = false; }
            }
            if (!success) data_021015a0.state = 9;
            break;
        }
        case 2: break;
        case 26: break;
        }
    }
}
