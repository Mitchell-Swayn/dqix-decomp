#include <globaldefs.h>
ARM
extern "C" void VectorizedMemset(void* dst, int value, unsigned int length);
extern "C" int WirelessBeaconScan_CopyReadyResult(int,void*);
// Original data: arm9/ov031 @ 0x224e5d8; symbol: data_ov031_0224e5d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char *UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage;
struct Record { int active; char payload[116]; };
// Original: arm9/ov031 @ 0x0221624C; symbol: func_ov031_0221624c; size: 0xA4.
extern "C" int Util_CopyReadyContextRecords(Record *out) {
    if (*(int*)(UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage + 0x1a90) != 2) return -1;
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
    if (*(int*)(UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage + 0x1a88) > 0) {
        do {
            if (WirelessBeaconScan_CopyReadyResult(index, out) == -1) break;
            index++;
            out++;
        } while (index < *(int*)(UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage + 0x1a88));
    }
    return 0;
}
