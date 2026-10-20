struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
extern "C" void __clear(void*,unsigned);
extern "C" void* Zone3D_GetMainInstance();
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" int Selection_ReadEnabledIndexFromControl(void*);
extern "C" int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
extern "C" const char* ResourceStringTable_GetTextByKey(void*,int);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int Text_AppendFormatString(char*,const char*);
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
extern "C" void DisplayRecord_SetActiveAndResetSelection(unsigned char*,unsigned);
extern "C" void DisplayRecord_SetPrimarySelectionAndMarkDirty(unsigned char*,int);
extern "C" void DisplayRecord_SetSecondarySelectionAndMarkDirty(unsigned char*,unsigned char);
extern "C" int Window_ReplaceCanvasTextById(void*,unsigned,void*,unsigned,unsigned char);
// Original data: arm9/ov003 @ 0x2180c7f; symbol: data_ov003_02180c7f.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0a0000000000000000000000000000000000000000000000000000000000000000.
// Observed span: 33 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" const char TextRefreshSixEntryPage_UnknownRoleInitializedBytes[];
// Original: arm9/ov003 @ 0x0217DFB4; symbol: func_ov003_0217dfb4; size: 0x14C.
extern "C" void Text_RefreshSixEntryPage(char* self) {
 Zone3D_GetMainInstance(); TextContext_GetSharedInstance();
 char text[1024]; __clear(text,1024);
 char* owner=*(char**)(self+0x90);
 int end,i; int page=*(int*)(owner+0x68);
 end=(page+1)*6;
 if(end>*(unsigned char*)(self+0x30))end=*(unsigned char*)(self+0x30);
 if(*(int*)(self+0x14)==2)TextMarkup_AppendFrameTag(text,Selection_ReadEnabledIndexFromControl(owner)%6,8,5,5,5);
 for(i=page*6;i<end;i++) {
 const char* label=ResourceStringTable_GetTextByKey(self+0xcc,(short)(*(unsigned char*)(self+i+0x18)+100));
 Text_AppendFormattedIntegerAndStringFragment(text,i%6,label);
 if(i!=end-1)Text_AppendFormatString(text,TextRefreshSixEntryPage_UnknownRoleInitializedBytes);
 }
 if(*(unsigned char*)(self+0x32)>1) {
 unsigned char* record=(unsigned char*)Window_FindActiveCanvasById((WindowCanvasOwner*)(*(void**)(self+0x90)),0);
 if(record) {
 DisplayRecord_SetActiveAndResetSelection(record,1);
 DisplayRecord_SetPrimarySelectionAndMarkDirty(record,(unsigned char)page);
 DisplayRecord_SetSecondarySelectionAndMarkDirty(record,*(unsigned char*)(self+0x32));
 }
 }
 Window_ReplaceCanvasTextById(*(void**)(self+0x90),0,text,1,0);
}
