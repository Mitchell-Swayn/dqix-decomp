#include <globaldefs.h>
ARM
struct State;
extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void *out);
extern "C" void func_ov011_021848a0(State* self, unsigned value);
extern "C" void* func_ov011_021849c8(State* self);
extern "C" void *func_ov023_021f6880(void **head, unsigned short value);
extern "C" unsigned OV023_ReadHalfwordField04(void*);
struct Buffer { unsigned words[4]; unsigned count : 9; unsigned flags : 23; unsigned tail[39]; };
// Original: arm9/ov004 @ 0x02156760; symbol: func_ov004_02156760; size: 0x98.
extern "C" int Graphics_UpdateTypeSevenEntryPageCount(State *self) {
    char *entry = (char*)func_ov023_021f6880((void**)func_ov011_021849c8(self), 3);
    if (!entry) return 0;
    if (OV023_ReadHalfwordField04(entry) != 7) return 0;
    Buffer buffer;
    GameState_CopyB0ByteStateBufferToOutput(&buffer);
    unsigned pages;
    unsigned count = buffer.count;
    pages = count / 12;
    if (count % 12) pages++;
    if (pages) {
        *(short*)(entry + 0x5c) = 0;
        *(short*)(entry + 0x5e) = pages;
        return 0;
    } else {
        func_ov011_021848a0(self, 0x66);
    }
    return 0;
}
