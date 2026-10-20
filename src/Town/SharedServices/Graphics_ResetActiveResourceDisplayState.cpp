#include <globaldefs.h>
ARM
extern "C" void TextCanvas_ClearDisplayLayerBuffers(void*);
extern "C" void TextCanvas_CopyAllDisplayPartsToLayers(void*);
extern "C" void TextCanvas_FillDisplayPartRegionsOnLayer(void*,int,int,int);
extern "C" void Graphics_CleanConfiguredDestinationCacheForEachThirtyTwoByteEntry(void*);
extern "C" void Town_UpdatePartyMenuBackgroundRegions(void*);
extern "C" unsigned Window_IsVisible(void*);
extern "C" void Window_UpdateEnabledEntryAndRoot(void*,void*);
extern "C" void Tavern_DrawPartySelectionCursor(unsigned char*);
extern "C" void Graphics_CleanupTransferState(unsigned char*);
extern "C" void SpriteAnimation_StartTrack(void*,int);
extern "C" unsigned char* SpriteAnimation_FindTrackByKey(void*,unsigned);
extern "C" void SpriteAnimation_AdvanceAllTracks(char*,unsigned);
extern "C" void Window_SetLookupEntryPosition(void*,unsigned,unsigned,unsigned);
extern "C" void SpriteAnimation_SubmitAllTrackFrames(unsigned char*);
// Original: arm9/ov003 @ 0x02160134; symbol: Graphics_ResetActiveResourceDisplayState; size: 0x10C.
// Resets active transfer records, refreshes the display window, and restores selected lookup-entry state when flagged.
extern "C" void Graphics_ResetActiveResourceDisplayState(unsigned char* self){
 if(self[0x4a3]==0)return;
 void* records=*(void**)(self+0x324);
 if(records){TextCanvas_ClearDisplayLayerBuffers(records);TextCanvas_CopyAllDisplayPartsToLayers(records);TextCanvas_FillDisplayPartRegionsOnLayer(records,1,2,1);Graphics_CleanConfiguredDestinationCacheForEachThirtyTwoByteEntry(records);}
 Town_UpdatePartyMenuBackgroundRegions(self);
 if(*(void**)(self+0x390)&&Window_IsVisible(*(void**)(self+0x390)))Window_UpdateEnabledEntryAndRoot(*(void**)(self+0x390),self+0x334);
 Tavern_DrawPartySelectionCursor(self);
 if(*(void**)(self+0x318))Graphics_CleanupTransferState(*(unsigned char**)(self+0x318));
 if((*(unsigned*)(self+0x464)&0x02000000)==0)return;
 SpriteAnimation_StartTrack(*(void**)(self+0x38c),1);
 unsigned char* entry=SpriteAnimation_FindTrackByKey(*(void**)(self+0x38c),0);if(entry)entry[0x15]&=~8;
 entry=SpriteAnimation_FindTrackByKey(*(void**)(self+0x38c),1);if(entry)entry[0x15]|=8;
 SpriteAnimation_AdvanceAllTracks((char*)*(void**)(self+0x38c),*(unsigned*)(self+0x460));
 Window_SetLookupEntryPosition(*(void**)(self+0x38c),1,0xd7,0x96);
 SpriteAnimation_SubmitAllTrackFrames(self+0x334);
}
