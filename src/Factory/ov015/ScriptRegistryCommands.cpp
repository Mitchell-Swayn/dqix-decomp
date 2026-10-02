#include "ScriptRegistry.h"
#include "Resource/Script.h"
#include "Memory/AllocatorUnion.h"

extern "C" {
extern AllocatorUnion data_02114e20;
ScriptRegistry* data_ov015_02194560;
void* func_02012d88(AllocatorUnion*, unsigned int);
int func_020d2ff0(const char*);
void func_ov015_0218b978(ScriptRegistry*, int);
void func_ov015_0218b9ac(ScriptRegistry*, int);
void func_ov015_0218b9d4(ScriptRegistry*, const RegistryRecord*);
void func_ov015_0218ba1c(ScriptRegistry*, const RegistryGroup*);

int func_ov015_0218b5a0(Script::Parameter* parameters, int)
{
    ScriptRegistry* registry = data_ov015_02194560;
    func_ov015_0218b978(registry, parameters[0].ToInt());
    return 1;
}

int func_ov015_0218b5c8(Script::Parameter* parameters, int)
{
    const char* first = parameters[0].ToString();
    const char* second = parameters[1].ToString();
    int value = parameters[2].ToInt();
    int kind = parameters[3].ToInt();
    int flags = parameters[4].ToInt();
    RegistryRecord record;
    record.first = 0;
    record.second = 0;
    record.value = 0;
    record.kind = 0;
    record.flags = 0;
    if (first) {
        record.first = (char*)func_02012d88(&data_02114e20, func_020d2ff0(first) + 1);
        if (record.first) strcpy(record.first, first);
    }
    if (second) {
        record.second = (char*)func_02012d88(&data_02114e20, func_020d2ff0(second) + 1);
        if (record.second) strcpy(record.second, second);
    }
    record.value = value;
    record.kind = kind;
    record.flags = flags;
    func_ov015_0218b9d4(data_ov015_02194560, &record);
    return 1;
}

int func_ov015_0218b6bc(Script::Parameter* parameters, int)
{
    ScriptRegistry* registry = data_ov015_02194560;
    func_ov015_0218b9ac(registry, parameters[0].ToInt());
    return 1;
}

int func_ov015_0218b6e4(Script::Parameter* parameters, int count)
{
    const char* name = (parameters++)->ToString();
    RegistryGroup group;
    group.name = 0;
    group.entries = 0;
    if (name) {
        group.name = (char*)func_02012d88(&data_02114e20, func_020d2ff0(name) + 1);
        if (group.name) strcpy(group.name, name);
    }
    for (int i = 1; i < count; i += 3) {
        const char* entryName = (parameters++)->ToString();
        int value = (parameters++)->ToInt();
        int kind = (parameters++)->ToInt();
        RegistryNode* node = (RegistryNode*)func_02012d88(&data_02114e20, sizeof(RegistryNode));
        node->name = 0;
        node->value = 0;
        node->kind = 0;
        node->next = 0;
        if (entryName) {
            node->name = (char*)func_02012d88(&data_02114e20, func_020d2ff0(entryName) + 1);
            if (node->name) strcpy(node->name, entryName);
        }
        node->value = value;
        node->kind = kind;
        RegistryNode** tail = &group.entries;
        while (*tail) tail = &(*tail)->next;
        *tail = node;
    }
    func_ov015_0218ba1c(data_ov015_02194560, &group);
    return 1;
}

// Sorted opcode table, terminated by the Script interpreter's zero entry.
Script::OpcodeLookupEntry data_ov015_02193fa0[] = {
    {100, func_ov015_0218b5a0},
    {101, func_ov015_0218b5c8},
    {102, func_ov015_0218b6bc},
    {103, func_ov015_0218b6e4},
    {0, 0}
};
}
