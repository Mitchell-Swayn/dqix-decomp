#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct Node;
struct Lists;
struct OpeningPresentation;
struct RefreshCommand { unsigned char prefix[9]; unsigned char targetCount; };
struct RefreshTarget { unsigned char prefix[0x18]; unsigned char resultCount; };
struct RefreshResult { unsigned statusLow, statusHigh; void* messages; };
struct RefreshPresentation {
    unsigned int* linkedCommands;
    unsigned char unknown04[0x1c0];
    unsigned flags;
    unsigned char unknown1C8[0x374];
    unsigned char active;
    unsigned char unknown53D[0x8b];
    unsigned short pendingTarget;
};
extern "C" {
unsigned BattleScene_GetActiveInstance();
char* BattleScene_ResolveCurrentActionRecord(char*);
void Combat_PlayActionCategorySoundOnce(unsigned char*, int);
void Combat_QueueOpeningActionMessagesOnce(OpeningPresentation*);
void Combat_RestoreActionActorsAndFacePrimaryTowardTarget(char*);
void Combat_ResetMotionTrail(void*);
void SetCollectedCombatantsAlpha31Immediately(char*);
void* Util_FindLinkedNodeByWord(unsigned*, unsigned);
void Combat_ApplyActionMpResultsAndShowRecovery(void*);
void* Combat_GetIndexedActionTarget(void*, int);
Node* Combat_GetTargetResultByCategoryAndPosition(Lists*, int, int);
int Combat_GetLatestTargetFromHistory(char*);
void QueueQualifiedLinkedPresentation(char*, int, int, int);
// Original data: arm9/ov025 @ 0x021EF9A4; symbol: data_ov025_021ef9a4.
// Zero-initialized flags shared by action-presentation stages.
extern unsigned CombatAdvanceActionPresentation_UnknownRoleZeroInitializedStorage_Variant2;
}
#pragma force_active on
// Original: arm9/ov025 @ 0x021E9B2C; symbol: func_ov025_021e9b2c; size: 0x1E8.
// Refreshes action visuals and queues qualified results when no target has linked messages.
extern "C" void Combat_RefreshActionPresentationAndQueueResults(RefreshPresentation* self)
{
    GameState::GetInstance();
    char* scene = (char*)BattleScene_GetActiveInstance();
    RefreshCommand* command = (RefreshCommand*)BattleScene_ResolveCurrentActionRecord(scene);
    if (CombatAdvanceActionPresentation_UnknownRoleZeroInitializedStorage_Variant2 & 8) {
        Combat_PlayActionCategorySoundOnce((unsigned char*)self, 0);
        Combat_QueueOpeningActionMessagesOnce((OpeningPresentation*)self);
        Combat_RestoreActionActorsAndFacePrimaryTowardTarget((char*)self);
        Combat_ResetMotionTrail(scene + 0x5ab0);
        SetCollectedCombatantsAlpha31Immediately(scene);
    }
    if (self->flags & 0x10) {
        self->flags &= ~0x10;
        if (!(CombatAdvanceActionPresentation_UnknownRoleZeroInitializedStorage_Variant2 & 0x20)) {
            CombatAdvanceActionPresentation_UnknownRoleZeroInitializedStorage_Variant2 |= 0x20;
            if ((!self->linkedCommands || !Util_FindLinkedNodeByWord(self->linkedCommands, 0x69)) && !Util_FindLinkedNodeByWord(self->linkedCommands, 0x89)) Combat_ApplyActionMpResultsAndShowRecovery(self);
            int empty = 1;
            for (int i = 0; i < command->targetCount; ++i) {
                RefreshTarget* target = (RefreshTarget*)Combat_GetIndexedActionTarget(command, i);
                if (target) {
                    for (int j = 0; j < target->resultCount; ++j) {
                        RefreshResult* result = (RefreshResult*)Combat_GetTargetResultByCategoryAndPosition((Lists*)target, j, 0);
                        if (result && result->messages) { empty = 0; break; }
                    }
                }
            }
            if (empty) {
                int fourSlot = 1;
                RefreshTarget* target = (RefreshTarget*)Combat_GetIndexedActionTarget(command, 0);
                if (target) {
                    int latest = Combat_GetLatestTargetFromHistory((char*)target);
                    int valid;
                    if (latest >= 0 && latest <= 3) valid = 1;
                    else valid = 0;
                    if (valid) fourSlot = 1;
                    else fourSlot = 0;
                }
                QueueQualifiedLinkedPresentation((char*)self, fourSlot, 1, -1);
            } else self->active = 0;
        }
    }
    if (self->pendingTarget < 255 && self->active) {
        int valid = self->pendingTarget <= 3 ? 1 : 0;
        int fourSlot;
        if (valid) fourSlot = 1;
        else fourSlot = 0;
        QueueQualifiedLinkedPresentation((char*)self, fourSlot, 1, -1);
    }
}
#pragma force_active reset
