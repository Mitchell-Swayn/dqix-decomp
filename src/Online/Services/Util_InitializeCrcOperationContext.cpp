#include <globaldefs.h>
ARM
extern "C" void VectorizedMemset(void* dst, int value, unsigned int length);
extern "C" void CRC16_BuildReflectedPolynomialTable(unsigned short* table,unsigned polynomial);
extern "C" int WM_InitializeForListening(void *p,void *a,int b,bool flag);
extern "C" int WirelessBeaconScan_GetWorkspaceSize(void);
// Original data: arm9/ov031 @ 0x224e5d8; symbol: data_ov031_0224e5d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char * volatile UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02215FD8; symbol: func_ov031_02215fd8; size: 0x98.
extern "C" int Util_InitializeCrcOperationContext(char *storage, void *arg, int value, bool flag) {
    if (!arg) return -1;
    UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage = storage;
    unsigned size = WirelessBeaconScan_GetWorkspaceSize();
    VectorizedMemset(UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage, 0, size);
    *(unsigned*)(UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage + 0x1a90) = 0;
    *(unsigned short*)(UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage + 0x1a94) = 0;
    CRC16_BuildReflectedPolynomialTable((unsigned short*)(UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage + 0x1a96), 0xa001);
    int result = WM_InitializeForListening(UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage, arg, value, flag);
    if (result == 2) result = 0;
    return result;
}
