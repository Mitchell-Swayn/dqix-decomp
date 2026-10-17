#include <globaldefs.h>
// Combat action command dispatch, indexed by command opcode. Dispatcher021e9778
// passes commandnode r0, action r1, combatstate r2 and selectioncontext r3.
// It interprets returned int status0,1,-1 to retain/advance the linked command.
// Opaque argument layouts remain unresolved; incoming register contract is explicit.
struct CombatCommandNode;
struct CombatActionRecord;
struct CombatExecutionState;
struct CombatSelectionContext;
typedef int (*CombatCommandProc)(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
extern "C" {
int func_ov025_021e2980(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e2c34(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e2ca4(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e2f4c(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int RegisterAndInitializeIndexedRecord(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e30e8(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e3178(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Object_ClearOffset57COnMatchingValue(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e3c78(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e3c80(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e40bc(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e40c4(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e40cc(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e40d4(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e40dc(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int FormatAndAppendSelectedValue(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e413c(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int World_LoadFormattedResource(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e41a0(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetMappedSelectionVisibility(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e44fc(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_TurnLinkedCombatantTowardTarget(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Graphics_RunLinkedObjectEffectUntilNearTarget(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_TestSelectedObjectAnimationReady(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int DispatchObjectHalfwordIndexWithZeroAndReturnOne(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e4a00(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int BackgroundLoader_FormatAndAppendSelectedValue(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e4a58(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e4a88(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e4a90(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e4aac(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Resource_LoadCHRAndCreateBoneTrackingState(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e4e10(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Memory_PushGlobalAllocatorState(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e4ec8(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Unclassified_InitializeFromGlobalContextField(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e4f00(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int ClearIndexedDisplayObjectAndEntry(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetDisplayRecordSelectedTarget(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Graphics_SetSelectedDisplayRecordParentAndBone(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e514c(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e56e8(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Graphics_SetMainBrightnessFromFields(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Resource_IsBrightnessTransitionInactive(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e58f0(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e59b4(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int GameState_SetVectorFromParameterAndMarkOverlay(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Object_ApplyHeightScaledVectorUpdate(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Graphics_ApplyHeightScaledVectorToCurrentObject(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e5e1c(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_CopySelectedCombatantName(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Graphics_ClearAndStageFieldBuffers(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Object_ApplyPackedHalfwordSettings(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e5ff0(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e6010(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e6030(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e604c(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e6208(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e6230(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int StoreInputOffset8ToGlobalNestedOffset544AndReturnOne(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e6270(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Resource_StoreObjectField8InGlobal54C(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e62a8(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Ov025_CheckOverlayTaskAndCondition(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e6304(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e6320(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e6340(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e6374(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int StoreInputOffset8ToGlobalNestedOffset560AndReturnOne(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e63b0(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e66cc(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int World_ShowIndexedObjectAndHideRelated(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e697c(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e6a08(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e6cd4(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e6cf4(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Memory_CopyObjectHalfwordsToGlobalContext(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e6f20(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_IsSelectedObjectAnimationComplete(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int ConfigureTransformWithCombatantHeightScale(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Graphics_UpdateObjectAndApplyCurrentGameState(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int GameState_ApplyVectorInterpolationOrMarkOverlay(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int GameState_ApplyOverlayControlledVectorTransform(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int GameResources_UpdateFlag2000FromParameter(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_AttachSelectedObjectToSelectedParent(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_DetachSelectedObjectAndApplyLinkedPlacement(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e7450(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int GameState_ReplaceTemporaryObjectAndRevealIndexed(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e74d0(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Graphics_BeginLightingFadeAndSetOverlayFlag(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetSelectedObjectAnimationFlags(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e75a4(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e7890(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e7afc(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e7b74(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetSelectedMonsterFlag4(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e7eb8(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e7ec0(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e7fb4(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Resource_UpdateFlagFromObjectByte8(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e8008(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e8024(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e8044(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e8064(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int DispatchSelectionAndNotifyResource(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e80d8(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int GameState_SetWordPairFromFieldsWhenUnknownB0Nonzero(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e812c(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e8148(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Unclassified_CopyThreeObjectFieldsToOverlayRecord(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e8248(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_CopySelectionFieldsToCurrentState(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int UpdateOverlayControlFromByte(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Resource_UpdateMaskFromInputFlag(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e8344(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e83c4(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Overlay_SetEmbeddedAngleFromField8(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e8548(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Script_SetCurrentHalfword19DAFromObjectOffset8(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e856c(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int SetOverlayEmbeddedHalfwordFromObjectFields(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e85a8(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Resource_DispatchGlobalObjectOne(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int SetResourceFlagFromStateByte(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e861c(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Resource_ApplyLinkedRecordParameter(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e8670(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e86f0(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Resource_ClearGameResourceByte448A(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Resource_StoreObjectByte8InGlobal5D0(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e8740(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e8748(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int func_ov025_021e8798(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetFirstSelectedObjectAngle(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Resource_SetOverlayFlagIfPresent(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Resource_SetOverlayFlagAt6ff9IfPresent(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
CombatCommandProc data_ov025_021ef538[144] = {
    0, // opcode0
    0, // opcode1
    0, // opcode2
    func_ov025_021e2980, // opcode3
    func_ov025_021e2c34, // opcode4
    func_ov025_021e2ca4, // opcode5
    func_ov025_021e2f4c, // opcode6
    RegisterAndInitializeIndexedRecord, // opcode7
    func_ov025_021e30e8, // opcode8
    func_ov025_021e3178, // opcode9
    Object_ClearOffset57COnMatchingValue, // opcode10
    func_ov025_021e3c78, // opcode11
    func_ov025_021e3c80, // opcode12
    func_ov025_021e40bc, // opcode13
    func_ov025_021e40c4, // opcode14
    func_ov025_021e40cc, // opcode15
    func_ov025_021e40d4, // opcode16
    func_ov025_021e40dc, // opcode17
    FormatAndAppendSelectedValue, // opcode18
    func_ov025_021e413c, // opcode19
    World_LoadFormattedResource, // opcode20
    func_ov025_021e41a0, // opcode21
    Combat_SetMappedSelectionVisibility, // opcode22
    func_ov025_021e44fc, // opcode23
    Combat_TurnLinkedCombatantTowardTarget, // opcode24
    Graphics_RunLinkedObjectEffectUntilNearTarget, // opcode25
    Combat_TestSelectedObjectAnimationReady, // opcode26
    DispatchObjectHalfwordIndexWithZeroAndReturnOne, // opcode27
    func_ov025_021e4a00, // opcode28
    BackgroundLoader_FormatAndAppendSelectedValue, // opcode29
    func_ov025_021e4a58, // opcode30
    func_ov025_021e4a88, // opcode31
    func_ov025_021e4a90, // opcode32
    func_ov025_021e4aac, // opcode33
    Resource_LoadCHRAndCreateBoneTrackingState, // opcode34
    func_ov025_021e4e10, // opcode35
    Memory_PushGlobalAllocatorState, // opcode36
    func_ov025_021e4ec8, // opcode37
    Unclassified_InitializeFromGlobalContextField, // opcode38
    func_ov025_021e4f00, // opcode39
    ClearIndexedDisplayObjectAndEntry, // opcode40
    Combat_SetDisplayRecordSelectedTarget, // opcode41
    func_ov025_021e514c, // opcode42
    func_ov025_021e56e8, // opcode43
    Graphics_SetMainBrightnessFromFields, // opcode44
    Resource_IsBrightnessTransitionInactive, // opcode45
    func_ov025_021e58f0, // opcode46
    func_ov025_021e59b4, // opcode47
    GameState_SetVectorFromParameterAndMarkOverlay, // opcode48
    Object_ApplyHeightScaledVectorUpdate, // opcode49
    Graphics_ApplyHeightScaledVectorToCurrentObject, // opcode50
    func_ov025_021e5e1c, // opcode51
    Combat_CopySelectedCombatantName, // opcode52
    Graphics_ClearAndStageFieldBuffers, // opcode53
    0, // opcode54
    Object_ApplyPackedHalfwordSettings, // opcode55
    func_ov025_021e5ff0, // opcode56
    func_ov025_021e6010, // opcode57
    func_ov025_021e6030, // opcode58
    Graphics_SetSelectedDisplayRecordParentAndBone, // opcode59
    func_ov025_021e604c, // opcode60
    func_ov025_021e6208, // opcode61
    func_ov025_021e6230, // opcode62
    StoreInputOffset8ToGlobalNestedOffset544AndReturnOne, // opcode63
    func_ov025_021e6270, // opcode64
    Resource_StoreObjectField8InGlobal54C, // opcode65
    func_ov025_021e62a8, // opcode66
    Ov025_CheckOverlayTaskAndCondition, // opcode67
    func_ov025_021e6304, // opcode68
    func_ov025_021e6320, // opcode69
    func_ov025_021e6340, // opcode70
    func_ov025_021e6374, // opcode71
    StoreInputOffset8ToGlobalNestedOffset560AndReturnOne, // opcode72
    func_ov025_021e63b0, // opcode73
    func_ov025_021e66cc, // opcode74
    World_ShowIndexedObjectAndHideRelated, // opcode75
    func_ov025_021e697c, // opcode76
    func_ov025_021e6a08, // opcode77
    func_ov025_021e6cd4, // opcode78
    func_ov025_021e6cf4, // opcode79
    Memory_CopyObjectHalfwordsToGlobalContext, // opcode80
    0, // opcode81
    0, // opcode82
    0, // opcode83
    func_ov025_021e6f20, // opcode84
    Combat_IsSelectedObjectAnimationComplete, // opcode85
    ConfigureTransformWithCombatantHeightScale, // opcode86
    Graphics_UpdateObjectAndApplyCurrentGameState, // opcode87
    GameState_ApplyVectorInterpolationOrMarkOverlay, // opcode88
    GameState_ApplyOverlayControlledVectorTransform, // opcode89
    GameResources_UpdateFlag2000FromParameter, // opcode90
    Combat_AttachSelectedObjectToSelectedParent, // opcode91
    Combat_DetachSelectedObjectAndApplyLinkedPlacement, // opcode92
    func_ov025_021e7450, // opcode93
    GameState_ReplaceTemporaryObjectAndRevealIndexed, // opcode94
    func_ov025_021e74d0, // opcode95
    Graphics_BeginLightingFadeAndSetOverlayFlag, // opcode96
    Combat_SetSelectedObjectAnimationFlags, // opcode97
    func_ov025_021e75a4, // opcode98
    func_ov025_021e7890, // opcode99
    func_ov025_021e7afc, // opcode100
    func_ov025_021e7b74, // opcode101
    Combat_SetSelectedMonsterFlag4, // opcode102
    func_ov025_021e7eb8, // opcode103
    func_ov025_021e7ec0, // opcode104
    func_ov025_021e7fb4, // opcode105
    Resource_UpdateFlagFromObjectByte8, // opcode106
    func_ov025_021e8008, // opcode107
    func_ov025_021e8024, // opcode108
    func_ov025_021e8044, // opcode109
    func_ov025_021e8064, // opcode110
    DispatchSelectionAndNotifyResource, // opcode111
    func_ov025_021e80d8, // opcode112
    GameState_SetWordPairFromFieldsWhenUnknownB0Nonzero, // opcode113
    func_ov025_021e812c, // opcode114
    func_ov025_021e8148, // opcode115
    Unclassified_CopyThreeObjectFieldsToOverlayRecord, // opcode116
    func_ov025_021e8248, // opcode117
    Combat_CopySelectionFieldsToCurrentState, // opcode118
    UpdateOverlayControlFromByte, // opcode119
    Resource_UpdateMaskFromInputFlag, // opcode120
    func_ov025_021e8344, // opcode121
    func_ov025_021e83c4, // opcode122
    Overlay_SetEmbeddedAngleFromField8, // opcode123
    func_ov025_021e8548, // opcode124
    Script_SetCurrentHalfword19DAFromObjectOffset8, // opcode125
    func_ov025_021e856c, // opcode126
    SetOverlayEmbeddedHalfwordFromObjectFields, // opcode127
    func_ov025_021e85a8, // opcode128
    Resource_DispatchGlobalObjectOne, // opcode129
    SetResourceFlagFromStateByte, // opcode130
    func_ov025_021e861c, // opcode131
    Resource_ApplyLinkedRecordParameter, // opcode132
    func_ov025_021e8670, // opcode133
    func_ov025_021e86f0, // opcode134
    Resource_ClearGameResourceByte448A, // opcode135
    Resource_StoreObjectByte8InGlobal5D0, // opcode136
    func_ov025_021e8740, // opcode137
    func_ov025_021e8748, // opcode138
    func_ov025_021e8798, // opcode139
    Combat_SetFirstSelectedObjectAngle, // opcode140
    Resource_SetOverlayFlagIfPresent, // opcode141
    Resource_SetOverlayFlagAt6ff9IfPresent, // opcode142
    0, // opcode143
};
}
