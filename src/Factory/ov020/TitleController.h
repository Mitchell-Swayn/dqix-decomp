#pragma once

#include "Memory/SafeAllocator.h"

// Partial selection-grid layout established by func_0205ba2c/ba68/bb04.
struct TitleSelectionGrid {
    int count;
    int unknown_04;
    int columns;
    int rows;
    unsigned char orientation;
    unsigned char padding_11[3];
    int page;
    int column;
    int row;
    int* majorCount;
    int* minorCount;
    int* majorPosition;
    int* minorPosition;
    unsigned char unknown_30[0x20];
};

struct TitleMenuInput {
    unsigned char unknown_00[0x13];
    unsigned char repeatCounterA;
    unsigned char repeatDelayB;
    unsigned char repeatCounterB;
    unsigned char enabled;
    unsigned char padding_17;
};

// func_0205c790 initializes this 0x238-byte menu subobject.
struct TitleMenu {
    int unknown_000;
    TitleMenuInput input;
    int unknown_01c;
    TitleSelectionGrid primaryGrid;
    TitleSelectionGrid secondaryGrid;
    unsigned char unknown_0c0[0x233 - 0xc0];
    unsigned char updateEnabled;
    unsigned char inputEnabled;
    unsigned char padding_235[3];
};

struct TitleBrightnessTransition {
    float current;
    int target;
    int timeRemaining;
};

// Shared background resource descriptor. The two nibbles select the display
// engine and BG layer; resource/allocator fields before them remain partial.
struct TitleBackgroundDescriptor {
    unsigned char unknown_00[0x1c];
    unsigned char engine : 4;
    unsigned char layer : 4;
    unsigned char unknown_1d[3];
};

// Earlier UI/resource fields remain partial; no ownership of their storage.
struct TitleTransitionController {
    int state;
    int frameCounter;
    int unknown_008;
    TitleMenu menu;
    unsigned char unknown_244[0x470 - 0x244];
    SafeAllocator primaryAllocator;
    SafeAllocator secondaryAllocator;
    unsigned char unknown_498[4];
    TitleBackgroundDescriptor mainBackground;
    TitleBackgroundDescriptor subBackground;
    unsigned char unknown_4dc[8];
    int waitTimeRemaining;
    TitleBrightnessTransition mainBrightness;
    TitleBrightnessTransition subBrightness;
};
