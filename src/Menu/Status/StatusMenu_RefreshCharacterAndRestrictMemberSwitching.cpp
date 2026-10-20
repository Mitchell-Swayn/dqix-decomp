#include <globaldefs.h>
ARM
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original data: arm9/ov004 @ 0x21707e8; symbol: data_ov004_021707e8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" void StatusMenu_RefreshCharacterHeader(void*);extern "C" void StatusMenu_RefreshEquipmentNamesAndDescriptors(void*,void*);extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" unsigned GameState_CopyActivePartySlotList(void*,void*);extern "C" char* GameState_GetObjectWithFlag100(void*,int);extern "C" int GameObject_HasLinkedStatusNibble(char*);extern "C" char* Menu_FindCanvasNodeByKey(void*,unsigned short);extern "C" char StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov004 @ 0x02162B84; symbol: HideEntry133WhenPartyFlaggedOrListSmall; size: 0xac.
extern "C" int StatusMenu_RefreshCharacterAndRestrictMemberSwitching(void* self){
StatusMenu_RefreshCharacterHeader(self);StatusMenu_RefreshEquipmentNamesAndDescriptors(self,P(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage,28));void* state=_ZN9GameState11GetInstanceEv();unsigned buffer;unsigned count=GameState_CopyActivePartySlotList(state,&buffer);int found=0;for(int i=0;i<4;i++){char* object=GameState_GetObjectWithFlag100(state,i);if(object&&GameObject_HasLinkedStatusNibble(object))found=1;}if(found==1||count<=1){char* entry=Menu_FindCanvasNodeByKey(self,133);if(!entry)return 0;B(entry,12)|=0x78;}return 0;
}
