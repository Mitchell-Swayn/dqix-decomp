#include <globaldefs.h>
extern "C" void ResolveTwoValuesThroughSharedObject();extern "C" void InitializeSerializedResourceUnlessReady(unsigned,unsigned,unsigned*,void(*)());
// Original: arm9/main @ 0x020E56FC; symbol: func_020e56fc; size: 0x2C.
extern "C" ARM int InitializeResourceContextWhenInputsPresent(unsigned a,unsigned b,unsigned c,unsigned d){unsigned context;if(b&&c){InitializeSerializedResourceUnlessReady(a,b,&context,ResolveTwoValuesThroughSharedObject);return 1;}return 0;}
