#include <globaldefs.h>
ARM
struct Buffer;
struct MapGameObject;
extern "C" {
void* memset(void*, int, unsigned int);
void* _ZN9GameState11GetInstanceEv();
MapGameObject* _ZN9GameState20GetUnknownGameObjectEv(void*);
unsigned int TextContext_GetSharedInstance();
void TextLayout_ResetFormattingWorkspace(signed char*);
void TextContext_SetStringArgument(Buffer*,int,const char*);
void TextContext_SetNumericArgument(unsigned int*,int,unsigned int);
void Text_LoadItemNameRecord(int,unsigned int,int,int);
void* Text_ClearNameDescriptor(void*);
int MiniMedalMenu_GetPlacementState(void*,unsigned short);
void GameState_ComputeNextThresholdAndPartyContribution(short*,short*,short*,unsigned char*,int* volatile);
// Original data: arm9/ov004 @ 0x2170010; symbol: data_ov004_02170010.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0400.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern short PopulateOwnerThresholdSlotsAndResourceText_UnknownRoleInitializedBytes[][2];
// Original data: arm9/ov004 @ 0x2171024; symbol: data_ov004_02171024.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern void* ScriptInitializeLookupBuffers_UnknownRoleZeroInitializedStorage[3];
}
// Original: arm9/ov004 @ 0x02167B78; symbol: func_ov004_02167b78; size: 0x18C.
// Populates owner status slots and optional indexed resource text from party thresholds.
extern "C" int PopulateOwnerThresholdSlotsAndResourceText(void* object, short* entry) {
 short current, contribution, next; unsigned char reached; int tier;
 GameState_ComputeNextThresholdAndPartyContribution(&current,&contribution,&next,&reached,&tier);
 short total=current+contribution;
 if(total>80) total=80;
 unsigned int* owner=(unsigned int*)TextContext_GetSharedInstance();
 TextLayout_ResetFormattingWorkspace((signed char*)owner);
 MapGameObject* gameObject=_ZN9GameState20GetUnknownGameObjectEv(_ZN9GameState11GetInstanceEv());
 if(gameObject) TextContext_SetStringArgument((Buffer*)owner,0,*(const char**)((char*)gameObject+0x134));
 int active=MiniMedalMenu_GetPlacementState(object,5);
 TextContext_SetNumericArgument(owner,0,current);
 TextContext_SetNumericArgument(owner,1,contribution);
 TextContext_SetNumericArgument(owner,2,next);
 TextContext_SetNumericArgument(owner,3,total);
 if(active){
  if(!entry && tier>=0) entry=PopulateOwnerThresholdSlotsAndResourceText_UnknownRoleInitializedBytes[tier];
  if(entry){
   if(ScriptInitializeLookupBuffers_UnknownRoleZeroInitializedStorage[1] && ScriptInitializeLookupBuffers_UnknownRoleZeroInitializedStorage[0] && ScriptInitializeLookupBuffers_UnknownRoleZeroInitializedStorage[2]){
    Text_ClearNameDescriptor(ScriptInitializeLookupBuffers_UnknownRoleZeroInitializedStorage[1]);
    ((void**)ScriptInitializeLookupBuffers_UnknownRoleZeroInitializedStorage[1])[0]=ScriptInitializeLookupBuffers_UnknownRoleZeroInitializedStorage[0];
    ((void**)ScriptInitializeLookupBuffers_UnknownRoleZeroInitializedStorage[1])[1]=ScriptInitializeLookupBuffers_UnknownRoleZeroInitializedStorage[2];
    memset(ScriptInitializeLookupBuffers_UnknownRoleZeroInitializedStorage[0],0,128);
    memset(ScriptInitializeLookupBuffers_UnknownRoleZeroInitializedStorage[2],0,128);
   }
   ((void(*)(int,unsigned int))Text_LoadItemNameRecord)(entry[1],(unsigned int)ScriptInitializeLookupBuffers_UnknownRoleZeroInitializedStorage[1]);
   owner[6]=(unsigned int)ScriptInitializeLookupBuffers_UnknownRoleZeroInitializedStorage[1];
   TextContext_SetNumericArgument(owner,2,entry[0]);
  }
 }
 return 0;
}
