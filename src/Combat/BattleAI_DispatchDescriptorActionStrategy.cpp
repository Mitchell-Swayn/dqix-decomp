#include <globaldefs.h>
extern "C" char* _ZN9GameState11GetInstanceEv();extern "C" char* GameState_FindIndexedObjectWithFlag400(char*,int);extern "C" unsigned Combat_SelectAutomaticActionTargets(unsigned,int,int,unsigned);
// Original data: arm9/main @ 0x20f10b0; symbol: data_020f10b0.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex aca4080200000000cca4080200000000eca40802000000002ca50802000000000ca5080200000000d8a508020000000000a708020000000040a8080200000000 ...; full span in module reference.
// Observed span: 72 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Owner{unsigned value;unsigned invoke(int,unsigned*,unsigned);};typedef unsigned(Owner::*Handler)(int,unsigned*,unsigned);extern "C" Handler BattleAIDispatchDescriptorActionStrategy_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x0208A91C; symbol: func_0208a91c; size: 0x98.
extern "C" ARM unsigned BattleAI_DispatchDescriptorActionStrategy(Owner* owner,unsigned value,int id,unsigned* out,unsigned arg){char* entity=GameState_FindIndexedObjectWithFlag400(_ZN9GameState11GetInstanceEv(),id);char* descriptor=*(char**)(entity+0x148);owner->value=value;int kind=(*(unsigned*)(descriptor+16)<<24)>>29;if(kind>=8){*out=Combat_SelectAutomaticActionTargets(owner->value,id,2,arg);return 2;}return (owner->*BattleAIDispatchDescriptorActionStrategy_UnknownRoleProcedureReferenceRecords[kind])(id,out,arg);}
