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
struct Entry;
extern "C" {
void Window_SetCanvasDisplayAttribute(unsigned char*,int,int);
int Selection_ReadEnabledIndexFromControl(void*);
bool BattleMenu_TestConfirmInputAfterDelay(unsigned char*,int);
void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
void* BattleMenu_FindSelectedEquipmentRecord(char*);
int BattleMenu_GetSelectedEquipmentMemberIndex(char*);
void Equipment_GetPartyRestrictionMask(int,void*);
Entry* BattleMenu_GetSelectedPartyCommandRecord(char*);
void BattleMenu_OpenPanelForSelectionState(void*,void*,int,int,int);
int BattleMenu_TestCancelInput(void*);
void Window_PopCanvasesAndResetSelection(void*,int);
void BattleMenu_ConfigureGlobalCommandSelection(char*,int,int);
void BattleMenu_RefreshExistingPanel(void*,void*,int,int,int,int);
// Original data: arm9/main @ 0x02108760; sound state.
extern char Main_UnknownRoleZeroInitializedStorage[];
}
// Original: arm9/ov000 @ 0x0217DB4C; symbol: func_ov000_0217db4c; size: 0x1A4.
// Confirms or cancels the unchanged equipment selection and opens or restores its command panel.
extern "C" void BattleMenu_HandleEquipmentItemInput(char* self,int a,int b) {
    UHALF(self,0x1d72)|=256;
    Window_SetCanvasDisplayAttribute((unsigned char*)self+0x188,33,0);
    int previous=SBYTE(self,0x1d6f);
    int selected=Selection_ReadEnabledIndexFromControl(self+0x188);
    BYTE(self,0x1d6f)=selected;
    if(previous!=selected) return;
    if(BattleMenu_TestConfirmInputAfterDelay((unsigned char*)self,5)) {
        BYTE(self,0x956)=0;
        SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
        BYTE(self,0x240)=7;
        void* equipment=BattleMenu_FindSelectedEquipmentRecord(self);
        Equipment_GetPartyRestrictionMask(BattleMenu_GetSelectedEquipmentMemberIndex(self),equipment);
        ++SBYTE(self,0x1d68);
        BYTE(self+SBYTE(self,0x1d68),0x1d60)=32;
        Entry* record=BattleMenu_GetSelectedPartyCommandRecord(self);
        BattleMenu_OpenPanelForSelectionState(self,record,SBYTE(self+SBYTE(self,0x1d68),0x1d60),a,b);
    } else if(BattleMenu_TestCancelInput(self)) {
        BYTE(self,0x956)=0;
        Window_PopCanvasesAndResetSelection(self+0x188,0);
        Window_PopCanvasesAndResetSelection(self+0x188,0);
        BYTE(self+SBYTE(self,0x1d68),0x1d60)=0;
        --SBYTE(self,0x1d68);
        BattleMenu_ConfigureGlobalCommandSelection(self,a,b);
        Entry* record=BattleMenu_GetSelectedPartyCommandRecord(self);
        BattleMenu_RefreshExistingPanel(self,record,SBYTE(self+SBYTE(self,0x1d68),0x1d60),a,b,0);
    }
}
