// Original data: arm9/main @ 0x020E8C00; symbol: data_020e8c00; size: 88.
// Owner: src/GameState/ReadDescriptorDependentStateValue.cpp.
// Retain the existing external linker identity pending semantic renaming.
// Alternating descriptor keys and GameState attribute identifiers. The caller
// scans two unsigned words at a time until key 0xFFFFFFFF, then obtains the
// learned-skill mask and attribute value for the matching identifier.
extern "C" {
extern const unsigned int ReadDescriptorDependentStateValue_UnknownRoleInitializedBytes[22] = {
    33, 134, 0, 3, 1, 13, 2, 27, 5, 70, 6, 113,
    7, 125, 8, 181, 9, 189, 11, 213, 0xFFFFFFFF, 0xFFFFFFFF
};
}
