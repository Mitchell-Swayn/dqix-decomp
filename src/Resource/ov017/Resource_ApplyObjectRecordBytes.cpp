#include <globaldefs.h>
ARM
extern "C" void* GameState_FindIndexedObjectWithFlag1000(void*, int);
extern "C" void WriteByteAtOffset2D0(void*, signed char);
extern "C" void Object_SetByteAtOffset2D1(void*, signed char);
extern "C" void Object_SetByteAtOffset1C8(void*, signed char);
extern "C" void SetByteFieldAtOffset1C9(void*, signed char);
// Original: arm9/ov017 @ 0x021CE3AC; symbol: func_ov017_021ce3ac; size: 0x54.
extern "C" void Resource_ApplyObjectRecordBytes(unsigned unused, unsigned char* record, void* state) {
    void* object = GameState_FindIndexedObjectWithFlag1000(state, *(unsigned short*)(record + 4));
    if (object == 0) return;
    WriteByteAtOffset2D0(object, (signed char)record[6]);
    Object_SetByteAtOffset2D1(object, (signed char)record[7]);
    Object_SetByteAtOffset1C8(object, (signed char)record[8]);
    SetByteFieldAtOffset1C9(object, (signed char)record[9]);
    *(unsigned char*)((char*)object + 0x2d2) = (unsigned char)record[0xa];
}
