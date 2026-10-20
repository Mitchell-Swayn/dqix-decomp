#include <globaldefs.h>
ARM
extern "C" char* Menu_GetDisplayRecordRegistry(...);
extern "C" char* MenuRecordList_LocateByKey(...);
extern "C" int GameState_UpdateIndexedNodeIfTypeSeven(...);
extern "C" int Menu_AllocateAndAppendTextLabelWidget(...);
extern "C" int TitleMenu_ConfigureTextCanvasAndAdvanceCharacterOffset(...);
extern "C" int Menu_BindExistingWidgetToSelectionGridCell(...);
extern "C" int TitleMenu_BindMappedActivationCallbacks(...);
extern "C" int GameState_UpdateIndexedNodeIfTypeSeven(...);
extern "C" int TitleMenu_BindMappedActivationCallbacks(...);
// Original data: arm9/ov004 @ 0x2171034; symbol: data_ov004_02171034.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage[];
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov004 @ 0x0216C750; symbol: Resource_InitializeIndexedTypeSevenDisplay; size: 0xc0.
// Resource InitializeIndexedTypeSevenDisplay from listed field operations and calls.
extern "C" int Resource_InitializeIndexedTypeSevenDisplay(void* self){char* record=MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(self),1);if(record)B(record,12)|=8;GameState_UpdateIndexedNodeIfTypeSeven(self,300);Menu_AllocateAndAppendTextLabelWidget(self,50,2,212,54,10,10,12,1);W(InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage,12)=TitleMenu_ConfigureTextCanvasAndAdvanceCharacterOffset(self,212,96,0);Menu_BindExistingWidgetToSelectionGridCell(self,300,50,0);TitleMenu_BindMappedActivationCallbacks(self,50,201,0);return 0;}
