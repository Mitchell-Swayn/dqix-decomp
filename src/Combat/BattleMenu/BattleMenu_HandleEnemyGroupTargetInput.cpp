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
#include <Util/Random.h>
extern "C" {
int Selection_ReadEnabledIndexFromControl(void*);
int Input_IsKeyMaskNewlyPressed(void*,int);
int TestSelectedRecordReadyAndByteFlagBitOne(char*,int);
int BattleMenu_GetEnemyTargetGroupKey(void*,int);
int BattleMenu_CountEnemyTargetsWithGroupKey(void*,int);
void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
void BattleMenu_RefreshMemberCommandLabel(char*);
int System_TestNewInputMaskOrStateModeTwo(char*);
void BattleMenu_PopSelectionPanels(char*);
void BattleMenu_ConfigureActorCommandSelection(char*,int,int);
void BattleMenu_RefreshExistingPanel(void*,void*,int,int,int,int);
// Original data: arm9/ov000 @ 0x02184294; shared menu argument slots.
extern int BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x02114e30; input repeater state.
extern char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x02108760; sound state.
extern char Main_UnknownRoleZeroInitializedStorage[];
}
// Original: arm9/ov000 @ 0x0217B380; symbol: func_ov000_0217b380; size: 0x198.
// Confirms an enemy-group target, randomizes touched-group members, or restores the previous command panel.
extern "C" int BattleMenu_HandleEnemyGroupTargetInput(char* record,int a,int b) {
    UHALF((char*)BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[2],0x1d72)|=256;
    int selected=Selection_ReadEnabledIndexFromControl(PTR(record,0x38));
    BYTE(record,0x1d)=selected;
    bool confirm=Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x601) | TestSelectedRecordReadyAndByteFlagBitOne((char*)PTR(record,0x38),20);
    if(confirm) {
        if(TestSelectedRecordReadyAndByteFlagBitOne((char*)PTR(record,0x38),20)) {
            int key=BattleMenu_GetEnemyTargetGroupKey((void*)BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[2],selected);
            int count=BattleMenu_CountEnemyTargetsWithGroupKey((void*)BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[2],key);
            BYTE(record,0x1d)=NextRandomMax(GetBTRandom(),count*100)/100+(signed char)selected;
        }
        SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
        ++SBYTE(record,0x18);
        BYTE(record+SBYTE(record,0x18),0x10)=100;
        BattleMenu_RefreshMemberCommandLabel(record);
    } else if(System_TestNewInputMaskOrStateModeTwo(record)) {
        BattleMenu_PopSelectionPanels(record);
        BYTE(record+SBYTE(record,0x18),0x10)=0;
        --SBYTE(record,0x18);
        SBYTE(record,0x1d)=-1;
        BattleMenu_ConfigureActorCommandSelection(record,a,b);
        BattleMenu_RefreshExistingPanel((void*)BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[2],record,SBYTE(record+SBYTE(record,0x18),0x10),BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[1],BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[0],0);
    }
    return -1;
}
