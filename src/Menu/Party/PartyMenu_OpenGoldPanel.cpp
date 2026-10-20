struct PartyMenuState;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetIndexList(void*);
extern "C" unsigned int TextContext_GetSharedInstance(void*);
extern "C" void TextLayout_ResetFormattingWorkspace(signed char*);
extern "C" void TextContext_SetNumericArgument(unsigned int*,int,unsigned int);
extern "C" void TextContext_SetNumericArgumentAlignment(char*,int,int);
extern "C" void TextContext_SetNumericArgumentWidth(char*,int,int);
extern "C" void* Text_LookupStandardString(unsigned);
extern "C" void TextMarkup_ExpandAndWrapText(void*,int,void*,void*,int,int,unsigned);
extern "C" void PartyMenu_ConfigurePanelLayout(PartyMenuState*,int,int,int);
extern "C" void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);
extern "C" int Window_UpdateCanvasesAndSelection(unsigned char*,unsigned);
extern "C" void* memset(void*,int,unsigned);
// Original: arm9/ov002 @ 0x0215BF34; symbol: InitializeSelectionWorkspace; size: 0xF4.
extern "C" void PartyMenu_OpenGoldPanel(void* owner) {
    PartyMenu_ConfigurePanelLayout((PartyMenuState*)(owner),0x29,0x15,0x15);
    void* state=_ZN9GameState11GetInstanceEv();
    void* indexList=GameState_GetIndexList(state);
    unsigned int* record=(unsigned int*)TextContext_GetSharedInstance(indexList);
    TextLayout_ResetFormattingWorkspace((signed char*)record);
    unsigned int* values=(unsigned int*)((char*)indexList+0xf6c);
    TextContext_SetNumericArgument(record,0,*(unsigned int*)values);
    TextContext_SetNumericArgumentAlignment((char*)record,0,1);
    TextContext_SetNumericArgumentWidth((char*)record,0,7);
    memset(*(void**)((char*)owner+0x1bd0),0,0x960);
    void* resource=Text_LookupStandardString(0x3f1);
    TextMarkup_ExpandAndWrapText(record,8,resource,*(void**)((char*)owner+0x1bd0),0x100,0,0);
    Window_PushTextCanvas((char*)owner+0xec8,*(void**)((char*)owner+0x1bd0),0,0,0,0,0,0);
    Window_UpdateCanvasesAndSelection((unsigned char*)owner+0xec8,4);
}
