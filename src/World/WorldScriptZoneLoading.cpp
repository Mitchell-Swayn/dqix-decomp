#include "World/WorldScriptZoneRecord.h"
#include "World/Zone3D.h"
#include "Resource/Script.h"

extern "C" {
    Zone3D* func_02012fe4();
    extern Script::OpcodeLookupEntry data_020f1248[2];
}

extern "C" int func_0208dc00(const void* data, unsigned int length,
                             WorldScriptZoneRecord* record)
{
    data_02108fc8.record = record;
    data_02108fc8.matched = 0;
    data_02108fc8.info = func_02012fe4()->pUnknownStruct_8_;
    Script script;
    script.Initialize();
    script.SetOpcodeLookup(data_020f1248);
    script.Load(data, length);
    script.Execute();
    return data_02108fc8.matched;
}
