#include <globaldefs.h>
ARM
extern "C" void Graphics_InitializeDisplayStateRecord(unsigned char*);
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned*, unsigned);
// Original: arm9/ov017 @ 0x021AA4CC; symbol: func_ov017_021aa4cc; size: 0x40.
extern "C" void FieldRecovery_QueuePromptIfIdle(void* object, unsigned char value) {
    unsigned char* request = *(unsigned char**)((char*)object + 0x3b0c);
    if (request[2] != 0)
        return;
    Graphics_InitializeDisplayStateRecord(request);
    unsigned char* base = (unsigned char*)object + 0x3000;
    *(unsigned char*)(*(unsigned char**)(base + 0xb0c) + 0x5c) = value;
    LinkedQueue_AppendAndMarkActive(*(unsigned**)(base + 0x6fc), (unsigned)*(unsigned char**)(base + 0xb0c));
}
