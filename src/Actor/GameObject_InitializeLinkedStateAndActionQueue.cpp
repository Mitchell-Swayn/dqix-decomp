#include <globaldefs.h>
#include "std_library_functions.h"

struct Entity {
    unsigned short flags;
    unsigned char unknown_2[0x14e];
    int field_150;
    int field_154;
    int field_158;
    int field_15c;
    unsigned char unknown_160[0x18];
    unsigned char field_178[4];
    unsigned char field_17c;
    unsigned char field_17d;
    unsigned char field_17e;
    unsigned char field_17f;
    int field_180;
    unsigned char field_184;
    unsigned char field_185;
    unsigned char field_186;
    unsigned char unknown_187;
    int field_188;
    int field_18c;
    int field_190;
    int field_194;
    unsigned char sub_198[4];
    int field_19c;
    unsigned char unknown_1a0[0x10];
    short field_1b0_pad;
    short field_1b2;
    int field_1b4;
    int field_1b8;
    int field_1bc;
    short field_1c0;
    short field_1c2;
    int field_1c4;
};

extern "C" {
void GameObject_InitializeCombatStateLinks(Entity*);
void ResourceHandle_InitializeSequenceHandle(void*);
}

// Original: arm9/main @ 0x02052A4C; symbol: func_02052a4c; size: 0x9C.
extern "C" ARM void GameObject_InitializeLinkedStateAndActionQueue(Entity* e) {
    GameObject_InitializeCombatStateLinks(e);
    e->flags |= 0x100;
    ResourceHandle_InitializeSequenceHandle(e->sub_198);
    e->field_150 = 0;
    e->field_154 = 0;
    e->field_158 = 0;
    memset(e->field_178, 0, 4);
    e->field_17c = 0;
    e->field_17d = 0;
    e->field_180 = -1;
    e->field_17e = 0;
    e->field_17f = 0;
    e->field_184 = 0;
    e->field_190 = 0;
    e->field_194 = -1;
    e->field_185 = 0;
    e->field_186 = 0;
    e->field_188 = 0;
    e->field_1b4 = 0;
    e->field_1b8 = 0;
    e->field_1bc = 0;
    e->field_18c = 0;
    e->field_19c = 0;
    e->field_1b2 = 0;
    e->field_1c0 = 0;
    e->field_15c = -1;
    e->field_1c4 = 0;
}
