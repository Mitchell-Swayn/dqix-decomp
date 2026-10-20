// Original data: arm9/main @ 0x020F2BEC; symbol: data_020f2bec; size: 8.
// Write the main/sub display window-enable bits for WindowControl_SetEnabled.
// Existing linker identities remain unchanged pending semantic renaming.
typedef void (*DisplayEnableWriter)(unsigned);
extern "C" {
// Original: arm9/main @ 0x020E2B94; symbol: func_020e2b94.
void Graphics_SetMainWindowEnableBits(unsigned);
// Original: arm9/main @ 0x020E2B78; symbol: func_020e2b78.
void Graphics_SetSubObjectTileMappingBits(unsigned);
// Original data: arm9/main @ 0x020F2BEC; symbol: data_020f2bec.
DisplayEnableWriter WindowControlSetEnabled_UnknownRoleProcedureReferenceRecords_Variant2[2] = {
    Graphics_SetMainWindowEnableBits, Graphics_SetSubObjectTileMappingBits
};
}
