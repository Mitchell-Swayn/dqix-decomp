#include <globaldefs.h>
#include <Resource/GameResources.h>
#include <Graphics/VRAMAllocations.h>
#include <Graphics/VRAMStaging.h>
#include <System/VRAM.h>
ARM
#pragma always_inline on
struct WordPair{unsigned words[2];};
struct ImageState{unsigned words[10];};struct State{ImageState current,saved;unsigned imageKey,imageAmount;TexturePaletteVRAMState palette,paletteSaved;unsigned paletteKey,paletteAmount;};
extern "C" {
void* Graphics_GetGlobalOamTransferState();
unsigned Graphics_GetBackgroundResourceOwner();
void TextureVRAM_SnapshotAllocationBounds(char*);
void Graphics_InitializeSubOamStagingState(char*);
void TextCache_UploadShadedObjPalettes(unsigned char*);
void Field_ResetSessionTransitionLatch(unsigned char*);
void Graphics_RestoreTextureImageAndPaletteVRAMState(const unsigned char*);
void VRAM_SaveStateAndReserveImagePaletteBytes(State*,unsigned,unsigned);
void Object_InvokeSaveTextureImageVRAMState(char*);
}
// Original: arm9/ov000 @ 0x02164280; symbol: BattleScene_PrepareDisplayAndVram; size: 0x154.
extern "C" void BattleScene_PrepareDisplayAndVram(unsigned char* self){
GameResources* resources=GameResources_GetInstance();void* oam=Graphics_GetGlobalOamTransferState();unsigned background=Graphics_GetBackgroundResourceOwner();
LockStagedTextureVRAMCopying();MapVRAMBanksToTextureImage(7);InitializeTextureImageVRAM(3,true);MapVRAMBanksToSubObj(8);
volatile unsigned* display=(volatile unsigned*)0x04001000;*display=(*display&0xffcfffef)|0x200010;
MapVRAMBanksToSubBG(0x180);
*(ImageState*)(self+0x14c)=*(ImageState*)((char*)resources+0xe9c);
*(ImageState*)(self+0x174)=*(ImageState*)((char*)resources+0xec4);
*(unsigned*)(self+0x19c)=*(unsigned*)((char*)resources+0xeec);
*(unsigned*)(self+0x1a0)=*(unsigned*)((char*)resources+0xef0);
*(WordPair*)(self+0x1a4)=*(WordPair*)((char*)resources+0xef4);
*(WordPair*)(self+0x1ac)=*(WordPair*)((char*)resources+0xefc);
*(unsigned*)(self+0x1b4)=*(unsigned*)((char*)resources+0xf04);
*(unsigned*)(self+0x1b8)=*(unsigned*)((char*)resources+0xf08);
TextureVRAM_SnapshotAllocationBounds((char*)self+0x14c);
Graphics_InitializeSubOamStagingState((char*)oam);TextCache_UploadShadedObjPalettes((unsigned char*)background);Field_ResetSessionTransitionLatch((unsigned char*)resources);
TextureVRAM_SnapshotAllocationBounds((char*)resources+0x2cc);Graphics_RestoreTextureImageAndPaletteVRAMState((unsigned char*)resources+0x2cc);
VRAM_SaveStateAndReserveImagePaletteBytes((State*)(self+0x36f0),0x18000,0x800);Object_InvokeSaveTextureImageVRAMState((char*)resources+0x2cc);
UpdateVRAMStagingVRAMBanks();UnlockStagedTextureVRAMCopying();
}
