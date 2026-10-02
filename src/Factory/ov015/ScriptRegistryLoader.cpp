#include "ScriptRegistry.h"
#include "Resource/Script.h"
#include "Filesystem/FileIO.h"
#include "Filesystem/BackgroundLoader.h"

extern "C" {
extern ScriptRegistry* data_ov015_02194560;
extern Script::OpcodeLookupEntry data_ov015_02193fa0[];
char data_ov015_02193fc8[] = "data/bin/charaview4.bin";
void func_ov015_0218b828(ScriptRegistry*);

void func_ov015_0218ba44(ScriptRegistry* registry, const char* filename)
{
    unsigned int length;
    Script script;
    func_ov015_0218b828(registry);
    BackgroundLoader::AddLockGlobal();
    void* code;
    if (filename) code = LoadFileIntoMemory(filename, data_0211e33c, &length);
    else code = LoadFileIntoMemory(data_ov015_02193fc8, data_0211e33c, &length);
    if (code) {
        data_ov015_02194560 = registry;
        script.Initialize();
        script.SetOpcodeLookup(data_ov015_02193fa0);
        script.Load(code, length);
        script.Execute();
    }
    BackgroundLoader::RemoveLockGlobal();
}
}
