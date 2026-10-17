#include <globaldefs.h>
ARM
extern "C" void VectorizedMemset(void* dst, int value, unsigned int length);
extern "C" int CopyReadyIndexedByteRecord(int,void*);
extern "C" char *data_ov031_0224e5d8;
struct Record { int active; char payload[116]; };
// Original: arm9/ov031 @ 0x0221624C; symbol: func_ov031_0221624c; size: 0xA4.
extern "C" int Util_CopyReadyContextRecords(Record *out) {
    if (*(int*)(data_ov031_0224e5d8 + 0x1a90) != 2) return -1;
    VectorizedMemset(out, 0, 0x780);
    int i = 0;
    Record *cursor = out;
    int zero = 0;
    do {
        cursor->active = zero;
        cursor++;
        i++;
    } while (i < 16);
    int index = zero;
    if (*(int*)(data_ov031_0224e5d8 + 0x1a88) > 0) {
        do {
            if (CopyReadyIndexedByteRecord(index, out) == -1) break;
            index++;
            out++;
        } while (index < *(int*)(data_ov031_0224e5d8 + 0x1a88));
    }
    return 0;
}
