// Original data: arm9/ov025 @ 0x21ef538; symbol: data_ov025_021ef538.
// Combat action command dispatch, indexed by command opcode. Dispatcher021e9778 passes commandnode r0, action r1, combatstate r2 and selectioncontext r3. It interprets returned int status0,1,-1 to retain/advance the linked command. Opaque argument layouts remain unresolved; incoming register contract is explicit.
// Initial values: hex 00000000000000000000000080291e02342c1e02a42c1e024c2f1e0248301e02e8301e0278311e023c3c1e02783c1e02803c1e02bc401e02c4401e02cc401e02 ...; full span in module reference.
// Observed span: 576 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
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
int Combat_PlayActionAnimationCommand(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int IsIndexedObjectAnimationReady(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_QueueAnimationTimedApproach(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_ReturnActionProcedureSuccess(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_InitializeAndQueueActionEffects(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int System_WaitForOverlayTimerAndResetRequest(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_BranchActionScriptOnCondition(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_ClearCommandGateWhenTokenMatches(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int CombatOpcode11_CompleteWithoutAction(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_ConfigureActionCameraByMode(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int CombatOpcode13_CompleteWithoutAction(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int CombatOpcode14_CompleteWithoutAction(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int CombatOpcode15_CompleteWithoutAction(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int CombatOpcode16_CompleteWithoutAction(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int CombatOpcode17_CompleteWithoutAction(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_QueueDataResourceAndTrackLoad(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Filesystem_AreBackgroundTasksReadyWhenLoaderFlag0Set(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_LoadLocalizedDataDisplayResource(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SpawnActionEffectFromTemplate(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetMappedSelectionVisibility(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_ApplyActionActorMpSnapshot(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_TurnLinkedCombatantTowardTarget(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Graphics_RunLinkedObjectEffectUntilNearTarget(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_TestSelectedObjectAnimationReady(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int DispatchObjectHalfwordIndexWithZeroAndReturnOne(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int CombatOpcode28_CompleteWithoutAction(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int BackgroundLoader_FormatAndAppendSelectedValue(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_FormatRecordValueUsingScaleField8(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_ReturnMinusOne(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_EnablePresentationFlag100(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int ReloadSelectedObjectArchives(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Resource_LoadCHRAndCreateBoneTrackingState(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_ActivateBattleCameraPreservingOrbit(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Memory_PushGlobalAllocatorState(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int PopAllocatorStackEntryFromSharedContext(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_ResetCurrentAllocatorAndCleanupObjects(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetActiveCameraSelectedCombatant(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int ClearIndexedDisplayObjectAndEntry(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetDisplayRecordSelectedTarget(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Graphics_SetSelectedDisplayRecordParentAndBone(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_PositionSelectedObjectsByPlacementMode(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetSelectedObjectScaleByMode(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Graphics_SetMainBrightnessFromFields(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Resource_IsBrightnessTransitionInactive(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SwitchZoneAndRestoreRotation(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_ApplyInheritedAlphaToSelectedObjects(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int GameState_SetVectorFromParameterAndMarkOverlay(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Object_ApplyHeightScaledVectorUpdate(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Graphics_ApplyHeightScaledVectorToCurrentObject(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_OpenActionMessageWindow(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_CopySelectedCombatantName(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Graphics_ClearAndStageFieldBuffers(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_ConfigurePackedPresentationParameters(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int CombatOpcode56_SetPresentationParameterAt21C(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int CombatOpcode57_SetPresentationParameterAt21C(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetCameraUpdateParameter(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int ActivateSelectedCombatantsAndTurnGroup(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_BeginActionCueDescriptor(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_QueueActionCuesFromDescriptor(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetActionCueDuration(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetActionCueVisualEffectTime(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Resource_StoreObjectField8InGlobal54C(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int CopyInputHalfwordToGlobalTargetField(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Ov025_CheckOverlayTaskAndCondition(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetActionCueFlags(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_LoadSfxGroup(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Resource_StoreObjectIndexAndInvokeOperation(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetActionCueSoundId(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetActionCueSoundTime(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_LoadActorActionReplacementModel(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_LoadCategoryArchiveOntoReplacementModel(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_ShowReplacementModelAttackAnimation(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_ClearSelectedComponentsAndPaletteFlags(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_MoveActionActorTowardTargetUntilInRange(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetActionCueCameraMode(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_PositionLinkedPairAtRadiusAdjustedDistance(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Memory_CopyObjectHalfwordsToGlobalContext(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetActionEffectMinimumHeight(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_IsSelectedObjectAnimationComplete(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int ConfigureTransformWithCombatantHeightScale(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Graphics_UpdateObjectAndApplyCurrentGameState(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int GameState_ApplyVectorInterpolationOrMarkOverlay(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int GameState_ApplyOverlayControlledVectorTransform(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int GameResources_UpdateFlag2000FromParameter(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_AttachSelectedObjectToSelectedParent(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_DetachSelectedObjectAndApplyLinkedPlacement(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetActionCueSelectionMask(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int GameState_ReplaceTemporaryObjectAndRevealIndexed(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetActionCueCameraWaitPolicy(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Graphics_BeginLightingFadeAndSetOverlayFlag(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetSelectedObjectAnimationFlags(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_CenterMonsterGroupAndQueueSkillPlacement(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_ReloadSpecialActionMonsterSetPreservingActorState(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Grotto_ApplyHalfwordFieldsToSelectedMonsters(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_ReloadSelectedMonsterGroupAndRefreshFacing(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetSelectedMonsterFlag4(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int CombatOpcode103_CompleteWithoutAction(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Graphics_CloneSelectedObjectsAndUploadSharedTexturePalette(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_ApplyActionHpAndMpSnapshots(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Resource_UpdateFlagFromObjectByte8(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_StartTemporaryBgmSequence(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_FadeBgmPlaybackVolume(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetActionCueConditionalVisualEffectId(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetActionCueConditionalSoundId(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int DispatchSelectionAndNotifyResource(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetActionMessageRemainingTime(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int GameState_SetWordPairFromFieldsWhenUnknownB0Nonzero(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetPresentationOptionAt228(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int GameState_ApplySelectedCombatScale(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetSceneActionPresentationParameters(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_ConfigureActionCueScaleRange(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_CopySelectionFieldsToCurrentState(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int UpdateOverlayControlFromByte(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Resource_UpdateMaskFromInputFlag(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_QueueActorCheerArchive(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_ReloadSelectedObjectsWithActorCheerArchive(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Overlay_SetEmbeddedAngleFromField8(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int CombatOpcode124_CompleteWithoutAction(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetMessageContextParameterAt19DA(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_KeepActionCuePendingAfterEffects(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int SetOverlayEmbeddedHalfwordFromObjectFields(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetActionMessageDefaultDuration(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Resource_DispatchGlobalObjectOne(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int SetResourceFlagFromStateByte(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_DisableActionSelectorGate(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetPrimaryActorGroupPolygonId(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_RestorePrimaryActorGroupPolygonIds(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_EnableActionResourceFlag448A(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Resource_ClearGameResourceByte448A(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Resource_StoreObjectByte8InGlobal5D0(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_CompleteNoOpCommand(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetActionSceneOverrideVector(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetPresentationParameter220WithDefault(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Combat_SetFirstSelectedObjectAngle(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Resource_SetOverlayFlagIfPresent(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
int Resource_SetOverlayFlagAt6ff9IfPresent(CombatCommandNode*, CombatActionRecord*, CombatExecutionState*, CombatSelectionContext*);
CombatCommandProc CombatAdvanceActionPresentation_CombatActionCommandDispatchIndexedByCommandOpcode[144] = {
    0, // opcode0
    0, // opcode1
    0, // opcode2
    Combat_PlayActionAnimationCommand, // opcode3
    IsIndexedObjectAnimationReady, // opcode4
    Combat_QueueAnimationTimedApproach, // opcode5
    Combat_ReturnActionProcedureSuccess, // opcode6
    Combat_InitializeAndQueueActionEffects, // opcode7
    System_WaitForOverlayTimerAndResetRequest, // opcode8
    Combat_BranchActionScriptOnCondition, // opcode9
    Combat_ClearCommandGateWhenTokenMatches, // opcode10
    CombatOpcode11_CompleteWithoutAction, // opcode11
    Combat_ConfigureActionCameraByMode, // opcode12
    CombatOpcode13_CompleteWithoutAction, // opcode13
    CombatOpcode14_CompleteWithoutAction, // opcode14
    CombatOpcode15_CompleteWithoutAction, // opcode15
    CombatOpcode16_CompleteWithoutAction, // opcode16
    CombatOpcode17_CompleteWithoutAction, // opcode17
    Combat_QueueDataResourceAndTrackLoad, // opcode18
    Filesystem_AreBackgroundTasksReadyWhenLoaderFlag0Set, // opcode19
    Combat_LoadLocalizedDataDisplayResource, // opcode20
    Combat_SpawnActionEffectFromTemplate, // opcode21
    Combat_SetMappedSelectionVisibility, // opcode22
    Combat_ApplyActionActorMpSnapshot, // opcode23
    Combat_TurnLinkedCombatantTowardTarget, // opcode24
    Graphics_RunLinkedObjectEffectUntilNearTarget, // opcode25
    Combat_TestSelectedObjectAnimationReady, // opcode26
    DispatchObjectHalfwordIndexWithZeroAndReturnOne, // opcode27
    CombatOpcode28_CompleteWithoutAction, // opcode28
    BackgroundLoader_FormatAndAppendSelectedValue, // opcode29
    Combat_FormatRecordValueUsingScaleField8, // opcode30
    Combat_ReturnMinusOne, // opcode31
    Combat_EnablePresentationFlag100, // opcode32
    ReloadSelectedObjectArchives, // opcode33
    Resource_LoadCHRAndCreateBoneTrackingState, // opcode34
    Combat_ActivateBattleCameraPreservingOrbit, // opcode35
    Memory_PushGlobalAllocatorState, // opcode36
    PopAllocatorStackEntryFromSharedContext, // opcode37
    Combat_ResetCurrentAllocatorAndCleanupObjects, // opcode38
    Combat_SetActiveCameraSelectedCombatant, // opcode39
    ClearIndexedDisplayObjectAndEntry, // opcode40
    Combat_SetDisplayRecordSelectedTarget, // opcode41
    Combat_PositionSelectedObjectsByPlacementMode, // opcode42
    Combat_SetSelectedObjectScaleByMode, // opcode43
    Graphics_SetMainBrightnessFromFields, // opcode44
    Resource_IsBrightnessTransitionInactive, // opcode45
    Combat_SwitchZoneAndRestoreRotation, // opcode46
    Combat_ApplyInheritedAlphaToSelectedObjects, // opcode47
    GameState_SetVectorFromParameterAndMarkOverlay, // opcode48
    Object_ApplyHeightScaledVectorUpdate, // opcode49
    Graphics_ApplyHeightScaledVectorToCurrentObject, // opcode50
    Combat_OpenActionMessageWindow, // opcode51
    Combat_CopySelectedCombatantName, // opcode52
    Graphics_ClearAndStageFieldBuffers, // opcode53
    0, // opcode54
    Combat_ConfigurePackedPresentationParameters, // opcode55
    CombatOpcode56_SetPresentationParameterAt21C, // opcode56
    CombatOpcode57_SetPresentationParameterAt21C, // opcode57
    Combat_SetCameraUpdateParameter, // opcode58
    Graphics_SetSelectedDisplayRecordParentAndBone, // opcode59
    ActivateSelectedCombatantsAndTurnGroup, // opcode60
    Combat_BeginActionCueDescriptor, // opcode61
    Combat_QueueActionCuesFromDescriptor, // opcode62
    Combat_SetActionCueDuration, // opcode63
    Combat_SetActionCueVisualEffectTime, // opcode64
    Resource_StoreObjectField8InGlobal54C, // opcode65
    CopyInputHalfwordToGlobalTargetField, // opcode66
    Ov025_CheckOverlayTaskAndCondition, // opcode67
    Combat_SetActionCueFlags, // opcode68
    Combat_LoadSfxGroup, // opcode69
    Resource_StoreObjectIndexAndInvokeOperation, // opcode70
    Combat_SetActionCueSoundId, // opcode71
    Combat_SetActionCueSoundTime, // opcode72
    Combat_LoadActorActionReplacementModel, // opcode73
    Combat_LoadCategoryArchiveOntoReplacementModel, // opcode74
    Combat_ShowReplacementModelAttackAnimation, // opcode75
    Combat_ClearSelectedComponentsAndPaletteFlags, // opcode76
    Combat_MoveActionActorTowardTargetUntilInRange, // opcode77
    Combat_SetActionCueCameraMode, // opcode78
    Combat_PositionLinkedPairAtRadiusAdjustedDistance, // opcode79
    Memory_CopyObjectHalfwordsToGlobalContext, // opcode80
    0, // opcode81
    0, // opcode82
    0, // opcode83
    Combat_SetActionEffectMinimumHeight, // opcode84
    Combat_IsSelectedObjectAnimationComplete, // opcode85
    ConfigureTransformWithCombatantHeightScale, // opcode86
    Graphics_UpdateObjectAndApplyCurrentGameState, // opcode87
    GameState_ApplyVectorInterpolationOrMarkOverlay, // opcode88
    GameState_ApplyOverlayControlledVectorTransform, // opcode89
    GameResources_UpdateFlag2000FromParameter, // opcode90
    Combat_AttachSelectedObjectToSelectedParent, // opcode91
    Combat_DetachSelectedObjectAndApplyLinkedPlacement, // opcode92
    Combat_SetActionCueSelectionMask, // opcode93
    GameState_ReplaceTemporaryObjectAndRevealIndexed, // opcode94
    Combat_SetActionCueCameraWaitPolicy, // opcode95
    Graphics_BeginLightingFadeAndSetOverlayFlag, // opcode96
    Combat_SetSelectedObjectAnimationFlags, // opcode97
    Combat_CenterMonsterGroupAndQueueSkillPlacement, // opcode98
    Combat_ReloadSpecialActionMonsterSetPreservingActorState, // opcode99
    Grotto_ApplyHalfwordFieldsToSelectedMonsters, // opcode100
    Combat_ReloadSelectedMonsterGroupAndRefreshFacing, // opcode101
    Combat_SetSelectedMonsterFlag4, // opcode102
    CombatOpcode103_CompleteWithoutAction, // opcode103
    Graphics_CloneSelectedObjectsAndUploadSharedTexturePalette, // opcode104
    Combat_ApplyActionHpAndMpSnapshots, // opcode105
    Resource_UpdateFlagFromObjectByte8, // opcode106
    Combat_StartTemporaryBgmSequence, // opcode107
    Combat_FadeBgmPlaybackVolume, // opcode108
    Combat_SetActionCueConditionalVisualEffectId, // opcode109
    Combat_SetActionCueConditionalSoundId, // opcode110
    DispatchSelectionAndNotifyResource, // opcode111
    Combat_SetActionMessageRemainingTime, // opcode112
    GameState_SetWordPairFromFieldsWhenUnknownB0Nonzero, // opcode113
    Combat_SetPresentationOptionAt228, // opcode114
    GameState_ApplySelectedCombatScale, // opcode115
    Combat_SetSceneActionPresentationParameters, // opcode116
    Combat_ConfigureActionCueScaleRange, // opcode117
    Combat_CopySelectionFieldsToCurrentState, // opcode118
    UpdateOverlayControlFromByte, // opcode119
    Resource_UpdateMaskFromInputFlag, // opcode120
    Combat_QueueActorCheerArchive, // opcode121
    Combat_ReloadSelectedObjectsWithActorCheerArchive, // opcode122
    Overlay_SetEmbeddedAngleFromField8, // opcode123
    CombatOpcode124_CompleteWithoutAction, // opcode124
    Combat_SetMessageContextParameterAt19DA, // opcode125
    Combat_KeepActionCuePendingAfterEffects, // opcode126
    SetOverlayEmbeddedHalfwordFromObjectFields, // opcode127
    Combat_SetActionMessageDefaultDuration, // opcode128
    Resource_DispatchGlobalObjectOne, // opcode129
    SetResourceFlagFromStateByte, // opcode130
    Combat_DisableActionSelectorGate, // opcode131
    Combat_SetPrimaryActorGroupPolygonId, // opcode132
    Combat_RestorePrimaryActorGroupPolygonIds, // opcode133
    Combat_EnableActionResourceFlag448A, // opcode134
    Resource_ClearGameResourceByte448A, // opcode135
    Resource_StoreObjectByte8InGlobal5D0, // opcode136
    Combat_CompleteNoOpCommand, // opcode137
    Combat_SetActionSceneOverrideVector, // opcode138
    Combat_SetPresentationParameter220WithDefault, // opcode139
    Combat_SetFirstSelectedObjectAngle, // opcode140
    Resource_SetOverlayFlagIfPresent, // opcode141
    Resource_SetOverlayFlagAt6ff9IfPresent, // opcode142
    0, // opcode143
};
}
