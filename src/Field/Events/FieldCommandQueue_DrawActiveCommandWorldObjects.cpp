#include <globaldefs.h>
ARM
extern "C" int FieldBattle_DrawCombatantsAndSelectionEffects(...);
extern "C" int Resource_DispatchGameResourceEntryWord(...);
extern "C" int Field_DrawSharedSubscreenAttachedModel(...);
extern "C" int Town_DrawModalOverlayAttachments(...);
extern "C" int Graphics_DrawAndUpdateEmbeddedObjectFromFieldC(...);
extern "C" int KrakPot_DrawFieldMenuSession(...);
extern "C" int Field_IgnoreOverlayThirtyOneUpdateHook(...);
extern "C" int FieldScreen_InvokeSecondVirtualOnCanvasNodes(...);
extern "C" int Field_DrawPartyManagementProtagonistPreview(...);
extern "C" int FieldScreen_DrawOptionalMappedObjects(...);
extern "C" int RecordsScreen_DrawOptionalPanel(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov017 @ 0x021A3DDC; symbol: DispatchUnfinishedResourceOperationBySignedKind.
extern "C" void FieldCommandQueue_DrawActiveCommandWorldObjects(int unused,char*object){
if(!object)return;if(B(object,1))return;switch(*(signed char*)object){case 2:Field_DrawSharedSubscreenAttachedModel(object);break;case 10:FieldBattle_DrawCombatantsAndSelectionEffects(object);break;case 23:Field_DrawPartyManagementProtagonistPreview(object);break;case 24:Town_DrawModalOverlayAttachments(object);break;case 38:Resource_DispatchGameResourceEntryWord(object);break;case 40:FieldScreen_DrawOptionalMappedObjects(object);break;case 41:RecordsScreen_DrawOptionalPanel(object);break;case 42:Graphics_DrawAndUpdateEmbeddedObjectFromFieldC(object);break;case 43:KrakPot_DrawFieldMenuSession(object);break;case 44:Field_IgnoreOverlayThirtyOneUpdateHook(object);break;case 45:FieldScreen_InvokeSecondVirtualOnCanvasNodes(object);break;}
}
