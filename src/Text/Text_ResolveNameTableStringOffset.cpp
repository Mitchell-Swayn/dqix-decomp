#pragma thumb off
struct OffsetBase { unsigned char unknown[8]; char* base; };
// Original: arm9/main @ 0x020E523C; symbol: func_020e523c; size: 0x30.
extern "C" char* Text_ResolveNameTableStringOffset(OffsetBase* object, char* offset, char* fallback)
{
    bool invalid = true;
    // CodeWarrior models the encoded pointer word as a byte distance from zero.
    int relativeOffset = offset - (char*)0;
    if (relativeOffset != -1 && object->base)
        invalid = false;
    if (!invalid)
        fallback = object->base + relativeOffset;
    return fallback;
}
