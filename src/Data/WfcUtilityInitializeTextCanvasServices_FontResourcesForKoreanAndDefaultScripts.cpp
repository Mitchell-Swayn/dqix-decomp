// Original data: arm9/ov031 @ 0x224c570; symbol: data_ov031_0224c570.
// Font resources for Korean and default scripts.
// Initial values: hex 90c5240280c52402.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Font resources for Korean and default scripts.
extern "C" {
extern char ProgramData_PathMsgLcSNFTRL[];
extern char ProgramData_PathMsgKcMNFTRL[];
const char *WfcUtilityInitializeTextCanvasServices_FontResourcesForKoreanAndDefaultScripts[2] = {
    ProgramData_PathMsgKcMNFTRL,
    ProgramData_PathMsgLcSNFTRL,
};
}
