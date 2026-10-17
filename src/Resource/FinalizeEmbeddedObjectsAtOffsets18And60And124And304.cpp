#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" void ClearOutputWordAndByte_Main0206EE70(void*);extern "C" void Clear456ByteBufferAndInitializeTrailingWords(void*);extern "C" void ClearMemoryRange192(void*);extern "C" void InitializeRecordWithField20Enabled(void*);
// Original: arm9/main @ 0x02028CFC; symbol: func_02028cfc; size: 0x30.
extern "C" void* FinalizeEmbeddedObjectsAtOffsets18And60And124And304(unsigned char* p){ClearOutputWordAndByte_Main0206EE70(p+772);Clear456ByteBufferAndInitializeTrailingWords(p+292);ClearMemoryRange192(p+96);InitializeRecordWithField20Enabled(p+24);return p;}
