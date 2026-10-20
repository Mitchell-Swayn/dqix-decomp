#include <globaldefs.h>
#include "GameState/GameState.h"
ARM
#pragma force_active on
extern "C" int Party_ApplyMPCostDiscount(int,int);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void TextLayout_ResetFormattingWorkspace(signed char*);
extern "C" void TextContext_SetNumericArgument(unsigned*,int,unsigned);
extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);
extern "C" void TextMarkup_ExpandAndWrapText(void*,int,void*,void*,int,int,unsigned);
// Original: arm9/main @ 0x020FDCB0; historical symbol: data_020fdcb0 (BSS).
// Initial values are zero at load; mutable at runtime.
// Opaque fallback storage; non-owning object-representation byte view. Here
// only a 4-byte field at signed object-id * 32 +4 is read. No logical extent
// is inferred. Owning-type and all-TU migration is required before typed
// storage acceptance; other current consumer projections remain baseline debt.
extern "C" char GraphicsSelectObjectRatioColor_UnknownRoleZeroInitializedStorage[];
struct ActionMpCostView {unsigned cost:8,other:24;};
// Original: arm9/ov002 @ 0x0215F084; symbol: func_ov002_0215f084; size: 0xEC.
extern "C" void PartyMenu_FormatSelectedActionMpCost(void* menu,void* output,int) {
    char* self=(char*)menu;
    if(!output) return;
    GameObject* object=GameState::GetInstance()->GetPartyMemberByIndex(*(signed char*)(self+0x1c20));
    if(!object) return;
    int selected=*(short*)(self+0x1bfa);
    char* action=0;
    if(selected>=0 && selected<32) action=*(char**)(self+0x24a0+selected*4);
    if(!action) return;
    int cost=Party_ApplyMPCostDiscount((int)object,((ActionMpCostView*)(action+8))->cost);
    char* display=GraphicsSelectObjectRatioColor_UnknownRoleZeroInitializedStorage+*(short*)((char*)object+4)*32;
    unsigned context=TextContext_GetSharedInstance();
    TextLayout_ResetFormattingWorkspace((signed char*)context);
    TextContext_SetNumericArgument((unsigned*)context,0,cost);
    TextContext_SetNumericArgument((unsigned*)context,1,*(unsigned*)(display+4));
    void* text=ResourceStringTable_GetTextByKey(self+0x20,(void*)0xbb8);
    TextMarkup_ExpandAndWrapText((void*)context,10,text,output,256,0,0);
}
