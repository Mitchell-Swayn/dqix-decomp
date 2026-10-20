#include <globaldefs.h>
#include <System/Memory.h>
ARM
extern "C" unsigned char NetworkBroadcastArpRequest_UnknownRoleZeroInitializedStorage[];
extern "C" unsigned char NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[];
extern "C" void ProcessBufferAfterSixByteHeader(void*,int,int,int);
inline unsigned short SwapHalfword(int value) { return (value >> 8) | (value << 8); }
struct ArpFrame { unsigned char destination[6], source[6]; unsigned short etherType; unsigned char hardwareType[2], protocolType[2]; unsigned short lengths; unsigned char operation[2], sender[6]; unsigned short sourceAddress[2]; unsigned char target[6]; unsigned short targetAddress[2]; };
// Original: arm9/ov031 @ 0x02200CCC; symbol: Network_BroadcastArpRequest; size: 0xFC.
// Sends a 42-byte broadcast ARP request for the supplied IPv4 address.
extern "C" void Network_BroadcastArpRequest(unsigned address) {
    ArpFrame frame;
    VectorizedMemset(&frame,0,42);
    VectorizedMemset(&frame,255,6);
    MI_CpuCopy8(NetworkBroadcastArpRequest_UnknownRoleZeroInitializedStorage,frame.source,6);
    frame.etherType=0x608;
    frame.hardwareType[1]=1;
    frame.operation[1]=1;
    frame.protocolType[0]=8;
    frame.lengths=0x406;
    MI_CpuCopy8(NetworkBroadcastArpRequest_UnknownRoleZeroInitializedStorage,frame.sender,6);
    unsigned source=*(unsigned*)(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage+0x50);
    unsigned short sourceHigh=source>>16;
    unsigned short sourceLow=source;
    unsigned short targetHigh=address>>16;
    unsigned short targetLow=address;
    frame.sourceAddress[0]=SwapHalfword(sourceHigh);
    frame.sourceAddress[1]=SwapHalfword(sourceLow);
    frame.targetAddress[0]=SwapHalfword(targetHigh);
    frame.targetAddress[1]=SwapHalfword(targetLow);
    ProcessBufferAfterSixByteHeader(&frame,42,0,0);
}
