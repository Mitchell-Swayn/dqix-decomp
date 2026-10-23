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
struct IndexedFlagNibble { unsigned char active:4,other:4; };
extern "C" {
unsigned char BattleMenu_IsPartyPanelEnabled(const void*);
unsigned GameState_ComputeTwelveBitObjectAttributeMask(unsigned);
unsigned GameState_AddLinkedObjectCategoryBit(int,unsigned);
unsigned GameState_CountSetBitsInWord68(void*);
void Window_SetCanvasActiveWhileProgressIncomplete(int,int,int,void*);
void ResetAllocatorAndStateWithDisabledEntryFlag(void*,int);
void Memory_SafeAllocatorCreateTypeAWith800ByteAllocation(void*,SafeAllocator*);
}

// Original: arm9/ov000 @ 0x0217CE24; symbol: func_ov000_0217ce24; size: 0x500.
// Counts eligible party panels and routes party options into individual commands, equipment, tactics or the session allocator.
extern "C" void BattleMenu_HandlePartyOptionsInput(char* self,int a,int b) {
    Zone3D_GetMainInstance();UHALF(self,0x1d72)|=256;
    int selected=Selection_ReadEnabledIndexFromControl(self+0x188);if(selected<0)selected=0;
    BYTE(self,0x1d6a)=selected;
    if(BattleMenu_TestConfirmInputAfterDelay((unsigned char*)self,5)) {
        BYTE(self,0x956)=0;SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
        GameState* game=GameState::GetInstance();char* list=GameState_GetIndexList(game);
        signed char enabled=0;int linked=0;unsigned char count=BYTE(list,0xf7c);
        for(unsigned char i=0;i<count;++i) {
            int id=SBYTE(list+i,0xf78);
            GameObject* object=GameState_GetObjectWithFlag100(game,id);if(!object)continue;
            char* state=PTR((char*)object,0x150);
            bool active=state?((IndexedFlagNibble*)(state+0x56b))->active!=0:false;
            if(active)linked=1;
            char* record=BattleMenu_FindPartyCommandRecord(self,id);
            if(record && BattleMenu_IsPartyPanelEnabled(record))++enabled;
        }
        if(BYTE(self,0x79)<enabled)enabled=BYTE(self,0x79);
        switch(SBYTE(self,0x1d6a)) {
        case 0:
            BattleMenu_RefreshPanelForActiveMode(self,0,SBYTE(self+SBYTE(self,0x1d68),0x1d60),a,b);
            if(BYTE(list,0xf7c)==1 || linked || BYTE(self,0x1d78) || enabled==1) {
                BYTE(self,0x1d6b)=0;++SBYTE(self,0x1d68);BYTE(self+SBYTE(self,0x1d68),0x1d60)=12;
                BattleMenu_OpenPanelForSelectionState(self,BattleMenu_GetSelectedPartyCommandRecord(self),12,a,b);
            }else {
                BYTE(self,0x1d6b)=0;++SBYTE(self,0x1d68);BYTE(self+SBYTE(self,0x1d68),0x1d60)=3;
                BattleMenu_OpenPanelForSelectionState(self,BattleMenu_GetSelectedPartyCommandRecord(self),3,a,b);
            }break;
        case 1:
            BattleMenu_RefreshPanelForActiveMode(self,0,SBYTE(self+SBYTE(self,0x1d68),0x1d60),a,b);
            BYTE(self,0x1d6e)=0;BYTE(self,0x1d6b)=0;++SBYTE(self,0x1d68);BYTE(self+SBYTE(self,0x1d68),0x1d60)=5;
            if(BYTE(list,0xf7c)==1 || linked || enabled==1) {
                signed char id=GameState_ReadProtagonistObjectIndex(game);
                UWORD(self,0x68)=GameState_ComputeTwelveBitObjectAttributeMask(id);
                UWORD(self,0x68)=GameState_AddLinkedObjectCategoryBit(id,UWORD(self,0x68));
                BYTE(self+SBYTE(self,0x1d68),0x1d60)=6;
                if(!UWORD(self,0x68)) {
                    BYTE(self+SBYTE(self,0x1d68),0x1d60)=43;
                    BattleMenu_OpenPanelForSelectionState(self,BattleMenu_FindPartyCommandRecord(self,id),43,a,b);break;
                }
            }
            BattleMenu_OpenPanelForSelectionState(self,BattleMenu_GetSelectedPartyCommandRecord(self),SBYTE(self+SBYTE(self,0x1d68),0x1d60),a,b);
            Window_SetCanvasActiveWhileProgressIncomplete(6,GameState_CountSetBitsInWord68(self),4,self+0x188);break;
        case 2:
            BYTE(self,0x79)=enabled;
            BattleMenu_RefreshPanelForActiveMode(self,0,SBYTE(self+SBYTE(self,0x1d68),0x1d60),a,b);
            BYTE(self,0x1d6b)=0;++SBYTE(self,0x1d68);BYTE(self+SBYTE(self,0x1d68),0x1d60)=8;
            BattleMenu_OpenPanelForSelectionState(self,BattleMenu_GetSelectedPartyCommandRecord(self),8,a,b);break;
        case 3:
            BattleMenu_RefreshExistingPanel(self,0,SBYTE(self+SBYTE(self,0x1d68),0x1d60),a,b,1);
            ++SBYTE(self,0x1d68);BYTE(self+SBYTE(self,0x1d68),0x1d60)=9;
            ((SafeAllocator*)(self+0x1af8))->Reset();
            ResetAllocatorAndStateWithDisabledEntryFlag(self+0x7c,(signed char)WORD(self,0x17c));
            Memory_SafeAllocatorCreateTypeAWith800ByteAllocation(self+0x7c,(SafeAllocator*)(self+0x1af8));
            BYTE(self,0xb3)|=8;break;
        }
    }else if(BattleMenu_TestCancelInput(self)) {
        BYTE(self,0x956)=0;Window_PopCanvasesAndResetSelection(self+0x188,0);
        BYTE(self+SBYTE(self,0x1d68),0x1d60)=0;--SBYTE(self,0x1d68);
        BattleMenu_ConfigureGlobalCommandSelection(self,a,b);
    }
}
