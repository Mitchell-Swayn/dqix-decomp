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
struct CommandWindowPiece { short x;short y;unsigned short delay; };
struct CommandWindowOffsets { int values[7]; };
extern "C" {
// Original data: arm9/ov000 @ 0x021836B0; seven initial window-piece horizontal offsets.
extern const CommandWindowOffsets BattleMenuAdvanceCommandWindowTransition_UnknownRoleInitializedBytes;
void BattleMenu_RefreshPendingMemberPanel(void*);
void GameState_ResetFourSelectedRecordsAndOwnerState(char*);
}

// Original: arm9/ov000 @ 0x02180594; symbol: func_ov000_02180594; size: 0x408.
// Allocates and advances seven command-window pieces through entry, pause and staggered exit transitions.
extern "C" int BattleMenu_AdvanceCommandWindowTransition(char* self,int delta,SafeAllocator* allocator) {
    CommandWindowOffsets offsets=BattleMenuAdvanceCommandWindowTransition_UnknownRoleInitializedBytes;
    if(delta<=0)delta=1;
    if(WORD(self,0x910)<5 && allocator && !PTR(self,0x1d7c)) {
        *(CommandWindowPiece**)(self+0x1d7c)=(CommandWindowPiece*)allocator->Allocate(42);
        for(int i=0;i<7;++i) {
            (*(CommandWindowPiece**)(self+0x1d7c))[i].x=offsets.values[i]+256;
            (*(CommandWindowPiece**)(self+0x1d7c))[i].y=8;
            (*(CommandWindowPiece**)(self+0x1d7c))[i].delay=i*2;
        }
        UHALF(self,0x1d72)|=8;
    }
    if(WORD(self,0x910)==0) {
        WORD(self,0x914)=0;WORD(self,0x918)=0;WORD(self,0x91c)=0;++WORD(self,0x910);
        GameState_ResetFourSelectedRecordsAndOwnerState(self);UHALF(self,0x1d72)|=8;return 1;
    }
    if(WORD(self,0x910)==1) {
        WORD(self,0x914)=0;HALF(self,0x1d5e)-=delta*2;
        if(HALF(self,0x1d5e)<0){HALF(self,0x1d5e)=0;++WORD(self,0x910);}return 1;
    }
    if(WORD(self,0x910)==2) {
        if(UHALF(self,0x1d72)&32) {
            WORD(self,0x928)-=delta*16;
            if(WORD(self,0x928)<=86){WORD(self,0x928)=86;WORD(self,0x91c)=(WORD(self,0x91c)+delta)&63;WORD(self,0x910)=5;}
        }else if(UHALF(self,0x1d72)&16) {
            WORD(self,0x924)-=delta*16;
            if(WORD(self,0x924)<=92){WORD(self,0x924)=92;WORD(self,0x918)=(WORD(self,0x918)+delta)&63;WORD(self,0x910)=5;}
        }else if((UHALF(self,0x1d72)&8) && PTR(self,0x1d7c)) {
            int step=(int)(0.0f-1.5f*(float)(delta*16));
            for(int i=0;i<7;++i)(*(CommandWindowPiece**)(self+0x1d7c))[i].x+=step;
            if((*(CommandWindowPiece**)(self+0x1d7c))[0].x<=72) {
                for(int i=0;i<7;++i)(*(CommandWindowPiece**)(self+0x1d7c))[i].x=offsets.values[i]+72;
                WORD(self,0x914)=0;++WORD(self,0x910);
            }
        }return 1;
    }
    if(WORD(self,0x910)==3) {if(WORD(self,0x914)>=10)++WORD(self,0x910);return 1;}
    if(WORD(self,0x910)==4) {
        int completed;
        CommandWindowPiece* pieces=*(CommandWindowPiece**)(self+0x1d7c);
        if(!pieces) {
            WORD(self,0x92c)=(int)((float)WORD(self,0x92c)-1.5f*(float)(delta*4));
            if(WORD(self,0x92c)<-32)++WORD(self,0x910);
        }else {
            completed=0;
            int step=(int)(0.0f-1.5f*(float)(delta*4));
            for(int i=0;i<7;++i) {
                if(delta<pieces[i].delay)pieces[i].delay-=delta;
                else {pieces[i].delay=0;(*(CommandWindowPiece**)(self+0x1d7c))[i].y+=step;}
                pieces=*(CommandWindowPiece**)(self+0x1d7c);
                if(pieces[i].y<-32)++completed;
            }
            if(completed==7){PTR(self,0x1d7c)=0;++WORD(self,0x910);}
            if(completed>0)return 0;
        }return 1;
    }
    PTR(self,0x1d7c)=0;return 0;
}
