#pragma once

// Eight RGB555 colors copied to the 3D edge-color registers at 04000330.
struct Overlay21EdgeColors
{
    unsigned short colors[8];
};

extern "C" const Overlay21EdgeColors data_ov021_0218bbc4;

typedef char Overlay21EdgeColorsSizeCheck[sizeof(Overlay21EdgeColors) == 16 ? 1 : -1];
