// Original data: arm9/ov031 @ 0x224bedc; symbol: data_ov031_0224bedc.
// Top-screen resource paths by utility screen.
// Initial values: hex 8cbe2402a0be2402b4be2402c8be240278be2402.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Top-screen resource paths by utility screen.
extern "C" {
extern char ProgramData_PathCharJtTopNscL[];
extern char ProgramData_PathCharJtStep1NscL[];
extern char ProgramData_PathCharJtStep2NscL[];
extern char ProgramData_PathCharJtStep3NscL[];
extern char ProgramData_PathCharJtOptionNscL[];
const char *WfcUtilityLoadModeBackgroundAndScheduleUpload_TopScreenResourcePathsByUtilityScreen[5] = {
    ProgramData_PathCharJtStep1NscL,
    ProgramData_PathCharJtStep2NscL,
    ProgramData_PathCharJtStep3NscL,
    ProgramData_PathCharJtOptionNscL,
    ProgramData_PathCharJtTopNscL,
};
}
