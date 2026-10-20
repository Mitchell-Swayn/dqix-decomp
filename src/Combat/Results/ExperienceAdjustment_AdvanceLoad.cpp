#include <globaldefs.h>
ARM
// Original data: arm9/ov023 @ 0x21fe334; symbol: data_ov023_021fe334.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 38e31f02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" {void* _ZN16BackgroundLoader11GetInstanceEv();int _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);int _ZN16BackgroundLoader13GetTaskStatusEi(void*,int);void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);void ExperienceAdjustment_CopyTableSections(void*,void*,void*,unsigned);int BackgroundLoader_RemoveTaskAndResetLoadState(void*);extern const char* ExperienceAdjustmentAdvanceLoad_UnknownRoleDataReferences;}
// Original: arm9/ov023 @ 0x021F5340; symbol: Resource_AdvanceThreeStageFileLoad; size: 0xd0.
extern "C" int ExperienceAdjustment_AdvanceLoad(char* self){void* loader=_ZN16BackgroundLoader11GetInstanceEv();switch(*(short*)(self+12)){case 1:*(int*)(self+16)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,ExperienceAdjustmentAdvanceLoad_UnknownRoleDataReferences,0);*(short*)(self+12)=2;return ExperienceAdjustment_AdvanceLoad(self);case 2:if(!_ZN16BackgroundLoader13GetTaskStatusEi(loader,*(int*)(self+16)))return 0;*(short*)(self+12)=3;return ExperienceAdjustment_AdvanceLoad(self);case 3:{void* file=0;unsigned size=0;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,*(int*)(self+16),&file,&size);ExperienceAdjustment_CopyTableSections(self,*(void**)(self+20),file,size);BackgroundLoader_RemoveTaskAndResetLoadState(self);return 1;}default:return 1;}}
