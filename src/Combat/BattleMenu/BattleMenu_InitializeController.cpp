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
int TestSelectedRecordReadyAndByteFlagBitOne(char*,int);
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
// Original data: arm9/ov000 @ 0x02184288; shared battle HUD/menu state.
extern unsigned BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[];
void Grid_InitializeDirectionalSelection(void*);
void Graphics_InitializeCanvasTransferState(void*);
void Selection_InitializeDisplayController(void*);
void TextCanvas_InitializeLayoutAndTransferDefaults(void*);
void Graphics_InitializeSpriteResourceBuffers(void*);
void ResetAllocatorAndStateWithDisabledEntryFlag(void*,int);
void* Network_GetConnectionManager();
void _ZN13ZoneState27545ResetEv(void*);
void BattleMenu_RefreshPartySlotMappings(char*);
void TextSprite_ResetDrawRequest(char*);
void BattleMenu_ResetMemberWorkspace(char*);
void BattleMenu_SetPartyCommandListMembership(char*,int,int);
void BattleMenu_UpdateMemberRowPositions(char*);
}
struct ControllerFlags { unsigned short bit0:1,bit1:1,rest:14; };

// Original: arm9/ov000 @ 0x021723A8; symbol: func_ov000_021723a8; size: 0x378.
// Initializes allocators, menu controllers, animation state and all four indexed member workspaces.
extern "C" void BattleMenu_InitializeController(char* self,SafeAllocator* allocator) {
    WORD(self,0x20)=-1;
    ((SafeAllocator*)(self+0x1a78))->ResetAllocatorPointer();
    ((SafeAllocator*)(self+0x1a8c))->ResetAllocatorPointer();
    ((SafeAllocator*)(self+0x1ab4))->ResetAllocatorPointer();
    ((SafeAllocator*)(self+0x1aa0))->ResetAllocatorPointer();
    ((SafeAllocator*)(self+0x1ac8))->ResetAllocatorPointer();
    ((SafeAllocator*)(self+0x1adc))->ResetAllocatorPointer();
    ((SafeAllocator*)(self+0x1af8))->ResetAllocatorPointer();
    _ZN13ZoneState27545ResetEv(self+0xd0);
    _ZN13ZoneState27545ResetEv(self+0xe8);
    BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[2]=(unsigned)self;
    WORD(self,0x68)=0;WORD(self,0x178)=0;WORD(self,0x17c)=-1;
    UHALF(self,0x1d72)=0;((ControllerFlags*)(self+0x1d72))->bit1=1;WORD(self,0x184)=0;
    volatile short bg0,bg1;
    unsigned short raw=*(volatile unsigned short*)0x04001008;
    bg0=raw;UHALF(self,0x180)=raw;(void)bg0;
    raw=*(volatile unsigned short*)0x0400100a;
    bg1=raw;UHALF(self,0x182)=raw;(void)bg1;
    Graphics_InitializeCanvasTransferState(self+0x8a4);
    Graphics_InitializeCanvasTransferState(self+0x8c4);
    Graphics_InitializeCanvasTransferState(self+0x8e4);
    Selection_InitializeDisplayController(self+0x188);
    Grid_InitializeDirectionalSelection(self+0x244);
    for(int i=0;i<7;++i)TextCanvas_InitializeLayoutAndTransferDefaults(self+0x284+i*0xe0);
    *(SafeAllocator**)(self+0x1af0)=allocator;
    ResetAllocatorAndStateWithDisabledEntryFlag(self+0x7c,0);
    Graphics_InitializeSpriteResourceBuffers(self+0x11c);
    WORD(self,0x170)=0;WORD(self,0x174)=0;WORD(self,0x910)=0;WORD(self,0x934)=0;WORD(self,0x908)=0;WORD(self,0x90c)=-1;
    WORD(self,0x914)=0;WORD(self,0x918)=0;WORD(self,0x91c)=0;
    WORD(self,0x920)=256;WORD(self,0x924)=256;WORD(self,0x928)=256;WORD(self,0x92c)=0;
    UHALF(self,0x1d5e)=16;WORD(self,0x93c)=0;WORD(self,0x940)=0;WORD(self,0x944)=0;
    memset(self+0x1d60,0,8);
    BYTE(self,0x1d68)=0;BYTE(self+SBYTE(self,0x1d68),0x1d60)=1;
    BYTE(self,0x1d69)=0;SBYTE(self,0x1d6b)=-1;SBYTE(self,0x1d6c)=-1;SBYTE(self,0x1d6e)=-1;SBYTE(self,0x1d6f)=-1;
    BYTE(self,0x1d70)=0;BYTE(self,0x1d79)=1;BYTE(self,0x1d80)=0;BYTE(self,0x1d81)=0;BYTE(self,0x1d5c)=0;BYTE(self,0x1d7a)=0;
    GameState* game=GameState::GetInstance();Network_GetConnectionManager();
    int protagonist=GameState_ReadProtagonistObjectIndex(game);if(protagonist<0)protagonist=0;
    WORD(self,0x17c)=protagonist;
    BattleMenu_RefreshPartySlotMappings(self);
    TextSprite_ResetDrawRequest(self+0x1b54);TextSprite_ResetDrawRequest(self+0x1b6c);
    for(int i=0;i<9;++i)TextSprite_ResetDrawRequest(self+0x1b84+i*24);
    for(int i=0;i<3;++i)TextSprite_ResetDrawRequest(self+0x1b0c+i*24);
    for(int i=0;i<8;++i)TextSprite_ResetDrawRequest(self+0x1c5c+i*24);
    char* record;
    for(int i=0;i<4;++i) {
        record=self+0x958+SBYTE(self+i,0x6c)*0x448;
        BattleMenu_ResetMemberWorkspace(record);
        WORD(record,0x44)=0;WORD(record,0x48)=0;
        PTR(record,0x38)=self+0x188;PTR(record,4)=self+0xb8;PTR(record,0)=self+0xd0;
    }
    BattleMenu_SetPartyCommandListMembership(self,0,-1);
    BattleMenu_SetPartyCommandListMembership(self,1,GameState_ReadProtagonistObjectIndex(game));
    BattleMenu_UpdateMemberRowPositions(self);
    PTR(self,0x1d7c)=0;BYTE(self,0x1d78)=0;WORD(self,0x950)=0;BYTE(self,0x954)=0;BYTE(self,0x955)=0;BYTE(self,0x956)=0;
}
