#include <globaldefs.h>
ARM
extern "C" void VectorizedMemset(void* dst, int value, unsigned int length);
extern "C" void Build256EntryReflectedCRCTable(unsigned short* table,unsigned polynomial);
extern "C" int InvokeOperationWithFlagSelectedMode(void *p,void *a,int b,bool flag);
extern "C" int func_ov031_02215fcc(void);
extern "C" char * volatile data_ov031_0224e5d8;
// Original: arm9/ov031 @ 0x02215FD8; symbol: func_ov031_02215fd8; size: 0x98.
extern "C" int Util_InitializeCrcOperationContext(char *storage, void *arg, int value, bool flag) {
    if (!arg) return -1;
    data_ov031_0224e5d8 = storage;
    unsigned size = func_ov031_02215fcc();
    VectorizedMemset(data_ov031_0224e5d8, 0, size);
    *(unsigned*)(data_ov031_0224e5d8 + 0x1a90) = 0;
    *(unsigned short*)(data_ov031_0224e5d8 + 0x1a94) = 0;
    Build256EntryReflectedCRCTable((unsigned short*)(data_ov031_0224e5d8 + 0x1a96), 0xa001);
    int result = InvokeOperationWithFlagSelectedMode(data_ov031_0224e5d8, arg, value, flag);
    if (result == 2) result = 0;
    return result;
}
