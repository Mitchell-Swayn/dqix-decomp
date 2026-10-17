#include <globaldefs.h>
extern "C" unsigned char data_ov031_02290c40[];
extern "C" void *func_ov031_0223bfa0(void *);
extern "C" void *func_ov031_0223b61c(void *, void *, unsigned);
// Original: arm9/ov031 @ 0x02227630; symbol: func_ov031_02227630; size: 0x58.
extern "C" void *OV031_BuildSharedRecordViews(void *source) {
    unsigned char *global = *(unsigned char **)data_ov031_02290c40;
    void *views = func_ov031_0223bfa0(*(void **)(global + 0x60));
    unsigned local;
    unsigned char *record = (unsigned char *)func_ov031_0223b61c(source, &local, 4);
    unsigned char *base = record + 0x20;
    *(void **)((char *)views + 8) = record;
    *(void **)views = base + 0x10;
    *(void **)((char *)views + 4) = base + *(unsigned *)(base + 4) + 8;
    return views;
}
