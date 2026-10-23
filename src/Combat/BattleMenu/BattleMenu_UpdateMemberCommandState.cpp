#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
ARM
#pragma force_active on
#define WORD(p,o) (*(int*)((p)+(o)))
#define UWORD(p,o) (*(unsigned*)((p)+(o)))
#define HALF(p,o) (*(short*)((p)+(o)))
#define UHALF(p,o) (*(unsigned short*)((p)+(o)))
#define BYTE(p,o) (*(unsigned char*)((p)+(o)))
#define SBYTE(p,o) (*(signed char*)((p)+(o)))
#define PTR(p,o) (*(char**)((p)+(o)))
#define FLOAT(p,o) (*(float*)((p)+(o)))
extern "C" {
// Original data: arm9/ov000 @ 0x02184294; shared command-menu arguments and owner.
extern unsigned BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x02114E30; key input state.
extern char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x02108760; sound state.
extern char Main_UnknownRoleZeroInitializedStorage[];
int Selection_ReadEnabledIndexFromControl(void*);
void Window_SetCanvasEnabled(void*,int,int);
void Window_SetCanvasDisplayAttribute(void*,int,int);
int Input_IsKeyMaskNewlyPressed(void*,int);
int TestSelectedRecordReadyAndByteFlagBitOne(void*,int);
void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
int System_TestNewInputMaskOrStateModeTwo(const unsigned char*);
void BattleMenu_ConfigureGlobalCommandSelection(char*,int,int);
void BattleMenu_RefreshExistingPanel(char*,char*,int,int,int,unsigned char);
void BattleMenu_RefreshPanelForActiveMode(char*,char*,int,int,int);
char* BattleMenu_FindPartyCommandRecord(char*,int);
char* GameState_GetIndexList(GameState*);
int GameState_ReadProtagonistObjectIndex(GameState*);
bool BattleMenu_TestConfirmInputAfterDelay(unsigned char*,int);
int BattleMenu_TestCancelInput(void*);
void Window_PopCanvasesAndResetSelection(void*,int);
char* BattleMenu_GetSelectedPartyCommandRecord(char*);
void BattleMenu_OpenPanelForSelectionState(char*,char*,int,int,int);
void BattleMenu_RefreshMemberCommandLabel(unsigned char*);
GameObject* GameState_GetObjectWithFlag100(GameState*,int);
unsigned GameObject_GetLinkedIndexedState(int);
char* GameState_ReadPResources();
char* FieldBattle_GetScene(void*);
int BattleMenu_HasCommandBlockingStatus(char*);
void* Zone3D_GetMainInstance();
void* memset(void*,int,unsigned);
}
extern "C" {
// Original data: arm9/ov000 @ 0x02183FF0; saved panel dispatch value.
extern int BattleMenuRemovePartyMember_UnknownRoleInitializedBytes;
// Original data: arm9/ov000 @ 0x02184288; shared HUD dispatch values.
extern unsigned BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[];
char* BattleScene_GetMenuController(char*);
void BattleMenu_RefreshPendingMemberPanel(void*);
int BattleMenu_HandleActorCommandMenuInput(char*);
int BattleMenu_HandleEnemyGroupTargetInput(char*,int,int);
int BattleMenu_HandleSpellListInput(char*,int,int);
int BattleMenu_HandleSkillListInput(char*,int,int);
int BattleMenu_HandleCarriedItemListInput(char*,int,int);
int BattleMenu_HandleAllyTargetInput(char*,int,int);
int BattleMenu_HandleVocationActionInput(char*,int,int);
int BattleMenu_DismissActorCommandMessage(char*,int,int);
int BattleMenu_CancelPartyCommandReview(char*);
}
struct CombatFlagByte { unsigned char low:3, enabled:1, mode:4; };

