#include "std_library_functions.h"

struct TreasureMapRecord
{
    uint16_t unknown_00;
    uint16_t unknown_02;
    unsigned char unknown_04;
    unsigned char unknown_05;
    uint16_t unknown_06;
    uint16_t unknown_08;
    uint16_t unknown_0a;
    int unknown_0c;
    unsigned char unknown_10[0x14];
    unsigned char unknown_24;
    unsigned char unknown_25;
    unsigned char unknown_26[4];
    signed char unknown_2a;
    unsigned char unknown_2b;
    int unknown_2c;
    int unknown_30;
    unsigned char unknown_34;
    unsigned char unknown_35;
};

extern "C" void func_020a3578(TreasureMapRecord* record)
{
    record->unknown_00 = 0;
    record->unknown_06 = 0;
    record->unknown_08 = 0;
    record->unknown_0a = 0;
    record->unknown_2a = -1;
    record->unknown_2c = 0;
    record->unknown_30 = 0;
    record->unknown_34 = 0;
    record->unknown_0c = -1;
    record->unknown_04 = 0;
    record->unknown_02 = 0x75a4;
    record->unknown_24 = 0;
    record->unknown_25 = 0;
    record->unknown_35 = 0;
    record->unknown_05 = 2;
}
