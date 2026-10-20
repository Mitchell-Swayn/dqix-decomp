// Original data: arm9/main @ 0x020F2BDC; symbol: data_020f2bdc; size: 8.
// Read the main/sub display window-enable bits for WindowControl_SetEnabled.
// Existing linker identities remain unchanged pending semantic renaming.
typedef unsigned (*DisplayEnableReader)();
extern "C" {
// Original: arm9/main @ 0x020E2BC4; symbol: func_020e2bc4.
unsigned Graphics_ReadMainObjectTileMappingBits();
// Original: arm9/main @ 0x020E2BAC; symbol: func_020e2bac.
unsigned Graphics_ReadSubDisplayMode();
// Original data: arm9/main @ 0x020F2BDC; symbol: data_020f2bdc.
DisplayEnableReader WindowControlSetEnabled_UnknownRoleProcedureReferenceRecords[2] = {
    Graphics_ReadMainObjectTileMappingBits, Graphics_ReadSubDisplayMode
};
}
