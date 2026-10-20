#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/ov004 @ 0x21707c0; symbol: data_ov004_021707c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
struct State;extern "C" void* Menu_GetDisplayRecordRegistry(State*);extern "C" void* MenuRecordList_LocateByKey(void**,unsigned short);extern "C" unsigned MenuRecord_GetType(void*);extern "C" void MenuTextCanvas_RefreshConfiguredFrameAndContents(void*,void*);extern "C" char* SumSixIndexedEntryByteValues_UnknownRoleZeroInitializedStorage;extern "C" void Menu_CopyPositionUnlessSourceDescriptorIsActive(void*,int,int);
// Original: arm9/ov004 @ 0x02154250; symbol: Graphics_UpdateHealthPercentageAndLinkedTypeSix; size: 0xFC.
extern "C" int Menu_DisplayCatalogueCompletionRatio(void* self){short current=H(SumSixIndexedEntryByteValues_UnknownRoleZeroInitializedStorage,0x7a);short percent=(current*100)/H(SumSixIndexedEntryByteValues_UnknownRoleZeroInitializedStorage,0x78);if(!percent&&!current)percent=0;if(!percent&&current)percent=1;if(percent>100)percent=100;if(percent<0)percent=0;void** list=(void**)Menu_GetDisplayRecordRegistry((State*)self);void* object=MenuRecordList_LocateByKey(list,19);if(!object)return 0;((void(*)(void*,int))(*(void***)object)[56])(object,percent);object=MenuRecordList_LocateByKey(list,20);if(!object)return 0;((void(*)(void*,int))(*(void***)object)[56])(object,current);Menu_CopyPositionUnlessSourceDescriptorIsActive(self,20,25);object=MenuRecordList_LocateByKey(list,16);if(!object)return 0;if(MenuRecord_GetType(object)!=6)return 0;MenuTextCanvas_RefreshConfiguredFrameAndContents(object,self);return 0;}
