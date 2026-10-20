#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2248d3a; symbol: data_ov031_02248d3a.
// Numeric keyboard navigation: 14 keys with four signed destinations, plus two zero alignment bytes. MoveEffectSelectionThroughTransitionTable indexes key*4+direction and ldrsb. Negative navigation values are special fallback destinations handled by the consumer.
// Initial values: hex 020c0103000d0204010d0005050004060301050704020308080307090604080a0705060b0b060a0c09070b0d0a08090d0d090d000cff0cfe0000.
// Observed span: 58 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2250c00; symbol: data_ov031_02250c00.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" {extern signed char* WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage;extern signed char WfcNumberPadMoveSelection_NumericKeyboardNavigation14KeysWithFourSignedDestinationsPlusTwoZeroAlignmentBytes[];void ConfigureEffectSpriteBySignedIndex();int WfcUtility_PlaySequenceArchiveEntry(unsigned);}
// Original: arm9/ov031 @ 0x02226A64; symbol: MoveEffectSelectionThroughTransitionTable; size: 0xac.
// Resolves selection transition table with remembered state for special values13/-1/-2.
extern "C" void WfcNumberPad_MoveSelection(int direction){int old=WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage[0x63];WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage[0x63]=*(WfcNumberPadMoveSelection_NumericKeyboardNavigation14KeysWithFourSignedDestinationsPlusTwoZeroAlignmentBytes+old*4+direction);int next=WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage[0x63];if(next==13 && (direction==1 || direction==3))WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage[0x64]=old;else if(next==-1){int previous=WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage[0x64];if(previous==1 || previous==10)WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage[0x63]=10;else WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage[0x63]=11;}else if(next==-2){int previous=WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage[0x64];if(previous==1 || previous==10)WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage[0x63]=1;else WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage[0x63]=2;}ConfigureEffectSpriteBySignedIndex();WfcUtility_PlaySequenceArchiveEntry(8);}
