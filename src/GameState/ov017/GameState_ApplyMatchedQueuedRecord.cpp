#include <globaldefs.h>
ARM
extern "C" void EnableField55F4Bits(unsigned char* p,unsigned int bits);
struct Record { unsigned short id; unsigned short value : 15; unsigned short reserved : 1; unsigned char mode; signed char field; };
extern "C" void func_ov000_021633b8(void *, const Record *);
extern "C" void SetByteAt5901AndFlag8000At55F4(void *, int);
extern "C" void* OV017_ReadWordField6AC(void*);
extern "C" void* OV017_GetEmbeddedField1C(void*);
// Original: arm9/ov017 @ 0x021CD424; symbol: func_ov017_021cd424; size: 0xA4.
extern "C" void GameState_ApplyMatchedQueuedRecord(void *unused0, unsigned char *input, int unused2, char *context) {
    void *object = *(void **)(context + 0x3718);
    char *header = (char *)OV017_GetEmbeddedField1C(object);
    if (*(unsigned short *)(header + 8) == *(unsigned short *)(input + 4)) {
        unsigned char *state = (unsigned char *)OV017_ReadWordField6AC(object);
        if (state) {
            Record record;
            record.id = *(unsigned short *)(input + 6);
            record.value = *(unsigned short *)(input + 8);
            record.mode = input[11];
            record.field = *(signed char *)(input + 12);
            func_ov000_021633b8(state, &record);
            int value = *(signed char *)(input + 10);
            if (value >= 0) SetByteAt5901AndFlag8000At55F4(state, value);
            EnableField55F4Bits(state, 0x8000);
        }
    }
}
