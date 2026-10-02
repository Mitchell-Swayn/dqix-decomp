#include "AllocatorNodes.h"
#include <std_library_functions.h>

// Unknown payloads stay opaque; only fields accessed by these initializers
// are described. The record is embedded at manager offset 0x20.
struct Ov011ManagerRecord
{
    unsigned short count, index;
    unsigned char payload[0x70];
    void* next;
    void* previous;
};

struct Ov011AllocatorManager
{
    Ov011AllocatorNode root;
    Ov011ManagerRecord record;
    void* allocation;
    unsigned int allocationSize;
    int allocationId;
    unsigned int field_a8, field_ac, field_b0, field_b4;
    unsigned char storage[0x54];
    unsigned int field_10c;
    int field_110;
    unsigned int field_114;
    unsigned char subsystem[0x74];
    int field_18c;
    int powerFlag;
    unsigned char state[0x10];
    unsigned char flag_1a4, flag_1a5;
    unsigned char padding_1a6[2];
    unsigned int displayMode, subDisplayMode;
    unsigned short field_1b0, field_1b2;
    unsigned int field_1b4, field_1b8;
    unsigned short field_1bc, field_1be, field_1c0, field_1c2, field_1c4, field_1c6;
    unsigned int field_1c8;
    unsigned char flag_1cc, flag_1cd;
    unsigned char padding_1ce[2];
    unsigned int field_1d0, field_1d4, field_1d8, field_1dc;
};

typedef char Ov011RecordSizeCheck[sizeof(Ov011ManagerRecord) == 0x7c ? 1 : -1];
typedef char Ov011ManagerSizeCheck[sizeof(Ov011AllocatorManager) == 0x1e0 ? 1 : -1];

extern "C" {
    void func_ov023_021f672c(void*);
    void* func_ov017_0218b5b0();
    void func_0203b4d8(void*, int);
    void func_02074af4(void*);
    void func_02074b64(void*);

    void func_ov011_02184374(Ov011ManagerRecord* record)
    {
        record->count = 0;
        record->index = 0;
        record->next = 0;
        record->previous = 0;
    }

    void func_ov011_0218438c(Ov011AllocatorManager* manager)
    {
        func_ov011_021842a0(&manager->root);
        manager->field_a8 = 0;
        manager->field_ac = 0;
        manager->allocation = 0;
        manager->allocationSize = 0;
        manager->allocationId = -1;
        manager->field_b0 = 0;
        manager->field_b4 = 0;
        memset(manager->storage, 0, sizeof(manager->storage));
        manager->field_110 = -1;
        manager->field_10c = 0;
        manager->field_114 = 0;
        func_ov023_021f672c(manager->subsystem);
        manager->field_18c = -1;
        func_0203b4d8(func_ov017_0218b5b0(), 0xc0);
        manager->powerFlag = (*(volatile unsigned short*)0x04000304 & 0x8000) >> 15;
        manager->flag_1a4 = 0;
        manager->flag_1a5 = 0;
        func_02074af4(manager->state);
        func_02074b64(manager->state);
        manager->displayMode = (*(volatile unsigned int*)0x04000000 & 0x1f00) >> 8;
        manager->subDisplayMode = (*(volatile unsigned int*)0x04001000 & 0x1f00) >> 8;
        manager->field_1b0 = 0;
        manager->field_1b2 = 0;
        manager->field_1b4 = 0;
        manager->field_1b8 = 0;
        manager->field_1bc = 0;
        manager->field_1be = 0;
        manager->field_1c0 = 0;
        manager->field_1c2 = 0;
        manager->field_1c4 = 0;
        manager->field_1c6 = 0;
        manager->field_1c8 = 0;
        manager->field_1d0 = 0;
        manager->field_1d4 = 0;
        manager->field_1d8 = 0;
        manager->field_1dc = 0;
        manager->flag_1cc = 0;
        manager->flag_1cd = 0;
    }
}
