#include <globaldefs.h>
#include <System/Memory.h>
ARM
struct State;
extern "C" {
void Ssl_ComputeFinishedMd5(unsigned char* p, void* output, unsigned mode);
void Ssl_ComputeFinishedSha1(unsigned char* p, void* output, unsigned mode);
void Util_UpdateObjectHashContexts(void* self, unsigned int a, unsigned int b);
int Ssl_AuthenticateAndEncryptRecord(void* object, void* buffer);
unsigned Network_SendTwoBuffersWithTimeout(char* first, unsigned firstSize, char* second, unsigned secondSize, State* state);
extern void* (*SslSendClientHello_UnknownRoleZeroInitializedStorage)(unsigned);
extern void (*SslSendClientHello_UnknownRoleZeroInitializedStorage_Variant2)(void*);
}
// Original: arm9/ov031 @ 0x02209E98; symbol: Ssl_SendChangeCipherSpecAndFinished; size: 0x158.
// Sends a ChangeCipherSpec record followed by the encrypted Finished handshake message
// (SSL 3.0; MD5 and SHA-1 finished hashes computed over copies of the running contexts).
extern "C" void Ssl_SendChangeCipherSpecAndFinished(char* self) {
    unsigned char* context = *(unsigned char**)(self + 0x0c);
    unsigned char* packet = (unsigned char*)SslSendClientHello_UnknownRoleZeroInitializedStorage(0x83);
    if (!packet) { context[0x455] = 9; return; }
    packet[0] = 0x14; packet[1] = 3; packet[2] = 0; packet[3] = 0; packet[4] = 1; packet[5] = 1;
    VectorizedMemset(context + 0x1cc, 0, 8);
    packet[6] = 0x16; packet[7] = 3; packet[8] = 0; packet[9] = 0;
    packet[10] = 0x28; packet[11] = 0x14; packet[12] = 0; packet[13] = 0; packet[14] = 0x24;
    MI_CpuCopy8(context + 0x3a4, context + 0x3fc, 0x58);
    Ssl_ComputeFinishedMd5(context, packet + 0x0f, 0);
    MI_CpuCopy8(context + 0x3fc, context + 0x3a4, 0x58);
    MI_CpuCopy8(context + 0x2ec, context + 0x348, 0x5c);
    Ssl_ComputeFinishedSha1(context, packet + 0x1f, 0);
    MI_CpuCopy8(context + 0x348, context + 0x2ec, 0x5c);
    Util_UpdateObjectHashContexts(context, (unsigned)(packet + 0x0b), 0x28);
    unsigned size = (unsigned)Ssl_AuthenticateAndEncryptRecord(context, packet + 6);
    Network_SendTwoBuffersWithTimeout((char*)packet, size + 6, 0, 0, (State*)self);
    SslSendClientHello_UnknownRoleZeroInitializedStorage_Variant2(packet);
}
