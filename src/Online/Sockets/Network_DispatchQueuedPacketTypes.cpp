#include <globaldefs.h>
ARM
extern "C" unsigned char* Network_WaitForReceivedEthernetFrame(unsigned int* length);
extern "C" void Network_ConsumeReceivedEthernetFrame();
extern "C" void Network_ValidateAndDispatchIpv4Packet(unsigned char*, unsigned);
extern "C" void Network_ProcessReceivedArpPacket(unsigned char*, unsigned);
// Original: arm9/ov031 @ 0x02203008; symbol: Network_DispatchQueuedPacketTypes; size: 0x70.
// Repeatedly consumes packets and dispatches payloads for byte-swapped types 0x0800 or 0x0806 when long enough.
extern "C" void Network_DispatchQueuedPacketTypes() {
    const unsigned int expected = 0x806;
    for (;;) {
        unsigned int length;
        unsigned char* packet = Network_WaitForReceivedEthernetFrame(&length);
        if (length > 0x22) {
            int encoded = *(unsigned short*)(packet + 0xc);
            int left = encoded << 8;
            int right = encoded >> 8;
            unsigned short type = (unsigned short)(right | left);
            switch (type) {
            case 0x800: Network_ValidateAndDispatchIpv4Packet(packet + 0xe, length - 0xe); break;
            case 0x806: Network_ProcessReceivedArpPacket(packet + 0xe, length - 0xe); break;
            }
        }
        Network_ConsumeReceivedEthernetFrame();
    }
}
