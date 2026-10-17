#pragma thumb off

extern "C" int PowerManagement_ExecuteCommandSynchronously(int,int,void*);
// Original: arm9/main @ 0x020CE810; symbol: func_020ce810; size: 0x60.
extern "C" int PowerManagement_ReadTwoStatusFlags(int* first, int* second) {
    unsigned short flags;
    int result = PowerManagement_ExecuteCommandSynchronously(15,1,&flags);
    if (result) return result;
    if (first) *first = (flags & 8) != 0;
    if (second) *second = (flags & 4) != 0;
    return result;
}
