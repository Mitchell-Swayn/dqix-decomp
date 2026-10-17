#include <globaldefs.h>
ARM
struct Entry { unsigned *data; };
extern "C" Entry *FindSerializedPrimaryRecordByKey(void *, int);
extern "C" void __clear(void *, unsigned);
extern "C" char* strcpy(char *, const char *);
extern "C" int sprintf(char *, const char *, ...);
extern "C" const char data_ov015_0219400a[];
extern "C" const char data_ov015_0219400d[];
extern "C" const char data_ov015_02194010[];
extern "C" const char data_ov015_02194013[];
// Original: arm9/ov015 @ 0x0218C274; symbol: func_ov015_0218c274; size: 0x130.
extern "C" void func_ov015_0218c274(void *p, char *out, int flag) {
    int key = (short)*(unsigned int*)((char*)*(void**)((char*)p + 0x20) + 0x20);
    Entry *a = FindSerializedPrimaryRecordByKey((char*)*(void**)p + 0x4c, key);
    int key2 = (short)**(unsigned int**)((char*)p + 0x20);
    Entry *b = FindSerializedPrimaryRecordByKey((char*)*(void**)p + 0x4c, key2);
    unsigned int va = 0;
    unsigned int vb = 0;
    if (b) va = (b->data[1] << 12 >> 24);
    if (a) vb = (a->data[1] << 12 >> 24);
    char temp[4];
    __clear(temp, 4);
    int suffix;
    if (((unsigned char*)p)[0x1c] == 1) {
        strcpy(temp, data_ov015_0219400a);
        suffix = ((unsigned char*)p)[0x3b] == 0 ? 0x6d : 0x77;
    } else {
        strcpy(temp, data_ov015_0219400d);
        suffix = *(void**)((char*)p + 0x48) == 0 ? 0x6e : 0x62;
        if (flag) suffix = 0x66;
    }
    if ((suffix == 0x6e || suffix == 0x66) && ((unsigned char*)p)[0x3b] == 1)
        strcpy(temp, data_ov015_02194010);
    sprintf(out, data_ov015_02194013, temp, va, vb, suffix);
}
