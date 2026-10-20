#include <globaldefs.h>
ARM
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
// Original data: arm9/ov017 @ 0x21d83ac; symbol: data_ov017_021d83ac.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" void* FieldMenuUpdatePartyMenuOverlay_UnknownRoleZeroInitializedStorage;extern "C" void PartyMenu_ReleaseControllerResources(void*);extern "C" char* GameResources_GetInstance();extern "C" int LinkedList_ContainsTag(void*,int);extern "C" void OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay(int);extern "C" void OverlayLoader_PopSecondarySelectionAndOptionallyRestoreOverlay(int);extern "C" void CleanupScriptStateAndFreeAllocator(void*);
// Original: arm9/ov017 @ 0x021A5974; symbol: ReleaseScriptAndPopOverlayAccordingToQueuedTags; size: 0xb4.
extern "C" void FieldMenu_ReleasePartyMenuAndRestoreOverlaySelections(char* self){
if(FieldMenuUpdatePartyMenuOverlay_UnknownRoleZeroInitializedStorage){PartyMenu_ReleaseControllerResources(FieldMenuUpdatePartyMenuOverlay_UnknownRoleZeroInitializedStorage);FieldMenuUpdatePartyMenuOverlay_UnknownRoleZeroInitializedStorage=0;}char* resources=GameResources_GetInstance();void* queue=P(resources,0x36fc);if(queue&&(LinkedList_ContainsTag(queue,2)||LinkedList_ContainsTag(queue,47)||LinkedList_ContainsTag(queue,45))){OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay(0);OverlayLoader_PopSecondarySelectionAndOptionallyRestoreOverlay(0);}else{OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay(1);OverlayLoader_PopSecondarySelectionAndOptionallyRestoreOverlay(1);}CleanupScriptStateAndFreeAllocator(self);B(self,1)=1;
}
