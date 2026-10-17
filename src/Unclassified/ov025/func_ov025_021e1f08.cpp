#include <globaldefs.h>
ARM
extern "C" unsigned int Object_ReadNestedOffset13CByte4COrFF(unsigned char **p);
extern "C" unsigned int ReadLinkedByteField4DOrReturnFF(char *p);
// Original: arm9/ov025 @ 0x021E1F08; symbol: func_ov025_021e1f08; size: 0x38.
extern "C" int func_ov025_021e1f08(char *obj, void *record) {
    unsigned int result = Object_ReadNestedOffset13CByte4COrFF((unsigned char **)obj);
    if (result != 0xff) return result;
    result = ReadLinkedByteField4DOrReturnFF(obj);
    if (result != 0xff) return result;
    void *field = *(void **)((char *)record + 0x14);
    if (field != 0) result = *(short *)((char *)field + 0xe);
    return result;
}
