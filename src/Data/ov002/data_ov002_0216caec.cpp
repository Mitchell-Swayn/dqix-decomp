// Menu state rebuild transitions; func_ov002_0215b9a4 scans
// source/destination pairs with eight-byte stride until negative source.
// Original symbols split the first source word from the table tail.
struct MenuStateTransition { int source, destination; };
struct MenuStateTransitionTail { int firstDestination; MenuStateTransition remaining[5]; };
extern "C" const MenuStateTransitionTail data_ov002_0216caec = { 8, {
    { 9, 13 },
    { 17, 18 },
    { 17, 19 },
    { 31, 32 },
    { -1, -1 },
} };
