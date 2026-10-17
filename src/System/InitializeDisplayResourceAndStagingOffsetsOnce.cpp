#include <globaldefs.h>
#include "System/Cache.h"
#include "std_library_functions.h"
struct Animation { unsigned char state[40]; };
struct ScreenState { unsigned char reserved[60],screen;char reserved3D[3];void* tiles;unsigned tileSize;void* palette;unsigned paletteSize;char reserved50;unsigned char initialized,reserved52,fillEnabled;unsigned unknown54,flags;unsigned unknown5C,unknown60;unsigned char savedFlag;char reserved65[5];short fill;unsigned short reserved6C,count;Animation animations[3]; };
typedef char* (*GetMemory)();typedef void (*Upload)(const void*,unsigned,unsigned);typedef unsigned (*GetFlags)();
extern "C" {
extern GetMemory data_020f28e4[];
extern Upload data_020f28ec[],data_020f28dc[];
extern GetFlags data_020f28fc[];
void Graphics_SetSelectedScreenBrightnessAndMarkEnabled(ScreenState*,unsigned,int,int);
void* GetGlobalStatePointer();
void SetWordMaskBits_Main020466E4(void*,unsigned);
unsigned Graphics_ComputeObjectVRAMCapacity(unsigned);
bool Object_TestPowerOrNestedResourceReadyState(ScreenState*);
void DMAFillAndInvokeIndexedGraphicsLoader(ScreenState*,unsigned);
void ClearRecordWordsAndByteFlags(Animation*);
void ChooseOneOfThreeFlagsByRandomThreshold(Animation*);
}
// Original: arm9/main @ 0x020DB3F4; symbol: func_020db3f4; size: 0x1F8.
extern "C" void InitializeDisplayResourceAndStagingOffsetsOnce(ScreenState* state)
{
    if(state->initialized) return;
    Graphics_SetSelectedScreenBrightnessAndMarkEnabled(state,state->screen,state->fill,0);
    state->initialized=1;
    SetWordMaskBits_Main020466E4(GetGlobalStatePointer(),0x8000);
    char* memory;
    unsigned boundary=Graphics_ComputeObjectVRAMCapacity(state->screen);
    unsigned tileOffset=boundary-0xb80;
    unsigned paletteOffset=0x1e0;
    unsigned fillOffset=boundary-0x800;
    if(Object_TestPowerOrNestedResourceReadyState(state)) paletteOffset=0x1c0;
    memory=data_020f28e4[state->screen]();
    CleanInvalidateCacheRange(state->tiles,state->tileSize);
    data_020f28ec[state->screen](state->tiles,tileOffset,state->tileSize);
    CleanCacheRange(state->tiles,state->tileSize);
    if(!state->fillEnabled || !state->fill) memset(memory+fillOffset,0,0x800);
    else if(state->fill==-16) memset(memory+fillOffset,-1,0x800);
    else if(state->fill==16) memset(memory+fillOffset,0xeeeeeeee,0x800);
    CleanInvalidateCacheRange(memory+fillOffset,0x800);
    data_020f28ec[state->screen](memory+fillOffset,fillOffset,0x800);
    CleanCacheRange(memory+fillOffset,0x800);
    CleanInvalidateCacheRange(state->palette,state->paletteSize);
    data_020f28dc[state->screen](state->palette,paletteOffset,state->paletteSize);
    CleanCacheRange(state->palette,state->paletteSize);
    DMAFillAndInvokeIndexedGraphicsLoader(state,state->screen);
    state->count=0;
    Animation* animations=state->animations;
    for(int i=0;i<3;i++) {
        ClearRecordWordsAndByteFlags(&animations[i]);
        ChooseOneOfThreeFlagsByRandomThreshold(&animations[i]);
    }
    if(state->fillEnabled) {state->flags=16;return;}
    unsigned flags=data_020f28fc[state->screen]();
    state->savedFlag=flags&16;
    state->flags=flags|16;
}
