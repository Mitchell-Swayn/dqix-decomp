#include <globaldefs.h>
#include <std_library_functions.h>
ARM
struct State; struct SixFieldRecord;
struct E{short key,pad;unsigned value;};struct T{E* data;short count;};
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader21FreeAllocationsGlobalEv();
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv();
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv();
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
extern "C" int _ZN16BackgroundLoader21GetDetailedTaskStatusEi(void*,int);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" int Text_EncodeGlyphIndices(const char*,unsigned char*,unsigned);
extern "C" void Text_MapInputBytesToVariableLengthOutputSequences(const unsigned char*,unsigned char*,unsigned);
extern "C" void TextWindow_StartFormattedMessage(int,int,int,int);
extern "C" void Window_PopCanvasesAndResetSelection(State*,int);
extern "C" int Window_ClassifyTouchAgainstSelectedCanvas(void*);
extern "C" void Window_BindNextCanvasResourceByFormatAndLayer(char*,unsigned,unsigned);
extern "C" void Window_SetCanvasEnabled(unsigned char*,int,int);
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
extern "C" unsigned MessageTextTable_FindTextById(T*,int);
extern "C" void TextEntry_InitializeControlAndGridTables(SixFieldRecord*);
extern "C" void Script_ExecuteBufferWithLookup(void*,void*,const void*,unsigned);
extern "C" void InitializeBufferHeaderAndStatusBytes(void*);
extern "C" int TextEntry_UpdateControlInput(void*,unsigned);
extern "C" void TextEntry_SelectControlByNameAndResetInput(State*,const signed char*,int);
extern "C" void ProfileTextFilter_InitializeGlyphLookup(unsigned char*);
extern "C" int ProfileTextFilter_ContainsRejectedPattern(unsigned char*,char*);
extern "C" void Graphics_BuildProfileSummaryPage(unsigned char*);
extern "C" void Graphics_BuildProfileEntryChoicePage(unsigned char*);
extern "C" void ProfileEditor_DrawKeyboard(void*,void*,int);
extern "C" int ProfileEditor_GeneratePreviewText(unsigned char*,void*);
extern "C" void Menu_ConfigurePairedSelectionGridsForActiveCanvas(unsigned char*);
extern "C" void RefreshGridLabelBackground(unsigned char*);
extern "C" char UpdateProfileTextEditor_PathDataBinKeyboardPrBin[];
// Original data: arm9/ov012 @ 0x218b303; symbol: data_ov012_0218b303.
// Source-defined character literal. Text: "1". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "1".
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov012.md.
extern "C" signed char UpdateProfileTextEditor_Text1[];
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
inline unsigned char* ProfileRecord() {return (unsigned char*)_ZN9GameState11GetInstanceEv()+0x569c;}
// Original: arm9/ov012 @ 0x02188CD0; symbol: func_ov012_02188cd0; size: 0x594.
// Loads editor script, processes profile text input and validates/commits its glyph output.
extern "C" void UpdateProfileTextEditor(unsigned char* p) {
 if(p[0x1370]==0) {
 Window_PopCanvasesAndResetSelection((State*)(p+0xac),1);
 unsigned char* profile=ProfileRecord();
 memset(*(void**)(p+0x13d0),0,1024);
 *(void**)(p+0x1328)=*(void**)(p+0x13d0);
 Text_MapInputBytesToVariableLengthOutputSequences(profile+8,*(unsigned char**)(p+0x13d0),1);
 *(unsigned*)(p+0x1380)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(_ZN16BackgroundLoader11GetInstanceEv(),UpdateProfileTextEditor_PathDataBinKeyboardPrBin,0);
 ++p[0x1370];
 } else if(p[0x1370]==1) {
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,*(unsigned*)(p+0x1380))) {
 if(_ZN16BackgroundLoader21GetDetailedTaskStatusEi(loader,*(int*)(p+0x1380))!=2) {
 _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+0x1380)); *(int*)(p+0x1380)=-1;
 }
 void* file; unsigned size;
 _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,*(int*)(p+0x1380),&file,&size);
 if(file&&size) {
 _ZN13SafeAllocator5ResetEv(p+0x70);
 TextEntry_InitializeControlAndGridTables(*(SixFieldRecord**)(p+4));
 Script_ExecuteBufferWithLookup(*(void**)(p+4),p+0x70,file,size);
 InitializeBufferHeaderAndStatusBytes(*(void**)p);
 *(void**)(*(unsigned char**)p+4)=*(void**)(p+4);
 *(int*)*(unsigned char**)p=0;
 }
 _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+0x1380)); *(int*)(p+0x1380)=-1;
 ++p[0x1370];
 }
 } else if(p[0x1370]==2) {
 ProfileEditor_GeneratePreviewText(p,ProfileRecord()); ++p[0x1370];
 } else if(p[0x1370]==3) {
 p[0x13a0]=0;
 Window_BindNextCanvasResourceByFormatAndLayer((char*)p+0xac,0,2);
 Menu_ConfigurePairedSelectionGridsForActiveCanvas(p);
 Graphics_BuildProfileEntryChoicePage(p);
 memcpy(*(void**)(p+0x13ac),ProfileRecord()+8,114);
 unsigned char* editor=*(unsigned char**)p;
 *(void**)(editor+8)=*(void**)(p+0x13d0);
 *(int*)(editor+0x10)=1024;
 *(int*)(*(unsigned char**)p+0x14)=57;
 (*(unsigned char**)p)[0x1f]=1;
 (*(unsigned char**)p)[0x21]=1;
 (*(unsigned char**)p)[0x24]=1;
 TextEntry_SelectControlByNameAndResetInput(*(State**)p,UpdateProfileTextEditor_Text1,1);
 (*(unsigned char**)p)[0x22]=1;
 (*(unsigned char**)p)[0x23]=0;
 ProfileEditor_DrawKeyboard(p,0,0);
 ++p[0x1370];
 } else if(p[0x1370]==4) {
 if((Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2)||Window_ClassifyTouchAgainstSelectedCanvas(p+0xac)==2)&&!**(signed char**)(p+0x13d0)) {
 Window_PopCanvasesAndResetSelection((State*)(p+0xac),1); ++p[0x1370];
 }
 unsigned old=(*(unsigned char**)p)[0x20];
 switch(TextEntry_UpdateControlInput(*(void**)p,*(unsigned*)(p+0x13a4))) {
 case 1: SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,2,0); break;
 case 2: case 3: case 8:
 SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
 if(old!=(*(unsigned char**)p)[0x20]) ProfileEditor_DrawKeyboard(p,0,0);
 RefreshGridLabelBackground(p+0xd28); break;
 case 4: case 5: case 6: case 7: case 11:
 SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0); ProfileEditor_DrawKeyboard(p,0,0); break;
 case 9: SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0); break;
 case 10:
 SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
 if(**(signed char**)(p+0x13d0)) {
 _ZN9GameState11GetInstanceEv(); _ZN16BackgroundLoader13AddLockGlobalEv(); _ZN16BackgroundLoader21FreeAllocationsGlobalEv();
 ProfileTextFilter_InitializeGlyphLookup(p+0x1480);
 int result=ProfileTextFilter_ContainsRejectedPattern(p+0x1480,*(char**)(p+0x13d0));
 _ZN16BackgroundLoader16RemoveLockGlobalEv();
 if(result) {Window_SetCanvasEnabled(p+0xac,0,14);p[0x1370]=10;break;}
 }
 Window_PopCanvasesAndResetSelection((State*)(p+0xac),1); ++p[0x1370]; break;
 }
 } else if(p[0x1370]==5) {
 unsigned char* profile=ProfileRecord();
 Text_EncodeGlyphIndices(*(char**)(p+0x13d0),profile+8,1);
 *(int*)(p+0x1328)=0;
 memset(*(void**)(p+0x13d0),0,1024);
 ++p[0x1370];
 } else if(p[0x1370]==6) ++p[0x1370];
 else if(p[0x1370]==7) {
 p[0x1371]=1; Menu_ConfigurePairedSelectionGridsForActiveCanvas(p);Graphics_BuildProfileSummaryPage(p);p[0x13a0]=1;p[0x1370]=1;
 } else if(p[0x1370]==10) {
 char* owner=(char*)TextContext_GetSharedInstance();
 unsigned text=MessageTextTable_FindTextById((T*)(p+0x133c),501);
 TextWindow_StartFormattedMessage((int)owner,text,0,227);
 *(int*)(owner+0x998)=1; ++p[0x1370];
 } else if(p[0x1370]==11) {
 if(!*(int*)((char*)TextContext_GetSharedInstance()+0x998)) {
 Window_SetCanvasEnabled(p+0xac,1,14);p[0x1370]=4;
 *(int*)(*(unsigned char**)p+0x18)=0;
 *(short*)(*(unsigned char**)p+0x1c)=0;
 }
 }
}
