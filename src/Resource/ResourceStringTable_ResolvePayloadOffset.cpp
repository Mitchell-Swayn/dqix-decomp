// Original: arm9/main @ 0x020DFBFC; symbol: func_020dfbfc; size: 0x30.
// Resolves a byte offset against the base at offset 8, retaining the fallback for -1 or null base.
struct OffsetBase { unsigned words[2]; unsigned char* base; };
extern "C" unsigned char* ResourceStringTable_ResolvePayloadOffset(OffsetBase* owner, unsigned char* relative, unsigned char* fallback)
{
    int invalid = 1;
    int offset = relative - (unsigned char*)0;
    if (offset != -1 && owner->base != 0) invalid = 0;
    if (!invalid) fallback = owner->base + offset;
    return fallback;
}
