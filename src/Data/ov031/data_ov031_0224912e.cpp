// Two modes of four navigation keys with four signed directional destinations; func_ov031_022338b4 indexes mode*16 + key*4 + direction; negative values signal fallback.
struct MenuNavigation { signed char destinations[2][4][4]; unsigned short alignmentPadding; };
extern "C" const MenuNavigation data_ov031_0224912e = { {
    {
        { -1, -2, -1, -2 },
        { 3, 0, 3, 0 },
        { -1, -1, -1, -1 },
        { 1, 0, 1, 0 },
    },
    {
        { -1, -2, -1, -2 },
        { 3, 0, 2, 0 },
        { 1, 0, 3, 0 },
        { 2, 0, 1, 0 },
    },
}, 0 };
