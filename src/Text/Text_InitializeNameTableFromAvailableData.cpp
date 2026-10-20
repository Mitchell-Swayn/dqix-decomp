#include <globaldefs.h>
extern "C" void Text_RelocateNameTableEntryStrings();extern "C" void Text_InitializeSerializedNameTable(unsigned,unsigned,unsigned*,void(*)());
// Original: arm9/main @ 0x020E56FC; symbol: func_020e56fc; size: 0x2C.
extern "C" ARM int Text_InitializeNameTableFromAvailableData(unsigned a,unsigned b,unsigned c,unsigned d){unsigned context;if(b&&c){Text_InitializeSerializedNameTable(a,b,&context,Text_RelocateNameTableEntryStrings);return 1;}return 0;}
