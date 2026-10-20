#include <globaldefs.h>
// Original data: arm9/main @ 0x2110370; symbol: data_02110370.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char* NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020BD5E4; symbol: func_020bd5e4; size: 0x64.
extern "C" ARM char* ResourceManager_GetIndexedHeaderTable24Entry(int index) {
 char* state=NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage; char* base=*(char**)(state+0x8c);
 int offset=*(int*)(base+0x24);
 unsigned int* table; if(offset==0)table=0;else table=(unsigned int*)(base+offset);
 if (!table) return 0;
 if (index<0) return 0;
 if ((unsigned int)index>=*table) return 0;
 offset=*(unsigned int*)((char*)table+index*4+4); base=*(char**)(state+0x8c);
 if(offset==0) return 0; return base+offset;
}
