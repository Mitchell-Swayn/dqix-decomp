#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
ARM
#pragma force_active on
#pragma optimization_level 4
#pragma opt_common_subs off
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
struct ActionDefinition { unsigned name; unsigned identifier:12; unsigned other:20; unsigned unused:8; unsigned targetKind:2; unsigned rest:22; };
extern "C" {
char* ActionData_GetGlobalTables();
ActionDefinition* ActionData_FindDefinitionInPrimaryOrSecondaryTable(char*,int);
void BattleMenu_PushActionDefinitionSelectionState(char*);
}

// Original: arm9/ov000 @ 0x0217E558; symbol: func_ov000_0217e558; size: 0x318.
// Applies a shared action or no-action command to listed members and opens target selection when required.
extern "C" void BattleMenu_HandleSharedPartyActionInput(char* self,int a,int b) {
    UHALF(self,0x1d72)|=256;
    BYTE(self,0x1d6d)=Selection_ReadEnabledIndexFromControl(self+0x188);
    Window_SetCanvasEnabled(self+0x188,1,24);
    Window_SetCanvasDisplayAttribute(self+0x188,24,0);
    GameState* game=GameState::GetInstance();
    char* scene=FieldBattle_GetScene(PTR(GameState_ReadPResources(),0x3718));
    if(SBYTE(scene,0x7712)!=-1)return;
    if(!BattleMenu_TestConfirmInputAfterDelay((unsigned char*)self,5))return;
    BYTE(self,0x956)=0;
    SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
    if(!UHALF(self+SBYTE(self,0x1d6d)*2,0x10)) {
        ++SBYTE(self,0x1d68);
        BYTE(self+SBYTE(self,0x1d68),0x1d60)=100;
        char* list=GameState_GetIndexList(game);
        unsigned char count=BYTE(list,0xf7c);
        for(unsigned char i=0;i<count;++i) {
            char* record=BattleMenu_FindPartyCommandRecord(self,SBYTE(list+i,0xf78));
            if(record) {
                signed char target=SBYTE(record,0x1d);
                BYTE(record,0x1d)=target;
                UHALF(record,0x26)=0;
                signed char ally=SBYTE(record,0x2e);
                BYTE(record,0x2e)=ally;
                BYTE(record+SBYTE(record,0x18),0x10)=100;
                BattleMenu_RefreshMemberCommandLabel((unsigned char*)record);
            }
        }
    } else {
        signed char selectedAlly;
        GameState* currentGame;
        ActionDefinition* action;
        char* list;
        signed char target;int ally;unsigned char count;
        char* tables=ActionData_GetGlobalTables();if(!tables)return;
        action=ActionData_FindDefinitionInPrimaryOrSecondaryTable(tables,HALF(self+SBYTE(self,0x1d6d)*2,0x10));if(!action)return;
        BattleMenu_PushActionDefinitionSelectionState(self);
        currentGame=GameState::GetInstance();
        list=GameState_GetIndexList(currentGame);
        char* leader=BattleMenu_FindPartyCommandRecord(self,GameState_ReadProtagonistObjectIndex(currentGame));if(!leader)return;
        signed char* modes=(signed char*)self+0x1d60;
        int depth=SBYTE(self,0x1d68);
        switch(modes[depth]) {
        case 14:modes[depth]=25;BYTE(self,0x1d79)=0;break;
        case 18:case 19:modes[depth]=100;break;
        }
        target=-1;ally=-1;
        unsigned kind=action->targetKind;
        if(kind==1)target=SBYTE(leader,0x1d);
        if(kind==2)ally=SBYTE(leader,0x2e);
        count=BYTE(list,0xf7c);
        selectedAlly=ally;
        for(unsigned char i=0;i<count;++i) {
            char* record=BattleMenu_FindPartyCommandRecord(self,SBYTE(list+i,0xf78));
            if(record) {
                SBYTE(record,0x1d)=target;
                UHALF(record,0x26)=action->identifier;
                SBYTE(record,0x2e)=selectedAlly;
                BYTE(record+SBYTE(record,0x18),0x10)=SBYTE(self+SBYTE(self,0x1d68),0x1d60);
                BattleMenu_RefreshMemberCommandLabel((unsigned char*)record);
            }
        }
    }
    if(SBYTE(self+SBYTE(self,0x1d68),0x1d60)==25) {
        unsigned* refs=BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage;
        BattleMenu_RefreshExistingPanel(self,0,23,refs[1],refs[0],1);
        BYTE(self,0x1c)=0;
        BattleMenu_OpenPanelForSelectionState(self,BattleMenu_GetSelectedPartyCommandRecord(self),25,a,b);
    }
}
