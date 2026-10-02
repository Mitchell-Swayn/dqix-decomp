#pragma once

// Partial embedded types. Names retain offsets until their gameplay purposes
// are established. Only fields touched by recovered routines are identified.
extern "C" void func_020982b4(void*);

struct ZoneState0840
{
    char unknown[0x1b78];
    ZoneState0840() { func_020982b4(this); }
    ~ZoneState0840() { Finish(); }
    void Finish();
};
struct ZoneState2664
{
    int unknown_0;
    int unknown_4;
    char unknown_8[0xb4 - 8];
    unsigned char unknown_b4;
    unsigned char unknown_b5;
    unsigned char unknown_b6;
    signed char unknown_b7;
    signed char unknown_b8;
    char unknown_b9;
    unsigned short unknown_ba;
    signed char unknown_bc;
    char unknown_bd[3];
    ZoneState2664() { Reset(); }
    ~ZoneState2664() { Reset(); }
    void Reset();
};
struct ZoneState2724
{
    int unknown_0;
    int unknown_4;
    int unknown_8;
    ZoneState2724() { Reset(); }
    ~ZoneState2724() { Reset(); }
    void Reset();
};
struct ZoneState2754
{
    char unknown_0[0x14];
    unsigned char unknown_14;
    char padding[3];
    ZoneState2754();
    void Reset();
};
