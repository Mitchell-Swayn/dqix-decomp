// Original data: arm9/ov002 @ 0x216d3ac; symbol: data_ov002_0216d3ac.
// Menu condition flag; func_ov002_0215505c initializes and ProcessRecordActionConfirmation sets via byte access.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov002.md.
// Menu condition flag; func_ov002_0215505c initializes and ProcessRecordActionConfirmation sets via byte access.
extern "C" {
unsigned char PartyMenuInitializeController_MenuConditionFlag;
}
