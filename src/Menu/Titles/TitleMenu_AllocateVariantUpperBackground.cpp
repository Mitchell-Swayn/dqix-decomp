#include <globaldefs.h>
ARM
extern "C" int MenuRecordList_AppendKeyedRecord(...);
extern "C" int Menu_FindSessionArenaById(...);
extern "C" int MenuLayerRecord_InitializeAndAllocateScreenBuffer(...);
extern "C" int _ZN13SafeAllocator8AllocateEj(...);
extern "C" int _ZN9GameState11GetInstanceEv(...);
extern "C" int _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(...);
extern "C" int Menu_GetDisplayRecordRegistry(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
extern "C" char TitleMenu_AllocateVariantUpperBackground_TextMenuBgUpGp2[];
extern "C" char TitleMenu_AllocateVariantUpperBackground_MarkupBgUpLGPac[];
extern "C" char TitleMenu_AllocateVariantUpperBackground_TextMenuBgUp1Gp2[];
extern "C" char TitleMenu_AllocateVariantUpperBackground_MarkupBgUp1LGPac[];
extern "C" char TitleMenu_AllocateVariantUpperBackground_TextMenuBgUp2Gp2[];
extern "C" char TitleMenu_AllocateVariantUpperBackground_MarkupBgUp2LGPac[];
// Original data: arm9/ov023 @ 0x21fe4f0; symbol: data_ov023_021fe4f0.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 50751f02b8691f02e8691f0264781f0284781f02a4781f0284791f02147d1f02487d1f0258741f0250741f024c741f0244741f0240741f0238741f029c7d1f02 ...; full span in module reference.
// Observed span: 252 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" char MenuCreateNamedBackgroundCanvas_UnknownRoleProcedureReferenceRecords[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov004 @ 0x0216E0C0; symbol: AllocateLocaleSpecificTypeTwoCanvasNode.
extern "C" int TitleMenu_AllocateVariantUpperBackground(char*context){
char*file=0,*archive=0;unsigned mode=B(C(_ZN9GameState11GetInstanceEv()),0x7f71);switch(mode){case 0:archive=TitleMenu_AllocateVariantUpperBackground_TextMenuBgUpGp2;file=TitleMenu_AllocateVariantUpperBackground_MarkupBgUpLGPac;break;case 1:archive=TitleMenu_AllocateVariantUpperBackground_TextMenuBgUp1Gp2;file=TitleMenu_AllocateVariantUpperBackground_MarkupBgUp1LGPac;break;case 2:archive=TitleMenu_AllocateVariantUpperBackground_TextMenuBgUp2Gp2;file=TitleMenu_AllocateVariantUpperBackground_MarkupBgUp2LGPac;break;}char*tree=C(Menu_FindSessionArenaById(context,3));if(!tree)return 0;_ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(tree+4);char*record=C(_ZN13SafeAllocator8AllocateEj(tree+4,84));if(!record)return 0;char prototype[84];P(prototype,0)=MenuCreateNamedBackgroundCanvas_UnknownRoleProcedureReferenceRecords;memcpy(record,prototype,84);MenuLayerRecord_InitializeAndAllocateScreenBuffer(record,context,105,3,archive,file,1,2,0);MenuRecordList_AppendKeyedRecord(Menu_GetDisplayRecordRegistry(context),record);return 0;
}
