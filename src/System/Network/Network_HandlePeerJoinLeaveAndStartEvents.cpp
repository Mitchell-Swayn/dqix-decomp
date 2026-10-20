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
// Original data: arm9/main @ 0x21015a0; symbol: data_021015a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" WirelessState NetworkGetAssociationId_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x21017a0; symbol: data_021017a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 480 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2101f80; symbol: data_02101f80.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1088 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char NetworkHandleClientConnectionEvents_UnknownRoleZeroInitializedStorage_Variant2[], NetworkHandleClientConnectionEvents_UnknownRoleZeroInitializedStorage[];
extern "C" void Network_HandleParentMultiplayerCallback(WirelessEvent*);
extern "C" void Network_RecordWirelessErrorUnlessTerminal(unsigned int error);
extern "C" int ValidateSlotAgainstSharedMaskAndSubmit(void (*callback)(WirelessEvent*), unsigned int peer);
extern "C" int WM_StartMP(void (*callback)(WirelessEvent*), void*, unsigned int, void*, unsigned int, unsigned int);
// Original: arm9/main @ 0x0202C9AC; symbol: func_0202c9ac; size: 0x1A4.
extern "C" void Network_HandlePeerJoinLeaveAndStartEvents(WirelessEvent* event)
{
    unsigned int error;
    unsigned short peerMask;
    peerMask = 1 << event->peer;
    error = event->error;
    if (error) {
        Network_RecordWirelessErrorUnlessTerminal(error);
        NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.state = 9;
    } else {
        int code = event->code;
        switch (code) {
        case 7:
            if (NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.acceptPeer && !NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.acceptPeer(event)) {
                int result = ValidateSlotAgainstSharedMaskAndSubmit(0, event->peer);
                if (result != 2) {
                    Network_RecordWirelessErrorUnlessTerminal(result);
                    NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.state = 9;
                }
            } else {
                NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.peerMask |= peerMask;
                if (NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.eventCallback) NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.eventCallback(event);
            }
            break;
        case 9:
            NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.peerMask &= ~peerMask;
            if (NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.eventCallback) NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.eventCallback(event);
            break;
        case 0: {
            bool success;
            if (NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.state == 4 || NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.state == 6 || NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.state == 5) {
                success = true;
            } else {
                NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.state = 4;
                int result = WM_StartMP(Network_HandleParentMultiplayerCallback, NetworkHandleClientConnectionEvents_UnknownRoleZeroInitializedStorage_Variant2,
                    (unsigned short)NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.firstLength, NetworkHandleClientConnectionEvents_UnknownRoleZeroInitializedStorage,
                    (unsigned short)NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.secondLength, 1);
                if (result == 2) success = true;
                else { Network_RecordWirelessErrorUnlessTerminal(result); success = false; }
            }
            if (!success) NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.state = 9;
            break;
        }
        case 2: break;
        case 26: break;
        }
    }
}
