#include <globaldefs.h>
ARM
#pragma always_inline on
struct Vector3i { int x,y,z; };struct PhaseState;
extern "C" {
void Camera_StartEyeApproach(unsigned char*,const Vector3i*,int);
void SetVectorTargetAndClearFlagBitOne(unsigned char*,const Vector3i*,int);
void CharacterCreation_EnterPhaseAndMarkScreenDirty(PhaseState*,int);void ApplyChoiceToPairedObjectSettings(unsigned char*,int);
void ConfigureGridSelectionForCurrentMode(unsigned char*);void CharacterCreation_LoadPhaseChoiceGridLayout(void*);void CharacterCreation_PositionChoiceCursor(void*,int);int CharacterCreation_ProcessChoiceAndPhaseNavigation(void*);
// Original data: arm9/ov009 @ 0x218a9f8; symbol: data_ov009_0218a9f8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 009000000028010000f00200.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov009.md.
// Original data: arm9/ov009 @ 0x218aa04; symbol: data_ov009_0218aa04.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 009000000028010000000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov009.md.
// Original data: arm9/ov009 @ 0x218aa10; symbol: data_ov009_0218aa10.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00d0000000f80000cc2c0400.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov009.md.
// Original data: arm9/ov009 @ 0x218aa1c; symbol: data_ov009_0218aa1c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00d0000000f8000000000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov009.md.
extern Vector3i AdvanceModeSevenChoicePhaseAndVectors_UnknownRoleInitializedBytes,AdvanceModeSevenChoicePhaseAndVectors_UnknownRoleInitializedBytes_Variant2,AdvanceModeSevenChoicePhaseAndVectors_UnknownRoleInitializedBytes_Variant3,AdvanceModeSevenChoicePhaseAndVectors_UnknownRoleInitializedBytes_Variant4;
}
// Original: arm9/ov009 @ 0x02186C00; symbol: func_ov009_02186c00; size: 0x200.
// Configures choice selection, waits for a pending swap, then transitions vectors on phase changes.
extern "C" void AdvanceModeSevenChoicePhaseAndVectors(unsigned char* p) {
 if(p[0xc59]==0) {
  ConfigureGridSelectionForCurrentMode(p);CharacterCreation_LoadPhaseChoiceGridLayout(p);
  CharacterCreation_PositionChoiceCursor(p,(p+p[0xda3])[0xda8]);
  Vector3i first=AdvanceModeSevenChoicePhaseAndVectors_UnknownRoleInitializedBytes,second=AdvanceModeSevenChoicePhaseAndVectors_UnknownRoleInitializedBytes_Variant2;
  Camera_StartEyeApproach(p+0x924,&first,0x1e000);
  SetVectorTargetAndClearFlagBitOne(p+0x924,&second,0x1e000);
  *(unsigned*)(p+0x804)=0x1eb;
  *(unsigned*)(p+0xd9c)=(*(unsigned*)(p+0xd9c)|8)&~1;
  ++p[0xc59];
 }else if(p[0xc59]==1) {
  if(!(*(unsigned*)(p+0xd9c)&0x80)) {
   ApplyChoiceToPairedObjectSettings(p,(p+p[0xda3])[0xda8]);++p[0xc59];
  }
 }else if(p[0xc59]==2) {
  if(!(*(unsigned*)(p+0xd9c)&1)) {
   if(!(*(unsigned*)(p+0xd9c)&8))*(unsigned*)(p+0xd9c)|=1;
  }
  int selected=CharacterCreation_ProcessChoiceAndPhaseNavigation(p);
  bool changed=false;
  if(selected==-2) {CharacterCreation_EnterPhaseAndMarkScreenDirty((PhaseState*)p,8);changed=true;}
  else if(selected==-3) {CharacterCreation_EnterPhaseAndMarkScreenDirty((PhaseState*)p,6);changed=true;}
  else if(selected>=0x65 && selected<=0x6c) {
   int phase=selected-0x64;
   if(phase<=*(signed char*)(p+0xda0+p[0xda3]) && phase!=*(signed char*)(p+0xc58)) {
    CharacterCreation_EnterPhaseAndMarkScreenDirty((PhaseState*)p,(unsigned char)phase);changed=true;
   }
  }
  if(changed) {
   Vector3i first=AdvanceModeSevenChoicePhaseAndVectors_UnknownRoleInitializedBytes_Variant3,second=AdvanceModeSevenChoicePhaseAndVectors_UnknownRoleInitializedBytes_Variant4;
   Camera_StartEyeApproach(p+0x924,&first,0x1e000);
   SetVectorTargetAndClearFlagBitOne(p+0x924,&second,0x1e000);
  }
 }
}
