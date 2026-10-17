#include <globaldefs.h>
#include <Resource/Script.h>
#pragma always_inline on
struct Output { unsigned value; unsigned short count; };
struct Context { unsigned* count; void* arguments; Output* output; void* owner; inline void SetArguments(unsigned* c,void* a) {arguments=a;count=c;} }; extern Context data_02108fd4; extern Script::OpcodeLookupEntry data_020f1258[];
// The known overlay 13 caller supplies an argument-array pointer then a count
// in the fifth and sixth stack slots. The count address is consumed during Execute.
// Original: arm9/main @ 0x0208DF20; symbol: func_0208df20; size: 0x74.
extern "C" void Script_ExecuteWithArgumentsAndOutputRecord(Output* out,void* owner,const void* data,unsigned size,void* arguments,unsigned count) { void* args=arguments; out->value=0; out->count=0; data_02108fd4.owner=owner; data_02108fd4.SetArguments(&count,args); data_02108fd4.output=out; Script script; script.Initialize(); script.SetOpcodeLookup(data_020f1258); script.Load(data,size); script.Execute(); }
