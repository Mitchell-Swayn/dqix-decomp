#include <globaldefs.h>
ARM
struct State; struct Global;
struct E {short key;short pad;unsigned value;}; struct T {E* data;short count;};
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts(void*);
extern "C" void TextWindow_StartFormattedMessage(int,int,int,int);
extern "C" unsigned TextWindow_GetChoiceResult(Global*);
extern "C" void Window_PopCanvasesAndResetSelection(State*,int);
extern "C" int Selection_ReadEnabledIndexFromControl(void*);
extern "C" void Window_BindNextCanvasResourceByFormatAndLayer(char*,unsigned,unsigned);
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
extern "C" unsigned MessageTextTable_FindTextById(T*,int);
extern "C" void ProfileEditor_RefreshPageText(unsigned char*,unsigned,int);
extern "C" void Graphics_BuildProfileSummaryPage(unsigned char*);
extern "C" void Graphics_BuildProfileValuePairPage(unsigned char*);
extern "C" void ProfileEditor_RefreshPreview(char*,int,int,int);
extern "C" bool Menu_IsConfirmOrCanvasActionPressed(char*);
extern "C" int Menu_TestCancelKeyOrCanvasTouchKindTwo(void*);
extern "C" void Menu_ConfigurePairedSelectionGridsForActiveCanvas(unsigned char*);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
struct ProfileFlag { unsigned low:31; unsigned flag:1; };
inline ProfileFlag* GetProfileFlag() { return (ProfileFlag*)((char*)_ZN9GameState11GetInstanceEv()+0x569c); }
// Original: arm9/ov012 @ 0x02187320; symbol: func_ov012_02187320; size: 0x2E8.
// Handles owner dialog and selection for the profile's high-bit setting.
extern "C" void UpdateProfileHighBitDialog(char* p) {
 char* owner=(char*)TextContext_GetSharedInstance();
 int mode=*(int*)(owner+0x9a0);
 if(mode==3) *(unsigned char*)(owner+0x19ae)=0;
 if(*(unsigned char*)(p+0x1370)==0) {
 unsigned text=MessageTextTable_FindTextById((T*)(p+0x133c),15);
 TextWindow_StartFormattedMessage((int)owner,text,0,227);
 *(int*)(owner+0x998)=1;
 Window_PopCanvasesAndResetSelection((State*)(p+0xac),1);
 *(unsigned char*)(p+0x1370)=10;
 } else if(*(unsigned char*)(p+0x1370)==1) {
 if(mode==0||mode==3) ++*(unsigned char*)(p+0x1370);
 } else if(*(unsigned char*)(p+0x1370)==2) {
 *(unsigned char*)(p+0x13a0)=0;
 *(int*)(p+0x13f8)=0;
 Window_BindNextCanvasResourceByFormatAndLayer(p+0xac,0,2);
 Menu_ConfigurePairedSelectionGridsForActiveCanvas((unsigned char*)p);
 Graphics_BuildProfileValuePairPage((unsigned char*)p);
 SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,5,0);
 ++*(unsigned char*)(p+0x1370);
 } else if(*(unsigned char*)(p+0x1370)==3) {
 *(unsigned char*)(p+0x13a0)=1;
 *(int*)(p+0x13f8)=Selection_ReadEnabledIndexFromControl(p+0xac);
 int done=0;
 if(Menu_IsConfirmOrCanvasActionPressed(p)||Menu_TestCancelKeyOrCanvasTouchKindTwo(p)) {
 ProfileEditor_RefreshPageText((unsigned char*)p,*(unsigned char*)(p+0x1371),1);
 SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
 ProfileFlag* flag=GetProfileFlag();
 switch(*(int*)(p+0x13f8)) {case 0: flag->flag=0; break; case 1: flag->flag=1; break;}
 if(Menu_TestCancelKeyOrCanvasTouchKindTwo(p)) flag->flag=1;
 ProfileEditor_RefreshPreview(p,0,-1,0);
 done=1;
 }
 if(done) {
 char* owner=(char*)TextContext_GetSharedInstance();
 int idle=*(int*)(owner+0x998)==0;
 if(!idle) TextWindow_ResetGlyphBuffersAndFrameContexts(owner);
 Window_PopCanvasesAndResetSelection((State*)(p+0xac),1);
 ++*(unsigned char*)(p+0x1370);
 }
 } else if(*(unsigned char*)(p+0x1370)==4) ++*(unsigned char*)(p+0x1370);
 else if(*(unsigned char*)(p+0x1370)==5) ++*(unsigned char*)(p+0x1370);
 else if(*(unsigned char*)(p+0x1370)==6) {
 *(unsigned char*)(p+0x1371)=1;
 Menu_ConfigurePairedSelectionGridsForActiveCanvas((unsigned char*)p);
 Graphics_BuildProfileSummaryPage((unsigned char*)p);
 *(unsigned char*)(p+0x13a0)=1;
 *(signed char*)(p+0x13a8)=-1;
 *(signed char*)(p+0x13a9)=0;
 *(unsigned char*)(p+0x1370)=1;
 } else if(*(unsigned char*)(p+0x1370)==10 && *(int*)(owner+0x998)==0) {
 ProfileFlag* flag=GetProfileFlag();
 if(TextWindow_GetChoiceResult((Global*)owner)==0) flag->flag=0;
 else flag->flag=1;
 ProfileEditor_RefreshPreview(p,0,-1,0);
 Window_PopCanvasesAndResetSelection((State*)(p+0xac),1);
 *(unsigned char*)(p+0x1370)=5;
 }
}
