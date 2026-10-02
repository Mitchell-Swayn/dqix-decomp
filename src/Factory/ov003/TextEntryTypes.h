#ifndef FACTORY_OV003_TEXT_ENTRY_TYPES_H
#define FACTORY_OV003_TEXT_ENTRY_TYPES_H

// Layout inferred from the script builders and navigation/action callers.
struct TextEntryKey {
    short x;
    short y;
    const char* text;
    const char* alternateText;
    unsigned char modeMask;
    unsigned char action;
    unsigned char extentIndex;
    unsigned char disabled;
    short navigationIndex;
    unsigned char unknown12;
    unsigned char unknown13;
};

struct TextEntryGrid {
    unsigned char modeMask;
    signed char columns;
    signed char rows;
    signed char cellCount;
    short* keyIndices;
};

struct TextEntryLayout {
    TextEntryKey* keys;
    short keyCapacity;
    short keyCount;
    TextEntryGrid* grids;
    short gridCapacity;
    short gridCount;
};

struct TextEntryState {
    TextEntryKey* selectedKey;
    TextEntryLayout* layout;
    char* text;
    int widthLimit;
    unsigned int bufferSize;
    int characterLimit;
    int lastInput;
    short repeatTimer;
    unsigned char mode;
    unsigned char encoding;
    unsigned char alternate;
    unsigned char unknown21;
    unsigned char allowAlternateConfirm;
    unsigned char allowBackspace;
    unsigned char allowTouch;
    unsigned char padding[3];
};

#endif
