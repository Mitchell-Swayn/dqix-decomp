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
void Window_SetCanvasEnabled(void*,int,int);
int Input_IsKeyMaskNewlyPressed(void*,int);
int TestSelectedRecordReadyAndByteFlagBitOne(char*,int);
void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
int System_TestNewInputMaskOrStateModeTwo(char*);
void BattleMenu_PopSelectionPanels(char*);
void BattleMenu_ConfigureActorCommandSelection(char*,int,int);
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
void GameState_ProcessEligibleListedMemberRecords(char*);
void BattleMenu_ResetPanelsToFirstEligibleMember(char*);
}
extern "C" {
int FindSetFlagIndexByOrdinal(char*,int);
int TestMemberCurrentValueAgainstGroupedEntries(char*,int,unsigned char,short*,unsigned short*);
void _ZN16BackgroundLoader13AddLockGlobalEv();
void _ZN16BackgroundLoader16RemoveLockGlobalEv();
void _ZN13SafeAllocator5ResetEv(void*);
void _ZN13ZoneState27545ResetEv(void*);
void _ZN13ZoneState275412BuildForKeysEP13SafeAllocatorPvjPKst(void*,void*,void*,unsigned,const short*,unsigned short);
void* Filesystem_ExtractLocalizedGp2FileToScratch(void*,void*,unsigned*);
int BattleMenu_HasCommandBlockingStatus(char*);
void BattleMenu_RefreshSelectedPartyPanelExpansion(char*);
void Window_SetCanvasActiveWhileProgressIncomplete(int,int,int,char*);
// Original data: arm9/main @ 0x020F2A34 and 0x020F2A2C; equipment resource references.
extern void* BattleMenuHandleEquipmentCategoryInput_UnknownRoleDataReferences_Variant2;
extern void* BattleMenuHandleEquipmentCategoryInput_UnknownRoleDataReferences;
}

// Original: arm9/ov000 @ 0x0217D87C; symbol: func_ov000_0217d87c; size: 0x2D0.
// Loads the selected equipment category and opens its choices, or restores the eligible member and command panels on cancel.
extern "C" void BattleMenu_HandleEquipmentCategoryInput(char* self,int a,int b) {
    UHALF(self,0x1d72)|=256;
    int previous=SBYTE(self,0x1d6e);
    int selected=Selection_ReadEnabledIndexFromControl(self+0x188);
    BYTE(self,0x1d6e)=selected;
    int member=SBYTE(self+SBYTE(self,0x1d6b),0x70);
    if(previous!=selected)return;
    if(BattleMenu_TestConfirmInputAfterDelay((unsigned char*)self,5)) {
        BYTE(self,0x956)=0;
        char* list=GameState_GetIndexList(GameState::GetInstance());
        int category=FindSetFlagIndexByOrdinal(self,SBYTE(self,0x1d6e));
        if(TestMemberCurrentValueAgainstGroupedEntries(list+0x1d4,member,(unsigned char)category,(short*)(self+0x26),(unsigned short*)(self+0x66)))return;
        BYTE(self,0x240)=6;
        SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
        _ZN16BackgroundLoader13AddLockGlobalEv();
        _ZN13SafeAllocator5ResetEv(self+0x1af8);
        _ZN13ZoneState27545ResetEv(self+0x100);
        unsigned size;
        void* data=Filesystem_ExtractLocalizedGp2FileToScratch(BattleMenuHandleEquipmentCategoryInput_UnknownRoleDataReferences_Variant2,BattleMenuHandleEquipmentCategoryInput_UnknownRoleDataReferences,&size);
        if(data)_ZN13ZoneState275412BuildForKeysEP13SafeAllocatorPvjPKst(self+0x100,self+0x1af8,data,size,(short*)(self+0x26),UHALF(self,0x66));
        _ZN16BackgroundLoader16RemoveLockGlobalEv();
        BYTE(self,0x1d6f)=0;
        ++SBYTE(self,0x1d68);
        BYTE(self+SBYTE(self,0x1d68),0x1d60)=7;
        BattleMenu_OpenPanelForSelectionState(self,BattleMenu_GetSelectedPartyCommandRecord(self),7,a,b);
        Window_SetCanvasActiveWhileProgressIncomplete(7,HALF(self,0x66),4,self+0x188);
    } else if(BattleMenu_TestCancelInput(self)) {
        BYTE(self,0x956)=0;
        char* record=BattleMenu_FindPartyCommandRecord(self,member);
        if(!record)return;
        if(BattleMenu_HasCommandBlockingStatus(record)) {
            BYTE(record+SBYTE(record,0x18),0x10)=100;
            BYTE(record,0x24)&=~4;
        }
        unsigned char count=BYTE(GameState_GetIndexList(GameState::GetInstance()),0xf7c);
        for(unsigned char i=0;i<count;++i) {
            int member=SBYTE(self+i,0x70);
            char* record=BattleMenu_FindPartyCommandRecord(self,member);
            if(record && !BattleMenu_HasCommandBlockingStatus(record) && BYTE(record,0x87)) {
                WORD(self,0x17c)=member;
                break;
            }
        }
        BattleMenu_RefreshSelectedPartyPanelExpansion(self);
        Window_PopCanvasesAndResetSelection(self+0x188,0);
        BYTE(self+SBYTE(self,0x1d68),0x1d60)=0;
        --SBYTE(self,0x1d68);
        BattleMenu_ConfigureGlobalCommandSelection(self,a,b);
        Window_SetCanvasEnabled(self+0x188,1,1);
        Window_SetCanvasEnabled(self+0x188,1,2);
        Window_SetCanvasEnabled(self+0x188,1,5);
    }
}
