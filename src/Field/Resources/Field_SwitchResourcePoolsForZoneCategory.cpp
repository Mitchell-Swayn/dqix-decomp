#include <globaldefs.h>
#include <Resource/GameResources.h>
#include <World/Zone3D.h>
#pragma force_active on
ARM
extern "C" {
void GameResources_ReleasePoolsForMapKindsTwoAndThree(GameResources*);
void GameResources_ReleasePoolsForDefaultMapKind(GameResources*);
void GameResources_ReleasePoolsForMapKindFive(GameResources*);
void GameResources_ReleasePoolsForMapKindSix(GameResources*);
void GameResources_ReleasePoolsForMapKindSeven(GameResources*);
void GameResources_ReleasePoolsForMapKindEight(GameResources*);
void Graphics_AllocatePoolsAndReserveVram(char*);
void Graphics_InitializeTableDrivenAllocatorsAndVRAM(char*);
void Graphics_InitializeTableDrivenAllocatorAndVramReservations(char*);
void Graphics_InitializeIndexedAllocatorsAndVRAMReservations(char*);
void Graphics_AllocatePoolsReserveVramAndCopyState(char*);
void Graphics_InitializeAllocatorAndVramReservations(char*);
void OverlayLoader_ResetPrimarySelectionStack();
void OverlayLoader_ResetSecondarySelectionStack();
void OverlayLoader_PushPrimarySelection(unsigned);
void OverlayLoader_PushSecondarySelection(unsigned);
}
// Original: arm9/ov017 @ 0x0219DE70; symbol: func_ov017_0219de70; size: 0x18C.
// Changes resource-pool profile and overlay selections for the destination zone category.
extern "C" void Field_SwitchResourcePoolsForZoneCategory(GameResources* resources,const Zone3D_StructPtr_8* previous,const Zone3D_StructPtr_8* destination)
{
    unsigned kind=destination->unknown_c_low_;
    int next;
    if((unsigned)(kind-2)<=1) next=0;
    else if(kind==5) next=2;
    else if(kind==6) next=3;
    else if(kind==7) next=4;
    else if(kind==8) next=5;
    else next=1;
    int old=*(int*)(resources->unknown_2a78+0x90);
    if(old==next) return;
    switch(old) {
    case 0: GameResources_ReleasePoolsForMapKindsTwoAndThree(resources); break;
    case 1: GameResources_ReleasePoolsForDefaultMapKind(resources); break;
    case 3: GameResources_ReleasePoolsForMapKindFive(resources); break;
    case 4: GameResources_ReleasePoolsForMapKindSix(resources); break;
    case 2: GameResources_ReleasePoolsForMapKindSeven(resources); break;
    case 5: GameResources_ReleasePoolsForMapKindEight(resources); break;
    }
    *(int*)(resources->unknown_2a78+0x90)=next;
    switch(next) {
    case 0: Graphics_AllocatePoolsAndReserveVram((char*)resources); break;
    case 1: Graphics_InitializeTableDrivenAllocatorsAndVRAM((char*)resources); break;
    case 3: Graphics_InitializeTableDrivenAllocatorAndVramReservations((char*)resources); break;
    case 4: Graphics_InitializeIndexedAllocatorsAndVRAMReservations((char*)resources); break;
    case 2: Graphics_AllocatePoolsReserveVramAndCopyState((char*)resources); break;
    case 5: Graphics_InitializeAllocatorAndVramReservations((char*)resources); break;
    }
    OverlayLoader_ResetPrimarySelectionStack();
    OverlayLoader_ResetSecondarySelectionStack();
    int selected=*(int*)(resources->unknown_2a78+0x90);
    if(selected==0 || selected==2 || selected==5) {
        OverlayLoader_PushPrimarySelection(3);
        OverlayLoader_PushSecondarySelection(1);
    } else if(selected==1) {
        OverlayLoader_PushPrimarySelection(0);
        OverlayLoader_PushSecondarySelection(1);
    }
}