// Original: arm9/ov000 @ 0x021700DC; symbol: func_ov000_021700dc; size: 0x384.
// Checks member eligibility, advances its attention phase, and dispatches the current command-state input handler.
extern "C" int BattleMenu_UpdateMemberCommandState(char* self) {
    if(WORD(self,0x4c)<0)return -1;
    if(!(BYTE(self,0x24)&1))return -1;
    if(!HALF(self,0xc))return -1;
    if(BattleMenu_HasCommandBlockingStatus(self)) {
        BYTE(self+SBYTE(self,0x18),0x10)=100;return 100;
    }
    GameState* game=GameState::GetInstance();
    char* resources=GameState_ReadPResources();if(!resources)return -1;
    char* field=PTR(resources,0x3718);if(!field)return -1;
    char* scene=FieldBattle_GetScene(field);if(!scene)return -1;
    char* menu=BattleScene_GetMenuController(scene);if(!menu)return -1;
    GameObject* object=game->GetCombatantByIndex(WORD(menu,0x17c));
    if(object) {
        CombatFlagByte* flag=(CombatFlagByte*)((char*)object->currentStats_+0x3b);
        if(flag->enabled) {
            if(flag->mode==1)FLOAT(self,0x434)+=0.2f;
            else FLOAT(self,0x434)+=0.05f;
            if(FLOAT(self,0x434)>=3.141592f)FLOAT(self,0x434)=0.0f;
        }
    }
    BattleMenu_RefreshPendingMemberPanel(self);
    switch(SBYTE(self+SBYTE(self,0x18),0x10)) {
    case 13:return BattleMenu_HandleActorCommandMenuInput(self);
    case 14:return BattleMenu_HandleEnemyGroupTargetInput(self,BattleMenuRemovePartyMember_UnknownRoleInitializedBytes,BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[1]);
    case 15:return BattleMenu_HandleSpellListInput(self,BattleMenuRemovePartyMember_UnknownRoleInitializedBytes,BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[1]);
    case 16:return BattleMenu_HandleSkillListInput(self,BattleMenuRemovePartyMember_UnknownRoleInitializedBytes,BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[1]);
    case 17:return BattleMenu_HandleCarriedItemListInput(self,BattleMenuRemovePartyMember_UnknownRoleInitializedBytes,BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[1]);
    case 18:case 19:case 20:return BattleMenu_HandleAllyTargetInput(self,BattleMenuRemovePartyMember_UnknownRoleInitializedBytes,BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[1]);
    case 21:return BattleMenu_HandleVocationActionInput(self,BattleMenuRemovePartyMember_UnknownRoleInitializedBytes,BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[1]);
    case 26:return BattleMenu_DismissActorCommandMessage(self,BattleMenuRemovePartyMember_UnknownRoleInitializedBytes,BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[1]);
    case 27:return BattleMenu_DismissActorCommandMessage(self,BattleMenuRemovePartyMember_UnknownRoleInitializedBytes,BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[1]);
    case 28:return BattleMenu_DismissActorCommandMessage(self,BattleMenuRemovePartyMember_UnknownRoleInitializedBytes,BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[1]);
    case 29:return BattleMenu_DismissActorCommandMessage(self,BattleMenuRemovePartyMember_UnknownRoleInitializedBytes,BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[1]);
    case 30:return BattleMenu_DismissActorCommandMessage(self,BattleMenuRemovePartyMember_UnknownRoleInitializedBytes,BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[1]);
    case 37:return BattleMenu_DismissActorCommandMessage(self,BattleMenuRemovePartyMember_UnknownRoleInitializedBytes,BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[1]);
    case 38:return BattleMenu_DismissActorCommandMessage(self,BattleMenuRemovePartyMember_UnknownRoleInitializedBytes,BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[1]);
    case 39:return BattleMenu_DismissActorCommandMessage(self,BattleMenuRemovePartyMember_UnknownRoleInitializedBytes,BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[1]);
    case 40:return BattleMenu_DismissActorCommandMessage(self,BattleMenuRemovePartyMember_UnknownRoleInitializedBytes,BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[1]);
    case 100:return BattleMenu_CancelPartyCommandReview(self);
    default:return -1;
    }
}
