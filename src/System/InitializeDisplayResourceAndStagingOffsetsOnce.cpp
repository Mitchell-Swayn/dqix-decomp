#include <globaldefs.h>
#include "System/Cache.h"
#include "std_library_functions.h"
struct Animation { unsigned char state[40]; };
struct ScreenState { unsigned char reserved[60],screen;char reserved3D[3];void* tiles;unsigned tileSize;void* palette;unsigned paletteSize;char reserved50;unsigned char initialized,reserved52,fillEnabled;unsigned unknown54,flags;unsigned unknown5C,unknown60;unsigned char savedFlag;char reserved65[5];short fill;unsigned short reserved6C,count;Animation animations[3]; };
typedef char* (*GetMemory)();typedef void (*Upload)(const void*,unsigned,unsigned);typedef unsigned (*GetFlags)();
extern "C" {
// Original data: arm9/main @ 0x20f28e4; symbol: data_020f28e4.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 88af0d0280af0d02.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern GetMemory InitializeDisplayResourceAndStagingOffsetsOnce_UnknownRoleProcedureReferenceRecords[];
// Original data: arm9/main @ 0x20f28dc; symbol: data_020f28dc.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex cc580c0224590c02.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20f28ec; symbol: data_020f28ec.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 285a0c02805a0c02.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern Upload InitializeDisplayResourceAndStagingOffsetsOnce_UnknownRoleProcedureReferenceRecords_Variant2[],DisplayOverlayDeactivateAndRestoreDisplay_UnknownRoleProcedureReferenceRecords[];
// Original data: arm9/main @ 0x20f28fc; symbol: data_020f28fc.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 6caf0d0254af0d02.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern GetFlags DisplayOverlayCaptureNormalPlaneMasks_UnknownRoleProcedureReferenceRecords[];
void Graphics_SetSelectedScreenBrightnessAndMarkEnabled(ScreenState*,unsigned,int,int);
void* SystemState_GetGlobalFlags();
void SystemState_SetFlags(void*,unsigned);
unsigned Graphics_ComputeObjectVRAMCapacity(unsigned);
bool DisplayOverlay_UseAlternateSpritePalette(ScreenState*);
void DMAFillAndInvokeIndexedGraphicsLoader(ScreenState*,unsigned);
void DisplaySpriteAnimation_ResetPlayback(Animation*);
void DisplaySpriteAnimation_ChooseTileVariant(Animation*);
}
// Original: arm9/main @ 0x020DB3F4; symbol: func_020db3f4; size: 0x1F8.
extern "C" void InitializeDisplayResourceAndStagingOffsetsOnce(ScreenState* state)
{
    if(state->initialized) return;
    Graphics_SetSelectedScreenBrightnessAndMarkEnabled(state,state->screen,state->fill,0);
    state->initialized=1;
    SystemState_SetFlags(SystemState_GetGlobalFlags(),0x8000);
    char* memory;
    unsigned boundary=Graphics_ComputeObjectVRAMCapacity(state->screen);
    unsigned tileOffset=boundary-0xb80;
    unsigned paletteOffset=0x1e0;
    unsigned fillOffset=boundary-0x800;
    if(DisplayOverlay_UseAlternateSpritePalette(state)) paletteOffset=0x1c0;
    memory=InitializeDisplayResourceAndStagingOffsetsOnce_UnknownRoleProcedureReferenceRecords[state->screen]();
    CleanInvalidateCacheRange(state->tiles,state->tileSize);
    InitializeDisplayResourceAndStagingOffsetsOnce_UnknownRoleProcedureReferenceRecords_Variant2[state->screen](state->tiles,tileOffset,state->tileSize);
    CleanCacheRange(state->tiles,state->tileSize);
    if(!state->fillEnabled || !state->fill) memset(memory+fillOffset,0,0x800);
    else if(state->fill==-16) memset(memory+fillOffset,-1,0x800);
    else if(state->fill==16) memset(memory+fillOffset,0xeeeeeeee,0x800);
    CleanInvalidateCacheRange(memory+fillOffset,0x800);
    InitializeDisplayResourceAndStagingOffsetsOnce_UnknownRoleProcedureReferenceRecords_Variant2[state->screen](memory+fillOffset,fillOffset,0x800);
    CleanCacheRange(memory+fillOffset,0x800);
    CleanInvalidateCacheRange(state->palette,state->paletteSize);
    DisplayOverlayDeactivateAndRestoreDisplay_UnknownRoleProcedureReferenceRecords[state->screen](state->palette,paletteOffset,state->paletteSize);
    CleanCacheRange(state->palette,state->paletteSize);
    DMAFillAndInvokeIndexedGraphicsLoader(state,state->screen);
    state->count=0;
    Animation* animations=state->animations;
    for(int i=0;i<3;i++) {
        DisplaySpriteAnimation_ResetPlayback(&animations[i]);
        DisplaySpriteAnimation_ChooseTileVariant(&animations[i]);
    }
    if(state->fillEnabled) {state->flags=16;return;}
    unsigned flags=DisplayOverlayCaptureNormalPlaneMasks_UnknownRoleProcedureReferenceRecords[state->screen]();
    state->savedFlag=flags&16;
    state->flags=flags|16;
}
