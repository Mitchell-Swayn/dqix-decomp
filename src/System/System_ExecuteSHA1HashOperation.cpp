#include <globaldefs.h>
ARM
struct HashContext {int a,b;void* state;void* digest;void (*init)();void (*update)();void (*finish)();};
// Original data: arm9/main @ 0x20e93fc; symbol: data_020e93fc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 14000000400000000000000000000000000000000000000000000000140000004000000000000000000000000000000000000000000000001400000040000000 ...; full span in module reference.
// Observed span: 84 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" HashContext SystemExecuteSHA1HashOperation_UnknownRoleInitializedBytes;
extern "C" void SHA1_InitializeState();
extern "C" void Hash_Update64ByteBlocks();
extern "C" void Util_FinalizeSHA1Digest();
extern "C" void Util_ComputeHMAC(void*,unsigned,void*,unsigned,unsigned,HashContext*);
// Original: arm9/main @ 0x020C0C3C; symbol: func_020c0c3c; size: 0x94.
extern "C" void System_ExecuteSHA1HashOperation(void* a,unsigned b,void* c,unsigned d,unsigned e){
 unsigned char state[104];unsigned char digest[20];
 HashContext context=SystemExecuteSHA1HashOperation_UnknownRoleInitializedBytes;
 context.state=state;context.digest=digest;
 context.init=SHA1_InitializeState;context.update=Hash_Update64ByteBlocks;context.finish=Util_FinalizeSHA1Digest;
 Util_ComputeHMAC(a,b,c,d,e,&context);
}
