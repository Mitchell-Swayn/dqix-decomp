#include <globaldefs.h>
#include "Resource/Script.h"
#pragma thumb off
struct ObjectScriptContext {
    unsigned reserved[4];
    unsigned char* object;
};
extern "C" {
void* ReadGlobalValueAt020FB3F0();
void Object_AppendTwelveByteRecord(unsigned char*,unsigned short,unsigned char,unsigned int,unsigned int);
extern ObjectScriptContext data_020fdc4c;
}
// Original: arm9/main @ 0x0201F3B4; symbol: func_0201f3b4; size: 0x118.
// Script arguments supply a hundred-scaled key, record tag, and two rounded
// 20.12 values. A zero tag skips insertion; the command always returns success.
extern "C" int Script_AppendTwelveByteObjectRecord(Script::Parameter* params, int /* numParams */)
{
    float first;
    int key = params[0].ToInt();
    int tag = params[1].ToInt();
    first = params[2].ToFloat();
    float second = params[3].ToFloat();
    ReadGlobalValueAt020FB3F0();
    if (!tag) return 1;
    float roundedSecond = second > 0.0f ? 0.5f + 4096.0f * second : 4096.0f * second - 0.5f;
    float roundedFirst = first > 0.0f ? 0.5f + 4096.0f * first : 4096.0f * first - 0.5f;
    int recordKey = key / 100;
    Object_AppendTwelveByteRecord(data_020fdc4c.object,(unsigned short)recordKey,
        (unsigned char)tag,(int)roundedFirst,(int)roundedSecond);
    return 1;
}
