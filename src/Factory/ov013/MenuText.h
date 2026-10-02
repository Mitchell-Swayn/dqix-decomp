#pragma once

#include <Memory/SafeAllocator.h>

// Layout names describe observed menu/widget operations; screen identity is unknown.
struct Ov013Widget {
    unsigned char unknown00[0xc];
    short hitX[18];
    short hitY[18];
    short hitWidth[18];
    short hitHeight[18];
    unsigned char unknown9C[0x10];
    short tileX;
    short tileY;
    unsigned char unknownB0[0xc];
    short offsetX;
    short offsetY;
    unsigned char unknownC0[4];
    unsigned char id;
    unsigned char flags;
    unsigned char unknownC6[0x1a];
};

struct Ov013WidgetGroup {
    unsigned char unknown00[0x98];
    void* resources;
    Ov013Widget* widgets;
    short dimensions[8];
    unsigned char state[12];
};

struct Ov013TextBuffer {
    char text[0x960];
};

struct Ov013StringCatalog {
    unsigned char unknown00[0xc];
    short resourceId;
    unsigned short state;
    int task;
    void* loadedData;
};

struct Ov013TranslationEntry {
    unsigned char unknown00[4];
    short x;
    short y;
    unsigned short id;
    unsigned char unknown0A[0xb];
    unsigned char flags;
    unsigned char unknown16[2];
};

struct Ov013TranslationGroup {
    Ov013TranslationEntry* entries;
    unsigned short count;
};

struct Ov013DisplayEntry {
    unsigned char unknown00[0x14];
    int fixedX;
    int fixedY;
    unsigned char unknown1C[6];
    unsigned char blend;
    unsigned char unknown23[3];
    unsigned char visible;
    unsigned char unknown27;
};

struct Ov013Display {
    unsigned char unknown00[0x3c];
    Ov013TranslationGroup* translations;
    Ov013DisplayEntry* entries;
    unsigned char unknown44[0xa];
    unsigned short entryCount;
};

// Partial menu layout through the cursor enable flags; unknown fields stay explicit.
struct Ov013Menu {
    SafeAllocator allocator;
    unsigned int translationStep; // 0x14, added to translation counters by 0205a330
    Ov013Display* display;
    unsigned short displayId;
    short displayOffset;
    unsigned char graphicsState[0x10];
    unsigned char unknown30[4];
    unsigned int savedBackgroundMode;
    Ov013WidgetGroup widgetGroup; // 0x38, 0xbc bytes
    unsigned char resourceSlots[2][0x20]; // initialized by func_0204af64
    Ov013Widget widgets[3]; // initialized by func_0204c684
    unsigned char unknown3D4[0x238];
    SafeAllocator stringAllocator; // 0x60c
    Ov013StringCatalog strings; // 0x620, func_020dfc40 / func_020e0434
    unsigned char state[0x10]; // 0x638
    int mode; // 0x648
    int unknown64C;
    int task;
    int unknown654;
    Ov013TextBuffer* textBuffer; // 0x658, borrowed from func_020421a0()->0x5c
    int primarySelection;
    int optionSelection;
    unsigned char unknown664[0x58];
    unsigned char cursorFlags; // 0x6bc
};

typedef char Ov013WidgetSize[sizeof(Ov013Widget) == 0xe0 ? 1 : -1];
typedef char Ov013GroupSize[sizeof(Ov013WidgetGroup) == 0xbc ? 1 : -1];
typedef char Ov013CatalogSize[sizeof(Ov013StringCatalog) == 0x18 ? 1 : -1];
typedef char Ov013TranslationSize[sizeof(Ov013TranslationEntry) == 0x18 ? 1 : -1];
typedef char Ov013DisplayEntrySize[sizeof(Ov013DisplayEntry) == 0x28 ? 1 : -1];
typedef char Ov013DisplayPrefixSize[sizeof(Ov013Display) == 0x50 ? 1 : -1];
typedef char Ov013MenuPrefixSize[sizeof(Ov013Menu) == 0x6c0 ? 1 : -1];

extern "C" {
int func_0205d5d0(Ov013WidgetGroup*, unsigned int, const Ov013TextBuffer*, int, unsigned char);
Ov013Widget* func_0205d81c(Ov013WidgetGroup*, unsigned int);
void func_ov013_02185424(Ov013Menu*, Ov013TextBuffer*);
void func_ov013_02185be0(Ov013Menu*, Ov013TextBuffer*);
void func_ov013_02186bd4(Ov013Menu*);
void func_ov013_02186c1c(Ov013Menu*);
void func_ov013_02186c64(Ov013Menu*, unsigned int, int);
}
