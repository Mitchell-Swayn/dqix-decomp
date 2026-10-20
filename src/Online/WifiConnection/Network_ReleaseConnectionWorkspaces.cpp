#include "globaldefs.h"
#include "std_library_functions.h"
#define H(p,o) (*(unsigned short*)((unsigned char*)(p)+(o)))
#define S(p,o) (*(short*)((unsigned char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((unsigned char*)(p)+(o)))
#define P(p,o) (*(unsigned char**)((unsigned char*)(p)+(o)))
// Original data: arm9/ov031 @ 0x224e5c4; symbol: data_ov031_0224e5c4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage[];extern "C" int Network_GetConnectionWorkspace(unsigned);
// Original: arm9/ov031 @ 0x022132D4; symbol: func_ov031_022132d4; size: 0x124.
extern "C" ARM void Network_ReleaseConnectionWorkspaces(){unsigned char*state=(unsigned char*)Network_GetConnectionWorkspace(1);if(!state)return;if(state[8]&16){void*selected=(void*)Network_GetConnectionWorkspace(16);state[8]&=~16;(*(void(**)(unsigned,void*,unsigned))(state+4))(16,selected,3352);}if(state[8]&8){void*selected=(void*)Network_GetConnectionWorkspace(8);state[8]&=~8;(*(void(**)(unsigned,void*,unsigned))(state+4))(8,selected,12);}if(state[8]&4){void*selected=(void*)Network_GetConnectionWorkspace(4);state[8]&=~4;(*(void(**)(unsigned,void*,unsigned))(state+4))(4,selected,88);}if(state[8]&2){void*selected=(void*)Network_GetConnectionWorkspace(2);state[8]&=~2;(*(void(**)(unsigned,void*,unsigned))(state+4))(2,selected,8960);} if(state[8]&1){state[8]&=~1;(*(void(**)(unsigned,void*,unsigned))(state+4))(1,state,36);NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage[3]=0;}}