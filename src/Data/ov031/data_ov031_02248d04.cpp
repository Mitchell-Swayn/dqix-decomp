// Keyboard cursor origin table, preserved as split symbols. func_ov031_022269d8
// reads x from 0x2248d02 + key*4 and y from 0x2248d04 + key*4.
struct CursorOrigin { unsigned short x, y; };
struct CursorOriginTail { unsigned short firstY; CursorOrigin remaining[13]; };
extern "C" const CursorOriginTail data_ov031_02248d04 = { 74, {
    { 112, 74 },
    { 144, 74 },
    { 80, 97 },
    { 112, 97 },
    { 144, 97 },
    { 80, 120 },
    { 112, 120 },
    { 144, 120 },
    { 80, 143 },
    { 112, 143 },
    { 144, 143 },
    { 2, 168 },
    { 130, 168 },
} };
