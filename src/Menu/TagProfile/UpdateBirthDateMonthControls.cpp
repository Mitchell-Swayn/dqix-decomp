#include <globaldefs.h>
ARM
struct State;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);
extern "C" int Input_PollKeyRepeatCountdown(State*,unsigned);
extern "C" void Window_PopCanvasesAndResetSelection(State*,int);
extern "C" int Window_IsTouchInsideCanvas(unsigned char*,unsigned);
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
extern "C" int Calendar_ComputeAgeFromBirthDate(int,int,int);
extern "C" void ProfileEditor_RefreshPageText(unsigned char*,unsigned,int);
extern "C" void Graphics_BuildProfileSummaryPage(unsigned char*);
extern "C" void ProfileEditor_RefreshPreview(char*,int,int,int);
extern "C" void Calendar_UpdateBirthDateAdjustmentFlags(unsigned char*);
extern "C" void Menu_SetDateControlCanvasAttributes(char*,unsigned char,int,int,unsigned char);
extern "C" int Util_ClassifyCoordinateInRecordRegions(unsigned char*);
extern "C" bool Menu_IsConfirmOrCanvasActionPressed(char*);
extern "C" int Menu_TestCancelKeyOrCanvasTouchKindTwo(void*);
extern "C" void Menu_ConfigurePairedSelectionGridsForActiveCanvas(unsigned char*);
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
struct MonthDays { char values[12]; };
// Original data: arm9/ov012 @ 0x218af9e; symbol: data_ov012_0218af9e.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 1f1c1f1e1f1e1f1f1e1f1e1f.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov012.md.
extern "C" MonthDays UpdateBirthDateMonthControls_UnknownRoleInitializedBytes;
struct BirthDateBits { unsigned year:12; unsigned month:4; unsigned day:5; unsigned upper:11; unsigned age:9; unsigned remaining:23; };
inline BirthDateBits* GetBirthDateBits(char* s) {return (BirthDateBits*)(s+0x569c);}
// Original: arm9/ov012 @ 0x02187ADC; symbol: func_ov012_02187adc; size: 0x508.
// Handles month adjustment, coordinate controls, and committing packed birth date and age.
extern "C" void UpdateBirthDateMonthControls(char* p) {
 if(*(unsigned char*)(p+0x1370)==4) {
 int changed=0;
 int allowCancel=1;
 int region=Util_ClassifyCoordinateInRecordRegions((unsigned char*)p);
 if(Input_PollKeyRepeatCountdown((State*)KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,128)||region<0) {
 if(*(unsigned char*)(p+0x13aa)) *(signed char*)(p+0x13a8)=3;
 if(*(signed char*)(p+0x13a9)>-3) --*(signed char*)(p+0x13a9);
 } else if(Input_PollKeyRepeatCountdown((State*)KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,64)||region>0) {
 if(*(unsigned char*)(p+0x13aa)) *(signed char*)(p+0x13a8)=2;
 if(*(signed char*)(p+0x13a9)<3) ++*(signed char*)(p+0x13a9);
 } else *(signed char*)(p+0x13a9)=0;
 Calendar_UpdateBirthDateAdjustmentFlags((unsigned char*)p);
 MonthDays table=UpdateBirthDateMonthControls_UnknownRoleInitializedBytes;
 if(*(unsigned short*)(p+0x13fc)%4==0) table.values[1]=29;
 if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,128)||*(signed char*)(p+0x13a9)<=-3) {
 if(*(unsigned char*)(p+0x13ab)&8) {
 --*(unsigned char*)(p+0x13fe);
 changed=1;
 *(signed char*)(p+0x13a8)=3;
 *(unsigned char*)(p+0x13aa)=1;
 int maxDay=table.values[*(unsigned char*)(p+0x13fe)-1];
 if(*(unsigned char*)(p+0x13ff)>maxDay) {
 *(unsigned char*)(p+0x13ff)=maxDay;
 ProfileEditor_RefreshPageText((unsigned char*)p,9,changed);
 }
 } else *(unsigned char*)(p+0x13aa)=0;
 *(signed char*)(p+0x13a9)=0;
 } else if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,64)||*(signed char*)(p+0x13a9)>=3) {
 if(*(unsigned char*)(p+0x13ab)&4) {
 ++*(unsigned char*)(p+0x13fe);
 *(signed char*)(p+0x13a8)=2;
 changed=1;
 *(unsigned char*)(p+0x13aa)=1;
 int maxDay=table.values[*(unsigned char*)(p+0x13fe)-1];
 if(*(unsigned char*)(p+0x13ff)>maxDay) {
 *(unsigned char*)(p+0x13ff)=maxDay;
 ProfileEditor_RefreshPageText((unsigned char*)p,9,changed);
 }
 } else *(unsigned char*)(p+0x13aa)=0;
 *(signed char*)(p+0x13a9)=0;
 } else if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,32)||Window_IsTouchInsideCanvas((unsigned char*)p+0xac,9)) {
 Menu_SetDateControlCanvasAttributes(p,9,1,1,0);
 changed=1; allowCancel=0;
 ProfileEditor_RefreshPageText((unsigned char*)p,8,changed);
 } else if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,16)||Window_IsTouchInsideCanvas((unsigned char*)p+0xac,7)) {
 _ZN9GameState11GetInstanceEv();
 Menu_SetDateControlCanvasAttributes(p,7,0,1,1);
 changed=1; allowCancel=0;
 ProfileEditor_RefreshPageText((unsigned char*)p,8,changed);
 } else if(Window_IsTouchInsideCanvas((unsigned char*)p+0xac,8)) allowCancel=0;
 if(changed) {
 ProfileEditor_RefreshPageText((unsigned char*)p,*(unsigned char*)(p+0x1371),1);
 SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,2,0);
 }
 int done=0;
 if(Menu_IsConfirmOrCanvasActionPressed(p)||Window_IsTouchInsideCanvas((unsigned char*)p+0xac,16)) {
 char* state=(char*)_ZN9GameState11GetInstanceEv();
 BirthDateBits* bits=GetBirthDateBits(state);
 ProfileEditor_RefreshPageText((unsigned char*)p,*(unsigned char*)(p+0x1371),1);
 SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
 bits->year=*(unsigned short*)(p+0x13fc);
 bits->month=*(unsigned char*)(p+0x13fe);
 bits->day=*(unsigned char*)(p+0x13ff);
 *(unsigned*)bits|=0x10000000;
 bits->age=Calendar_ComputeAgeFromBirthDate(*(unsigned short*)(p+0x13fc),*(unsigned char*)(p+0x13fe),*(unsigned char*)(p+0x13ff));
 ProfileEditor_RefreshPreview(p,0,-1,0);
 *(unsigned char*)(p+0x1371)=6;
 *(unsigned char*)(p+0x1370)=0;
 } else if(Menu_TestCancelKeyOrCanvasTouchKindTwo(p)&&allowCancel) done=1;
 if(done) {
 Window_PopCanvasesAndResetSelection((State*)(p+0xac),1);
 ++*(unsigned char*)(p+0x1370);
 }
 } else if(*(unsigned char*)(p+0x1370)==5) ++*(unsigned char*)(p+0x1370);
 else if(*(unsigned char*)(p+0x1370)==6) ++*(unsigned char*)(p+0x1370);
 else if(*(unsigned char*)(p+0x1370)==7) {
 *(unsigned char*)(p+0x1371)=1;
 Menu_ConfigurePairedSelectionGridsForActiveCanvas((unsigned char*)p);
 Graphics_BuildProfileSummaryPage((unsigned char*)p);
 *(unsigned char*)(p+0x13a0)=1;
 *(signed char*)(p+0x13a8)=-1;
 *(signed char*)(p+0x13a9)=0;
 *(unsigned char*)(p+0x1370)=1;
 }
}
