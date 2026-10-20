#include <globaldefs.h>
ARM
#pragma always_inline on
#pragma optimize_for_size on
#pragma optimization_level 4
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {extern char Main_UnknownRoleZeroInitializedStorage[];void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);void BattleCombo_RequestIndicatorExit(void*,int);}
struct Object {char pad[0x6e8];unsigned char current,previous;short timer,elapsed;};
inline void ClearStatus(Object* p){p->previous=0;p->current=0;p->timer=0;}
// Original: arm9/ov000 @ 0x021823DC; symbol: func_ov000_021823dc; size: 0xBC.
extern "C" void SetBoundedStatusAndDispatchTransition(Object* p,int status){
if(status>3)status=3;
if(status>0){
if(status==p->current){if(p->timer!=0)return;}
p->previous=p->current;p->current=status;p->timer=30;p->elapsed=0;
if(status==1)SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,26,0);
else if(status==2)SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,23,0);
else SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,24,0);
}else{
if(p->current!=0){BattleCombo_RequestIndicatorExit(p,1);return;}
ClearStatus(p);
}
}
