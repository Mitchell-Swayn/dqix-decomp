#include <globaldefs.h>
ARM
struct CombatCommandNode;
struct CombatActionRecord;
struct CombatExecutionState;
struct CombatSelectionContext;
namespace {
struct CueConfiguration {
    unsigned char prefix[0x16];
    unsigned short conditionalVisual;
    unsigned char unknown18[4];
    unsigned short sound;
    unsigned short conditionalSound;
    unsigned char unknown20[4];
    unsigned short cameraMode;
    unsigned short selectionMask;
    unsigned short scaleFlags;
    short scaleRange[2];
    unsigned char unknown2E[6];
    unsigned char scaleMode;
};
struct CueHalfwordCommand { unsigned char prefix[8]; unsigned short value; };
struct CueWordCommand { unsigned char prefix[8]; int value; };
}
extern "C" {
// Original data: arm9/ov025 @ 0x021EF988; symbol: data_ov025_021ef988.
// Zero-initialized presentation execution state; its word at offset 0xC points to the active cue owner.
extern unsigned char CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[];
}
namespace {
#pragma always_inline on
inline CueConfiguration* ReadActionCueConfiguration()
{
    return (CueConfiguration*)(*(unsigned char**)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage + 0xC) + 0x540);
}
#pragma always_inline reset
}
#pragma force_active on
// Original: arm9/ov025 @ 0x021E8044; symbol: func_ov025_021e8044; size: 0x20.
extern "C" int Combat_SetActionCueConditionalVisualEffectId(CombatCommandNode* command, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*)
{
    CueConfiguration* cue = ReadActionCueConfiguration();
    unsigned short value = ((CueHalfwordCommand*)command)->value;
    cue->conditionalVisual = value;
    return 1;
}
#pragma force_active reset
