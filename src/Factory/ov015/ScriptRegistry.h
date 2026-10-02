#ifndef FACTORY_OV015_SCRIPT_REGISTRY_H
#define FACTORY_OV015_SCRIPT_REGISTRY_H

// Layouts established by the overlay's script producers and indexed users.
// Names of the two record strings and selector bytes remain provisional.
struct RegistryRecord {
    char* first;
    char* second;
    unsigned short value;
    unsigned char kind;
    unsigned char flags;
};

struct RegistryNode {
    char* name;
    unsigned short value;
    unsigned char kind;
    RegistryNode* next;
};

struct RegistryGroup {
    char* name;
    RegistryNode* entries;
};

struct ScriptRegistry {
    RegistryRecord* records;
    RegistryGroup* groups;
    int recordCount;
    int groupCount;
};

#endif
