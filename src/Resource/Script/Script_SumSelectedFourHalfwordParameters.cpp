#include <globaldefs.h>
#include "Resource/Script.h"
struct State
{
    unsigned char flags,pad;
    unsigned short overrideValue;
    unsigned first,second;
    int overrideEnabled;
};
// Original data: arm9/main @ 0x2109d94; symbol: data_02109d94.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" State ScriptSumSelectedFourHalfwordParameters_UnknownRoleZeroInitializedStorage;
extern "C" void ScriptEntryTable_AllocateEntriesAndVisitedBitmap(unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020A10CC; symbol: func_020a10cc; size: 0xB4.
extern "C" ARM int Script_SumSelectedFourHalfwordParameters(Script::Parameter* p)
{
    unsigned short result=0;
    unsigned short a=p[0].ToInt();
    unsigned short b=p[1].ToInt();
    unsigned short c=p[2].ToInt();
    unsigned short d=p[3].ToInt();
    unsigned flags=ScriptSumSelectedFourHalfwordParameters_UnknownRoleZeroInitializedStorage.flags;
    if(flags&1)result+=a;
    if(flags&2)result+=b;
    if(flags&4)result+=c;
    if(flags&8)result+=d;
    if(ScriptSumSelectedFourHalfwordParameters_UnknownRoleZeroInitializedStorage.overrideEnabled&&ScriptSumSelectedFourHalfwordParameters_UnknownRoleZeroInitializedStorage.overrideValue)result=ScriptSumSelectedFourHalfwordParameters_UnknownRoleZeroInitializedStorage.overrideValue;
    ScriptEntryTable_AllocateEntriesAndVisitedBitmap(ScriptSumSelectedFourHalfwordParameters_UnknownRoleZeroInitializedStorage.first,ScriptSumSelectedFourHalfwordParameters_UnknownRoleZeroInitializedStorage.second,result);
    return 1;
}
