#include <globaldefs.h>
ARM
#pragma force_active on
#define WORD(p,o) (*(int*)((p)+(o)))
#define UWORD(p,o) (*(unsigned*)((p)+(o)))
#define HALF(p,o) (*(short*)((p)+(o)))
#define UHALF(p,o) (*(unsigned short*)((p)+(o)))
#define BYTE(p,o) (*(unsigned char*)((p)+(o)))
#define SBYTE(p,o) (*(signed char*)((p)+(o)))
#define PTR(p,o) (*(char**)((p)+(o)))
#include <GameState/GameState.h>
extern "C" {
// Original data: arm9/ov000 @ 0x02184294; shared command-menu references.
extern unsigned BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x02114E30; key input state.
extern char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x02108760; sound state.
extern char Main_UnknownRoleZeroInitializedStorage[];
int Selection_ReadEnabledIndexFromControl(void*);
void Window_SetCanvasEnabled(unsigned char*,int,int);
int Input_IsKeyMaskNewlyPressed(void*,int);
int TestSelectedRecordReadyAndByteFlagBitOne(char*,int);
void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
char* GameObject_GetLinkedIndexedState(GameObject*);
void BattleMenu_ConfirmSelectedSpell(char*);
void BattleMenu_ConfirmSelectedAbility(char*);
void BattleMenu_AdvanceSelectedActionTargeting(char*);
int BattleMenu_IsSkillEquipmentCompatible(char*,int);
int System_TestNewInputMaskOrStateModeTwo(char*);
void BattleMenu_PopSelectionPanels(char*);
void BattleMenu_ConfigureActorCommandSelection(char*,int,int);
void BattleMenu_RefreshExistingPanel(char*,char*,int,int,int,int);
char* ActionData_GetGlobalTables();
char* ActionData_FindDefinitionInPrimaryOrSecondaryTable(char*,int);
// Original data: arm9/ov000 @ 0x02183658; vocation-indexed action keys.
extern short BattleMenuHandleVocationActionInput_UnknownRoleDataReferences[];
}

// Original: arm9/ov000 @ 0x0217BDF4; symbol: func_ov000_0217bdf4; size: 0x1C8.
// Resolves the selected member vocation action and advances targeting, or restores the previous panel on cancel.
struct ActionIdWord {unsigned id:12;unsigned other:20;};
extern "C" int BattleMenu_HandleVocationActionInput(char* self,int a,int b) {
    UHALF((char*)BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[2],0x1d72)|=256;
    BYTE(self,0x23)=Selection_ReadEnabledIndexFromControl(PTR(self,0x38));
    char* menu=(char*)BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[2];
    Window_SetCanvasEnabled((unsigned char*)menu+0x188,1,22);
    int pressed=Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x601);
    bool confirm=(pressed|TestSelectedRecordReadyAndByteFlagBitOne(PTR(self,0x38),20))!=0;
    if(confirm || BYTE(self,0x444)) {
        GameObject* object=GameState::GetInstance()->GetPartyMemberByIndex(WORD(self,0x4c));
        if(!object)return -1;
        int vocation=WORD(GameObject_GetLinkedIndexedState(object),0x950);
        SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
        BYTE(self,0x1d)=0;
        char* tables=ActionData_GetGlobalTables();
        if(!tables)return -1;
        char* action=ActionData_FindDefinitionInPrimaryOrSecondaryTable(tables,BattleMenuHandleVocationActionInput_UnknownRoleDataReferences[vocation]);
        if(!action)return -1;
        UHALF(self,0x26)=((ActionIdWord*)(action+4))->id;
        BattleMenu_AdvanceSelectedActionTargeting(self);
        Window_SetCanvasEnabled((unsigned char*)menu+0x188,0,22);
        return SBYTE(self+SBYTE(self,0x18),0x10);
    }

    if(System_TestNewInputMaskOrStateModeTwo(self)) {
        BattleMenu_PopSelectionPanels(self);
        BYTE(self+SBYTE(self,0x18),0x10)=0;
        --SBYTE(self,0x18);
        SBYTE(self,0x23)=-1; SBYTE(self,0x1d)=-1;
        UHALF(self,0x26)=0;
        BattleMenu_ConfigureActorCommandSelection(self,a,b);
        unsigned* refs=BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage;
        BattleMenu_RefreshExistingPanel((char*)refs[2],self,SBYTE(self+SBYTE(self,0x18),0x10),refs[1],refs[0],0);
    }
    return -1;
}
