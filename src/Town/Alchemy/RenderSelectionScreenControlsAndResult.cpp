#include <globaldefs.h>
ARM
struct GameState;struct IndexedRecordView;struct Entry;struct List;struct State;struct Obj;struct A;
extern "C" {
void* _ZN9GameState11GetInstanceEv();
unsigned int GameState_ReadSupportedFirmwareLanguage(GameState*);
void* Graphics_GetGlobalOamTransferState();
void* Graphics_GetSubOamStagingBuffer();
char* Graphics_GetLoadedScreenDescriptor(char*,unsigned);
void Graphics_ClearScreenBuffer(unsigned char*,void*);
void Graphics_CleanConfiguredDestinationCache(void*,int);
void Graphics_CopyIndexedScreenRectangle(IndexedRecordView*,unsigned,unsigned,unsigned,short,short,short,short,unsigned short);
void Graphics_CopyScreenAtPosition(char*,const short*,unsigned,unsigned,unsigned short);
void SpriteAnimation_AdvanceAllTracks(char*,unsigned);
void SpriteAnimation_StartTrack(void*, unsigned);
Entry* SpriteAnimation_FindTrackByKey(List*,unsigned);
void Graphics_SubmitTransformedCellToOam(void*,void*);
void SpriteAnimation_SubmitAllTrackFrames(unsigned char*);
int Sprite_DrawSelectedAnimationCell(State*,int,int);
void Sprite_SetScaleFactors(void*,unsigned,unsigned);
void TextCanvas_ClearDisplayLayerBuffers(unsigned char*);
void TextCanvas_CopyAllDisplayPartsToLayers(State*);
void Graphics_CleanConfiguredDestinationCacheForEachThirtyTwoByteEntry(State*);
void TextCanvas_FillDisplayPartRegionsOnLayer(void*,int,int,int);
void TextCanvas_GetGroupPixelOrigin(char*,int,short*,short*);
void Window_UpdateEnabledEntryAndRoot(Obj*,void*);
unsigned Window_IsVisible(A**);
void Graphics_ProjectBoneAnchorsAndDrawScreenMarkers(unsigned char*);
void KrakPot_SubmitControlSprite(void*,unsigned char*,int,int,unsigned char,unsigned char);
int KrakPot_IsDisplayPartPresentAndFlagFiveClear(unsigned char*,unsigned);
void KrakPot_UpdateSelectionCursorPosition(char*);
void SubmitPageAndToggleDisplayRecords(unsigned char*);
void SubmitQuantityControlDisplayRecords(unsigned char*);
void KrakPot_SubmitRecipeBrowserControlSprites(char*);
}
#define H(o) (*(short*)(self+(o)))
#define U(o) (*(unsigned short*)(self+(o)))
#define W(o) (*(unsigned*)(self+(o)))
#define P(o) (*(unsigned char**)(self+(o)))
// Original: arm9/ov006 @ 0x021580B8; symbol: func_ov006_021580b8; size: 0x3C0.
// Renders selection controls, language-specific labels, loading indicators and result markers.
extern "C" void RenderSelectionScreenControlsAndResult(unsigned char* self) {
 if(self[0x38f]) {
  if(KrakPot_IsDisplayPartPresentAndFlagFiveClear(P(0x14),0)) KrakPot_SubmitControlSprite(self+0xac,P(0x24)+0x410,2,0x61,0x64,1);
  if(KrakPot_IsDisplayPartPresentAndFlagFiveClear(P(0x14),1)) {
   KrakPot_SubmitControlSprite(self+0xac,P(0x24)+0x438,2,0x74,0x66,1);
   if((signed char)self[0x42c]>31) KrakPot_SubmitControlSprite(self+0xac,P(0x24)+0x460,0x78,0xb6,0x63,1);
  } else self[0x42c]=0;
  Graphics_ProjectBoneAnchorsAndDrawScreenMarkers(P(0x10));
  Graphics_ClearScreenBuffer(self+0x54,0);
  const short* position=(const short*)Graphics_GetLoadedScreenDescriptor((char*)self+0x54,self[0x397]);
  if(position) Graphics_CopyScreenAtPosition((char*)self+0x54,position,0,0,0xffff);
  if(self[0x397]==1) {
   unsigned language=GameState_ReadSupportedFirmwareLanguage((GameState*)_ZN9GameState11GetInstanceEv());
   unsigned index=1;
   switch(language) {case 2:index=3;break;case 4:index=4;break;case 3:index=5;break;case 5:index=6;break;}
   if(index>1) Graphics_CopyIndexedScreenRectangle((IndexedRecordView*)(self+0x54),index,0,0,0x16,2,9,2,0xffff);
  }
  unsigned char* display=P(0x14);
  TextCanvas_ClearDisplayLayerBuffers(display);TextCanvas_CopyAllDisplayPartsToLayers((State*)display);TextCanvas_FillDisplayPartRegionsOnLayer(display,2,1,1);
  Graphics_CleanConfiguredDestinationCache(self+0x54,0);Graphics_CleanConfiguredDestinationCacheForEachThirtyTwoByteEntry((State*)display);
  if(U(0x394)&0x200) {
   self[0x42c]=0;
   SpriteAnimation_StartTrack(P(0x28),1);
   unsigned char* record=(unsigned char*)SpriteAnimation_FindTrackByKey((List*)P(0x28),0);if(record) record[0x15]&=~8;
   record=(unsigned char*)SpriteAnimation_FindTrackByKey((List*)P(0x28),1);if(record) record[0x15]|=8;
   SpriteAnimation_AdvanceAllTracks((char*)P(0x28),W(0x34c));
   record=(unsigned char*)SpriteAnimation_FindTrackByKey((List*)P(0x28),1);if(record) {*(short*)(record+4)=0xd7;*(short*)(record+6)=0x96;}
   SpriteAnimation_SubmitAllTrackFrames(self+0xac);
  } else {
   unsigned char* record=(unsigned char*)SpriteAnimation_FindTrackByKey((List*)P(0x28),1);if(record) record[0x15]&=~8;
  }
  if(H(0x37e)<0) {
   if(P(0x18) && Window_IsVisible((A**)P(0x18))) Window_UpdateEnabledEntryAndRoot((Obj*)P(0x18),self+0xac);
   else KrakPot_UpdateSelectionCursorPosition((char*)self);
  }
  SubmitPageAndToggleDisplayRecords(self);SubmitQuantityControlDisplayRecords(self);KrakPot_SubmitRecipeBrowserControlSprites((char*)self);
  self[0x431]=0;self[0x430]=0;
 }
 if(W(0x3b4) && (self[0x38f]==8 || self[0x38f]==11)) {
  short x,y;
  TextCanvas_GetGroupPixelOrigin((char*)P(0x14),0x12,&x,&y);
  unsigned char* record=P(0x24)+0x2a8;
  if(record) {
   *(int*)(record+0x14)=(x+4)<<12;*(int*)(record+0x18)=(y+4)<<12;
   record[0x22]=0x32;record[0x26]=1;
   Graphics_SubmitTransformedCellToOam(self+0xac,record);
  }
  Graphics_GetGlobalOamTransferState();
  unsigned char* global=(unsigned char*)Graphics_GetSubOamStagingBuffer();
  W(0x404)=0;P(0x3cc)=global+0x1b8;W(0x3fc)=0x37;
  Sprite_SetScaleFactors(self+0x3b8,0x1000,0x1000);
  Sprite_DrawSelectedAnimationCell((State*)(self+0x3b8),x+8,y+8);
 }
}
