#include <globaldefs.h>
ARM
// Original: arm9/ov031:022053a0; Dispatches record processing by its signed state byte, sets record halfword +0x70, and returns zero.
extern "C" void Network_AttachSocketToCurrentThread(void*);
extern "C" void Network_EnableUdpSocketMode(void);
extern "C" void Network_InitializeCurrentThreadSocket(void);
extern "C" void Network_ShareCurrentSocketWithThread(void*);
extern "C" void Network_SetUdpReceiveCallback(unsigned int);
extern "C" void Network_QueueReceivedDatagram(void);
extern "C" int Network_InitializeSocketProtocol(void* self) {
    char* record = *(char**)((char*)self + 4);
    Network_AttachSocketToCurrentThread(record);
    signed char state = *(signed char*)(record + 0x73);
    char* value = *(char**)(record + 0x68);
    
    switch (state) {
    case 0:
    case 4:
        Network_ShareCurrentSocketWithThread(value + 0x20);
        Network_InitializeCurrentThreadSocket();
        break;
    case 1:
        Network_InitializeCurrentThreadSocket();
        Network_EnableUdpSocketMode();
        Network_SetUdpReceiveCallback((unsigned)&Network_QueueReceivedDatagram);
        break;
    case 2:
        Network_EnableUdpSocketMode();
        break;
    case 3:
        break;
    default:
        break;
    }
    *(unsigned short*)(record + 0x70) = 1;
    return 0;
}
