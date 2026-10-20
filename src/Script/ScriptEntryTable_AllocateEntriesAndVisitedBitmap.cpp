#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2109d94; symbol: data_02109d94.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char ScriptSumSelectedFourHalfwordParameters_UnknownRoleZeroInitializedStorage[];extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
// Original: arm9/main @ 0x020A14FC; symbol: func_020a14fc; size: 0x6C.
extern "C" void ScriptEntryTable_AllocateEntriesAndVisitedBitmap(unsigned char* p,void* required,int count){if(!required||!count)return;*(void**)p=_ZN13SafeAllocator8AllocateEj(*(void**)(ScriptSumSelectedFourHalfwordParameters_UnknownRoleZeroInitializedStorage+8),count*12);*(short*)(p+4)=count;*(short*)(p+6)=0;int bytes=(*(unsigned short*)(p+4)-1)/8+1;*(void**)(p+12)=_ZN13SafeAllocator8AllocateEj(*(void**)(ScriptSumSelectedFourHalfwordParameters_UnknownRoleZeroInitializedStorage+8),bytes);}
