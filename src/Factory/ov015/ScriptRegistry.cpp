#include "ScriptRegistry.h"
#include "Memory/AllocatorUnion.h"

// These main-module helpers round allocation sizes to four bytes and forward
// to AllocatorUnion::Allocate / Free, as established by their disassembly.
extern "C" {
extern AllocatorUnion data_02114e20;
void* func_02012d88(AllocatorUnion*, unsigned int);
void func_02012da4(AllocatorUnion*, void*);

void func_ov015_0218b810(ScriptRegistry* registry)
{
    registry->records = 0;
    registry->recordCount = 0;
    registry->groups = 0;
    registry->groupCount = 0;
}

void func_ov015_0218b828(ScriptRegistry* registry)
{
    for (int i = 0; i < registry->recordCount; ++i) {
        if (registry->records[i].first) {
            func_02012da4(&data_02114e20, registry->records[i].first);
            registry->records[i].first = 0;
        }
        if (registry->records[i].second) {
            func_02012da4(&data_02114e20, registry->records[i].second);
            registry->records[i].second = 0;
        }
    }
    for (int i = 0; i < registry->groupCount; ++i) {
        if (registry->groups[i].name) {
            func_02012da4(&data_02114e20, registry->groups[i].name);
            registry->groups[i].name = 0;
        }
        RegistryNode* node = registry->groups[i].entries;
        while (node) {
            RegistryNode* next = node->next;
            if (node->name) {
                func_02012da4(&data_02114e20, node->name);
                node->name = 0;
            }
            func_02012da4(&data_02114e20, node);
            node = next;
        }
    }
    if (registry->records) {
        func_02012da4(&data_02114e20, registry->records);
        registry->records = 0;
    }
    if (registry->groups) {
        func_02012da4(&data_02114e20, registry->groups);
        registry->groups = 0;
    }
    func_ov015_0218b810(registry);
}

void func_ov015_0218b978(ScriptRegistry* registry, int capacity)
{
    func_ov015_0218b828(registry);
    registry->records = (RegistryRecord*)func_02012d88(&data_02114e20, capacity * sizeof(RegistryRecord));
    registry->recordCount = 0;
}

void func_ov015_0218b9ac(ScriptRegistry* registry, int capacity)
{
    registry->groups = (RegistryGroup*)func_02012d88(&data_02114e20, capacity * sizeof(RegistryGroup));
    registry->groupCount = 0;
}

void func_ov015_0218b9d4(ScriptRegistry* registry, const RegistryRecord* record)
{
    RegistryRecord* destination = &registry->records[registry->recordCount++];
    destination->first = record->first;
    destination->second = record->second;
    destination->value = record->value;
    destination->kind = record->kind;
    destination->flags = record->flags;
}

void func_ov015_0218ba1c(ScriptRegistry* registry, const RegistryGroup* group)
{
    RegistryGroup* destination = &registry->groups[registry->groupCount++];
    *destination = *group;
}
}
