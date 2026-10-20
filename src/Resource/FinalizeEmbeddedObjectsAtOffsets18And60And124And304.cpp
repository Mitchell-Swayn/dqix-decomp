#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" void ScriptRecordList_FinalizeEmpty(void*);extern "C" void Clear456ByteBufferAndInitializeTrailingWords(void*);extern "C" void Actor_ClearChoiceEntries(void*);extern "C" void ActorPathGraph_InitializeEmpty(void*);
// Original: arm9/main @ 0x02028CFC; symbol: func_02028cfc; size: 0x30.
extern "C" void* FinalizeEmbeddedObjectsAtOffsets18And60And124And304(unsigned char* p){ScriptRecordList_FinalizeEmpty(p+772);Clear456ByteBufferAndInitializeTrailingWords(p+292);Actor_ClearChoiceEntries(p+96);ActorPathGraph_InitializeEmpty(p+24);return p;}
