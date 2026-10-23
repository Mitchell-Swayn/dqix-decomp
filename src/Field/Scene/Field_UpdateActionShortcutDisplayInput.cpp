#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
extern "C" {
int LinkedQueue_IsEmpty(void*);
void ResetUnknownObjectStateForSelectedCodes(void*);
GameStateIndexList* GameState_GetIndexList(GameState*);
int GameObject_GetUnknownFieldActionSelectorAt260(GameObject*);
int GameObject_IsMovementPauseActive(GameObject*);
int Input_IsKeyMaskNewlyPressed(void*,unsigned);
int Input_IsKeyMaskReleased(void*,unsigned);
int Input_TestKeyMask(void*,unsigned);
int GameObject_GetMovementInputEnabled(GameObject*);
int GameObject_HasQueuedActions(GameObject*);
void GameObject_DisableMovementInput(GameObject*,int);
void* SystemState_GetGlobalFlags();
void SystemState_SetFlags(void*,unsigned);
int SystemState_TestAnyFlags(void*,unsigned);
void Field_ReleaseGrottoMapPromptAndRestoreDisplay(void*);
void Graphics_InitializeRecordGridAndCanvasArrays(void*);
void Field_LoadActionShortcutDisplay(void*);
void Ov017_AllocateVRAMStagingEntries(void*,int,int);
void Tilemap_FillClippedRectangle(void*,unsigned,short,short,short,short,unsigned);
void Graphics_CleanAndTransferScreenBuffer(void*,int);
void Graphics_FreeVRAMStagingEntries(void*,int);
// Original data: arm9/main @ 0x02114E30; symbol: data_02114e30. Key repeater state.
extern char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
}
#pragma force_active on
// Original: arm9/ov017 @ 0x02199F08; symbol: func_ov017_02199f08; size: 0x280.
// Opens or closes the action shortcut display in response to key state and movement restrictions.
extern "C" void Field_UpdateActionShortcutDisplayInput(char* self) {
    if(!LinkedQueue_IsEmpty(*(void**)(self+0x36fc))) {ResetUnknownObjectStateForSelectedCodes(self);return;}
    GameState* game=GameState::GetInstance();
    game->GetProtagonist();
    GameObject* object=game->GetUnknownGameObject();
    GameStateIndexList* list=GameState_GetIndexList(game);
    int selector=GameObject_GetUnknownFieldActionSelectorAt260(object);
    if(selector==-1 && !GameObject_IsMovementPauseActive(object) && !*(int*)(self+0x4080)) {
        if(!Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2))return;
        if(!GameObject_GetMovementInputEnabled(object))return;
        if(*(unsigned*)((char*)object+0x18c)&1)return;
        if(GameObject_HasQueuedActions(object) || *(short*)((char*)object+0xac))return;
        GameObject_DisableMovementInput(object,1);
        *(short*)((char*)object+0xb2)=0;
        SystemState_SetFlags(SystemState_GetGlobalFlags(),0x400);
        Field_ReleaseGrottoMapPromptAndRestoreDisplay(self);
        // Preserve both saved BG control words and the signed halfword reads of
        // their local copies observed in the original register-save sequence.
        unsigned short background1=*(volatile unsigned short*)0x0400000a;
        **(unsigned short**)(self+0x3ca8)=background1;
        volatile short savedBackground1=background1;
        (void)savedBackground1;
        unsigned short background2=*(volatile unsigned short*)0x0400000c;
        volatile short savedBackground2=background2;
        (void)savedBackground2;
        **(unsigned short**)(self+0x3cac)=background2;
        (void)savedBackground2;
        Graphics_InitializeRecordGridAndCanvasArrays(self);
        *(int*)(self+0x4080)=1;
        return;
    }
    if(Input_IsKeyMaskReleased(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2) || *(short*)((char*)object+0xac) || GameObject_IsMovementPauseActive(object)) {
        ResetUnknownObjectStateForSelectedCodes(self);return;
    }
    if(selector!=-1)for(int i=0;i<list->count_;++i) {
        GameObject* member=game->GetPartyMemberByIndex(list->objectIndices_[i]);
        *(short*)((char*)member+0xac)=0;
    }
    if(SystemState_TestAnyFlags(SystemState_GetGlobalFlags(),4)){ResetUnknownObjectStateForSelectedCodes(self);return;}
    Field_LoadActionShortcutDisplay(self);
    if(Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2) && selector!=-1) {
        Ov017_AllocateVRAMStagingEntries(self+0x3cb4,2,0x800);
        void* entry;
        for(int i=0;i<2;++i) {
            entry=self+0x3cb4+i*32;
            Tilemap_FillClippedRectangle(entry,0,0,0,32,25,0);
            Graphics_CleanAndTransferScreenBuffer(entry,0);
        }
        Graphics_FreeVRAMStagingEntries(self+0x3cb4,2);
    }
}
#pragma force_active off
