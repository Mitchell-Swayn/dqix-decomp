#include <globaldefs.h>
#include <Resource/Script.h>
extern "C" void* data_02109ba8;extern "C" void AppendHalfwordPairWithinSixtySixEntryLimit(void*,short*);
// Original: arm9/main @ 0x0209A77C; symbol: func_0209a77c; size: 0x40.
extern "C" ARM int Script_AppendHalfwordPairToGlobalOwner(Script::Parameter* p){short values[2];values[0]=p[0].ToInt();values[1]=p[1].ToInt();AppendHalfwordPairWithinSixtySixEntryLimit(data_02109ba8,values);return 1;}
