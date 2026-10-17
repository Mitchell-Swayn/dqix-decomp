extern "C" int TestActiveWordAndGlobalStateNonzero(void*);
extern "C" unsigned int Object_FindSignedByteKeyInSixteenEntries(void*, unsigned int);
// Original: arm9/main @ 0x0202C69C; symbol: func_0202c69c; size: 0x40.
extern "C" void ClearResolvedBitInByteField100FUnlessActive(unsigned char* object, unsigned int value)
{
    if (TestActiveWordAndGlobalStateNonzero(object) != 0) {
        return;
    }
    int bit = (int)Object_FindSignedByteKeyInSixteenEntries(object, value);
    unsigned char* entry = object + 0x100f;
    *entry = *entry & ~(1 << bit);
}
