// Original data: arm9/ov031 @ 0x224b424; symbol: data_ov031_0224b424.
// ASCII keyboard character maps by keyboard mode.
// Initial values: hex acb424024cb424027cb42402.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// ASCII keyboard character maps by keyboard mode.
extern "C" {
extern char ProgramData_FormatQWERTYUIOPASDFGHJKLZXCVBNM[];
extern char ProgramData_Text1234567890QWERTYUIOPASDFGHJKLZXCVBNM[];
extern char ProgramData_Text1234567890QwertyuiopAsdfghjklZxcvbnm_Copy2[];
const char *WfcKeyboardConfirmTouchInput_ASCIIKeyboardCharacterMapsByKeyboardMode[3] = {
    ProgramData_Text1234567890QwertyuiopAsdfghjklZxcvbnm_Copy2,
    ProgramData_FormatQWERTYUIOPASDFGHJKLZXCVBNM,
    ProgramData_Text1234567890QWERTYUIOPASDFGHJKLZXCVBNM,
};
}
