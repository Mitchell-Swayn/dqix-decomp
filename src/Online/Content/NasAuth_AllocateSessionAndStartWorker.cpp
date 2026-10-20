#include "globaldefs.h"
#include "std_library_functions.h"
#define H(p,o) (*(unsigned short*)((unsigned char*)(p)+(o)))
#define S(p,o) (*(short*)((unsigned char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((unsigned char*)(p)+(o)))
#define P(p,o) (*(unsigned char**)((unsigned char*)(p)+(o)))
#include "System/Memory.h"
// Original data: arm9/ov031 @ 0x224e5e8; symbol: data_ov031_0224e5e8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned NasAuthDestroySession_UnknownRoleZeroInitializedStorage[];extern char NasAuth_AllocateSessionAndStartWorker_TextALLOCDWCauth[];extern "C" int NasAuth_BuildAndStartHttpRequest(int);extern "C" void System_InitializeAndStartGuardedProcessorContext();struct Configuration{unsigned words[18];};
#define Shared ((volatile unsigned*)NasAuthDestroySession_UnknownRoleZeroInitializedStorage)
// Original: arm9/ov031 @ 0x022167C8; symbol: func_ov031_022167c8; size: 0x124.
extern "C" ARM int NasAuth_AllocateSessionAndStartWorker(unsigned char*config,unsigned value){void*(*allocate)(const char*,unsigned)=*(void*(**)(const char*,unsigned))(config+64);if(Shared[2])return 2;unsigned char*memory=(unsigned char*)allocate(NasAuth_AllocateSessionAndStartWorker_TextALLOCDWCauth,0x13f4);Shared[2]=(unsigned)memory;if(!memory)return 2;VectorizedMemset(memory,0,0x13f4);W(Shared[2],0x1314)=value;Shared[0]=0;VectorizedMemset((unsigned char*)Shared[2]+0x1008,0,0x1c4);W(Shared[2],0x1008)=0x4e84;unsigned char*copyTarget=(unsigned char*)Shared[2];*(Configuration*)(copyTarget+0x11cc)=*(Configuration*)config;H(copyTarget,0x11fe)=0;((unsigned char*)Shared[2])[0x120b]=0;unsigned task=NasAuth_BuildAndStartHttpRequest(1);W(Shared[2],0x1004)=task;unsigned result=W(Shared[2],0x1004);if(result)return result;Shared[1]=0;System_InitializeAndStartGuardedProcessorContext();return 0;}