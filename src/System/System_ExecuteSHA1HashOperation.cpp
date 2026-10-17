#include <globaldefs.h>
ARM
struct HashContext {int a,b;void* state;void* digest;void (*init)();void (*update)();void (*finish)();};
extern "C" HashContext data_020e93fc;
extern "C" void InitializeSHA1State();
extern "C" void Hash_Update64ByteBlocks();
extern "C" void Util_FinalizeSHA1Digest();
extern "C" void Util_ComputeHMAC(void*,unsigned,void*,unsigned,unsigned,HashContext*);
// Original: arm9/main @ 0x020C0C3C; symbol: func_020c0c3c; size: 0x94.
extern "C" void System_ExecuteSHA1HashOperation(void* a,unsigned b,void* c,unsigned d,unsigned e){
 unsigned char state[104];unsigned char digest[20];
 HashContext context=data_020e93fc;
 context.state=state;context.digest=digest;
 context.init=InitializeSHA1State;context.update=Hash_Update64ByteBlocks;context.finish=Util_FinalizeSHA1Digest;
 Util_ComputeHMAC(a,b,c,d,e,&context);
}
