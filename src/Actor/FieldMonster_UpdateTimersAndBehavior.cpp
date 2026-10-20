#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void Object3D_AdvanceMotionAnimationAndLinkedPoint(void*);
extern "C" unsigned _ZNK9GameState21GetEffectiveDeltaTimeEv(void*);
extern "C" void Object3D_SelectTargetAndTransitionToStateTen(void*);
struct ObjectView;typedef void(ObjectView::*StateMethod)();
// Original data: arm9/main @ 0x20e892c; symbol: data_020e892c.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 5c6d070200000000f46d070200000000fc7107020000000030760702000000008877070200000000e07b07020000000050800702000000009883070200000000 ...; full span in module reference.
// Observed span: 104 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" StateMethod FieldMonsterUpdateTimersAndBehavior_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x02076B58; symbol: UpdateObjectTimersAndDispatchState; size: 0x94.
// Accumulates delta timers and frame count, transitions target, then invokes indexed member state method.
extern "C" void FieldMonster_UpdateTimersAndBehavior(char* object){
 void* state=_ZN9GameState11GetInstanceEv();Object3D_AdvanceMotionAnimationAndLinkedPoint(object);
 *(unsigned*)(object+0x14c)+=_ZNK9GameState21GetEffectiveDeltaTimeEv(state);
 if(*(int*)(object+0x130))*(unsigned*)(object+0x154)+=_ZNK9GameState21GetEffectiveDeltaTimeEv(state);
 ++*(unsigned*)(object+0x150);Object3D_SelectTargetAndTransitionToStateTen(object);
 (((ObjectView*)object)->*FieldMonsterUpdateTimersAndBehavior_UnknownRoleProcedureReferenceRecords[*(int*)(object+0x130)])();
}
