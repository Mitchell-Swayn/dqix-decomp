// Original data: arm9/ov031 @ 0x224b430; symbol: data_ov031_0224b430.
// UTF-16 keyboard character maps by keyboard mode.
// Initial values: hex dcb4240240b52402a4b52402.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// UTF-16 keyboard character maps by keyboard mode.
extern "C" {
extern unsigned short ProgramData_KeyboardUtf16CodeUnits[];
extern unsigned short ProgramData_KeyboardUtf16CodeUnits_Copy2[];
extern unsigned short ProgramData_KeyboardUtf16CodeUnits_Copy3[];
const unsigned short *WfcKeyboardCreate_UTF16KeyboardCharacterMapsByKeyboardMode[3] = {
    ProgramData_KeyboardUtf16CodeUnits,
    ProgramData_KeyboardUtf16CodeUnits_Copy2,
    ProgramData_KeyboardUtf16CodeUnits_Copy3,
};
}
