// Original data: arm9/main @ 0x020F2BF4; symbol: data_020f2bf4; size: 16.
// Select the main/sub display and window zero/one bounds writers by [bank][window].
// Existing linker identities remain unchanged pending semantic renaming.
typedef void (*WindowBoundsWriter)(unsigned,unsigned,unsigned,unsigned);
extern "C" {
// Original: arm9/main @ 0x020E2A54; symbol: func_020e2a54.
void Graphics_WriteMainWindow0Bounds(unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020E2A20; symbol: func_020e2a20.
void Graphics_SetMainWindowOneBounds(unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020E29EC; symbol: func_020e29ec.
void Graphics_SetSubWindowHorizontalAndVerticalBounds(unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020E29B8; symbol: func_020e29b8.
void Graphics_WriteSubWindow1Bounds(unsigned,unsigned,unsigned,unsigned);
// Original data: arm9/main @ 0x020F2BF4; symbol: data_020f2bf4.
WindowBoundsWriter WindowControlApplyEnabledBoundsAndMasks_UnknownRoleProcedureReferenceRecords[2][2] = {
    {Graphics_WriteMainWindow0Bounds, Graphics_SetMainWindowOneBounds},
    {Graphics_SetSubWindowHorizontalAndVerticalBounds, Graphics_WriteSubWindow1Bounds}
};
}
