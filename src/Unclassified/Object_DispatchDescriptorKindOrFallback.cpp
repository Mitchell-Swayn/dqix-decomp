#include <globaldefs.h>
extern "C" char* _ZN9GameState11GetInstanceEv();extern "C" char* GameState_FindIndexedObjectWithFlag400(char*,int);extern "C" unsigned func_ov000_02154a04(unsigned,int,int,unsigned);
struct Owner{unsigned value;unsigned invoke(int,unsigned*,unsigned);};typedef unsigned(Owner::*Handler)(int,unsigned*,unsigned);extern "C" Handler data_020f10b0[];
// Original: arm9/main @ 0x0208A91C; symbol: func_0208a91c; size: 0x98.
extern "C" ARM unsigned Object_DispatchDescriptorKindOrFallback(Owner* owner,unsigned value,int id,unsigned* out,unsigned arg){char* entity=GameState_FindIndexedObjectWithFlag400(_ZN9GameState11GetInstanceEv(),id);char* descriptor=*(char**)(entity+0x148);owner->value=value;int kind=(*(unsigned*)(descriptor+16)<<24)>>29;if(kind>=8){*out=func_ov000_02154a04(owner->value,id,2,arg);return 2;}return (owner->*data_020f10b0[kind])(id,out,arg);}
