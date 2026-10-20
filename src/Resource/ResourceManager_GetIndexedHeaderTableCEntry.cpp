#include <globaldefs.h>
// Original data: arm9/main @ 0x2110370; symbol: data_02110370.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned* NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020BD4B8; symbol: func_020bd4b8; size: 0x64.
extern "C" unsigned ResourceManager_GetIndexedHeaderTableCEntry(int index) { unsigned* root=NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage; unsigned base=root[35]; unsigned off=*(unsigned*)(base+12); unsigned* table=(off==0) ? 0 : (unsigned*)(base+off); if(!table)return 0; if(index<0)return 0; if((unsigned)index>=*table)return 0; unsigned item=(table+index)[1]; unsigned data=root[35]; return item==0 ? 0 : data+item; }
