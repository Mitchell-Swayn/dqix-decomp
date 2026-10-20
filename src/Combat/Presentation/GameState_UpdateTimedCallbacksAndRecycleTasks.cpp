#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned _ZNK9GameState21GetEffectiveDeltaTimeEv(void*);
struct Task {int type;unsigned delay;int pad[4];Task* next;};
struct Owner {unsigned char pad[0xe0];Task* active;Task* free;};
// Original data: arm9/ov025 @ 0x21ef93c; symbol: data_ov025_021ef93c.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 8ceb1e02a4ec1e0200000000000000000000000000000000000000000000000000000000.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" int (*GameStateUpdateTimedCallbacksAndRecycleTasks_UnknownRoleProcedureReferenceRecords[])(Task*);
// Original: arm9/ov025 @ 0x021EEDB0; symbol: func_ov025_021eedb0; size: 0x98.
extern "C" void GameState_UpdateTimedCallbacksAndRecycleTasks(Owner* p){
 unsigned delta=_ZNK9GameState21GetEffectiveDeltaTimeEv(_ZN9GameState11GetInstanceEv());
 Task* task;
 Task* previous=0;
 task=p->active;
 while(task){
 if(delta<task->delay){task->delay-=delta;}
 else{
 task->delay=0;
 if(GameStateUpdateTimedCallbacksAndRecycleTasks_UnknownRoleProcedureReferenceRecords[task->type](task)){
 if(previous)previous->next=task->next;else p->active=task->next;
 Task* next=task->next;
 task->next=p->free;p->free=task;
 task=next;
 continue;
 }
 }
 previous=task;task=task->next;
 }
}
