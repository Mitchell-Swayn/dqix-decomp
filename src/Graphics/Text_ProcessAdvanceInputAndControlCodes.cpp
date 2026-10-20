#include <globaldefs.h>
ARM
struct GameState;
struct Links;
struct Object;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned _ZNK9GameState12GetTickCountEv(GameState*);
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);
extern "C" void* ActorPool_GetGlobalInstance();
extern "C" unsigned* ActorPool_GetActiveSlot(unsigned**,unsigned);
extern "C" void Actor_SetRepresentationTargetYaw(Links*,unsigned);
extern "C" void TextWindow_ResetGlyphPoolAndParserState(char*);
extern "C" void TextWindow_ResetFrameContextsAndMessageFlags(unsigned char*);
extern "C" void Graphics_ClearAndStageSharedBuffers(char*);
extern "C" int TextStream_GetExtendedControlArgumentCount(void*,const void*);
extern "C" bool TextStream_IsControlToken(int,void*);
extern "C" void TextWindow_FlushPendingResourceAction(unsigned char*);
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
extern "C" unsigned short TextStream_GetCurrentToken(unsigned char*);
extern "C" void TextStream_UpdateSpeakerTurnWait(void*,int);
extern "C" void Text_ProcessBufferedHalfwordCodesAndResetCounters(Object*);
extern "C" void TextStream_AdvanceSegmentAndRebuildBuffers(Object*);
extern "C" void QuestMessagePanel_RequestAlternateTransition(unsigned char*);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020440CC; symbol: func_020440cc; size: 0x354.
extern "C" int Text_ProcessAdvanceInputAndControlCodes(unsigned char* self) {
if(!*(int*)(self+0x998)) return 1;
if(!self[0x19c1] && self[0x19c0]) return 0;
unsigned short mask=0x403;
bool advance=false;
if(self[0x19bf]) mask|=0x200;
if(self[0x19cf]) mask|=0x100;
if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,mask)) advance=true;
if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0xf0)) advance=true;
if(Main_UnknownRoleZeroInitializedStorage_Variant4[0x54] && *(unsigned*)(Main_UnknownRoleZeroInitializedStorage_Variant4+0x44)<20) advance=true;
if(TextStream_GetCurrentToken(self)==0xff0c) {
unsigned ticks=_ZNK9GameState12GetTickCountEv((GameState*)_ZN9GameState11GetInstanceEv());
unsigned value=self[0x1961];
if(value) {
if(value<=ticks) {self[0x1961]=0;advance=true;}
else self[0x1961]=value-ticks;
}
}
if(!advance) return 0;
switch(*(unsigned*)(self+0x9a0)) {
case 0:
if(self[0x19be]) return 0;
if(TextStream_GetCurrentToken(self)==0xff02) {
unsigned* slot=ActorPool_GetActiveSlot((unsigned**)ActorPool_GetGlobalInstance(),*(unsigned*)(self+0x1838));
if(slot) Actor_SetRepresentationTargetYaw((Links*)slot,*(unsigned*)(self+0x183c));
}
return 1;
case 1:
self[0x19ae]=0;self[0x19af]=0;self[0x19cd]=1;
*(unsigned*)(self+0x40)=0;*(unsigned*)(self+0x44)=0;self[0x912]=0;
Text_ProcessBufferedHalfwordCodesAndResetCounters((Object*)self);
*(unsigned*)(self+0x9a0)=5;
TextStream_AdvanceSegmentAndRebuildBuffers((Object*)self);
if(!self[0x19d3]) SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
break;
case 3:self[0x19bd]=0;break;
case 2:
if(TextStream_GetCurrentToken(self)==0xff1f) {
unsigned short code;
while(*(unsigned*)(self+0x78)<*(unsigned*)(self+0x6c)) {
code=(*(unsigned short**)(self+0x4c))[*(unsigned*)(self+0x78)];
if(TextStream_IsControlToken((int)self,&code)) {
int n=TextStream_GetExtendedControlArgumentCount(self,&code);
if(n) {*(unsigned*)(self+0x78)=*(unsigned*)(self+0x78)+n+1;continue;}
if(code==0xff01 || code==0xff03) break;
if(code==0xff2c) {
*(unsigned*)(self+0x1844)=*(unsigned*)(self+0x183c);
self[0x19b6]=1;
TextStream_UpdateSpeakerTurnWait(self,1);
} else if(code==0xff12) {
unsigned char* object=*(unsigned char**)(self+0x8c);
if(object) QuestMessagePanel_RequestAlternateTransition(object);
}
}
(*(unsigned*)(self+0x78))++;
}
TextWindow_FlushPendingResourceAction(self);
*(unsigned*)(self+0x9a0)=0;
TextWindow_ResetGlyphPoolAndParserState((char*)self);
Graphics_ClearAndStageSharedBuffers((char*)self);
TextWindow_ResetFrameContextsAndMessageFlags(self);
} else {
if(!self[0x19d3]) SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
*(unsigned*)(self+0x9a0)=5;
(*(unsigned*)(self+0x78))++;
self[0x912]=0;
}
break;
}
return 0;
}
