#include <globaldefs.h>
struct ObjectInfo { int unk0; unsigned short flags; };
struct Object { int unk0; ObjectInfo* info; };
// Returns bits 12-15 of the flags in the object's info record, or 0 if no object.
// Original: arm9/main @ 0x0205B190; symbol: func_0205b190; size: 0x1C.
extern "C" ARM unsigned int ReadLinkedInfoFlagBitsTwelveThroughFifteen(int unused, Object* object)
{
    if (object == NULL)
        return 0;
    return ((unsigned int)object->info->flags >> 12) & 0xf;
}
