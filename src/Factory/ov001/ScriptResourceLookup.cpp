#include "Resource/Script.h"
#include "Memory/SafeAllocator.h"

// Opcode 100 associates an integer key with a resource path. The loader runs
// the script twice, first counting entries and then copying the strings.
struct ScriptResourceEntry {
    int key;
    char* path;
};

struct ScriptResourceLookup {
    ScriptResourceEntry* entries;
    int count;
};

struct ScriptResourceParseState {
    int index;
    SafeAllocator* allocator;
    ScriptResourceLookup* lookup;
};

extern "C" {
ScriptResourceParseState data_ov001_02165800;

int func_ov001_021536e0(Script::Parameter*, int) {
    ++data_ov001_02165800.index;
    return 1;
}

int func_ov001_021536fc(Script::Parameter* parameters, int) {
    data_ov001_02165800.lookup->entries[data_ov001_02165800.index].key = parameters[0].ToInt();
    const char* path = parameters[1].ToString();
    if (!path)
        return 0;
    char* copy = (char*)data_ov001_02165800.allocator->Allocate(strlen(path) + 1);
    data_ov001_02165800.lookup->entries[data_ov001_02165800.index].path = copy;
    if (!data_ov001_02165800.lookup->entries[data_ov001_02165800.index].path)
        return 0;
    strcpy(data_ov001_02165800.lookup->entries[data_ov001_02165800.index].path, path);
    ++data_ov001_02165800.index;
    return 1;
}

Script::OpcodeLookupEntry data_ov001_02164b80[2] = {
    {100, func_ov001_021536e0}, {0, 0}
};
Script::OpcodeLookupEntry data_ov001_02164b90[2] = {
    {100, func_ov001_021536fc}, {0, 0}
};

void func_ov001_021537a0(ScriptResourceLookup* lookup) {
    lookup->entries = 0;
    lookup->count = 0;
}

void func_ov001_021537b0(ScriptResourceLookup* lookup, SafeAllocator* allocator,
                       const void* code, unsigned int length) {
    lookup->entries = 0;
    lookup->count = 0;
    data_ov001_02165800.index = 0;
    data_ov001_02165800.allocator = allocator;
    data_ov001_02165800.lookup = lookup;
    Script script;
    script.Initialize();
    script.SetOpcodeLookup(data_ov001_02164b80);
    script.Load(code, length);
    script.Execute();
    lookup->count = data_ov001_02165800.index;
    data_ov001_02165800.index = 0;
    lookup->entries = (ScriptResourceEntry*)allocator->Allocate(lookup->count * sizeof(ScriptResourceEntry));
    if (!lookup->entries) {
        lookup->count = 0;
        return;
    }
    script.Initialize();
    script.SetOpcodeLookup(data_ov001_02164b90);
    script.Load(code, length);
    script.Execute();
}

ScriptResourceEntry* func_ov001_02153884(ScriptResourceLookup* lookup, int key) {
    for (int i = 0; i < lookup->count; ++i) {
        if (lookup->entries[i].key == key) {
            ScriptResourceEntry* entry = &lookup->entries[i];
            return entry->path ? entry : 0;
        }
    }
    return 0;
}
}
