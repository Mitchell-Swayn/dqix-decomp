#include <globaldefs.h>
ARM
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader8AddFenceEv(void*);
extern "C" unsigned _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*,const char*,const char*,void*);
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
extern "C" void SpellTable_ClearBinding(void*);
extern "C" void SkillTable_Reset(unsigned*);
// Original data: arm9/main @ 0x20f2a18; symbol: data_020f2a18.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 062b0f02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const char* ItemTradeAdvanceIncomingOffer_UnknownRoleDataReferences_Variant2;
// Original data: arm9/main @ 0x20f2a0c; symbol: data_020f2a0c.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex b62a0f02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const char* ItemTradeAdvanceIncomingOffer_UnknownRoleDataReferences;
extern "C" const char Resource_QueueThreeFilesAndInitializeRecords_PathDataPrmSpelltableBin[];
extern "C" const char Resource_QueueThreeFilesAndInitializeRecords_PathDataPrmSkilltableBin[];
// Original: arm9/ov002 @ 0x02156BC8; symbol: func_ov002_02156bc8; size: 0xB4.
extern "C" void Resource_QueueThreeFilesAndInitializeRecords(char* self) {
if(*(unsigned*)(self+0x247c)&0x10) return;
void* loader=_ZN16BackgroundLoader11GetInstanceEv();
_ZN16BackgroundLoader8AddFenceEv(loader);
*(unsigned*)(self+0x1ba4)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,ItemTradeAdvanceIncomingOffer_UnknownRoleDataReferences_Variant2,ItemTradeAdvanceIncomingOffer_UnknownRoleDataReferences,0);
*(unsigned*)(self+0x1ba8)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,Resource_QueueThreeFilesAndInitializeRecords_PathDataPrmSpelltableBin,0);
*(unsigned*)(self+0x1bac)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,Resource_QueueThreeFilesAndInitializeRecords_PathDataPrmSkilltableBin,0);
SpellTable_ClearBinding(self+0x2444);
SkillTable_Reset((unsigned*)(self+0x243c));
*(unsigned*)(self+0x247c)|=0x10;
}
