#include <globaldefs.h>
ARM
struct GameState;
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
extern "C" void* OV017_ReadWordField6B0(void*);
extern "C" void* OV017_GetEmbeddedField1C(void*);
struct Input { unsigned unused, word; unsigned short id, half; unsigned char byte1,byte0,index; };
struct Entry { unsigned char byte0,byte1; unsigned short half; unsigned word; };
struct Target { char pad[0x4c]; Entry entries[1]; };
// Original: arm9/ov017 @ 0x021C6784; symbol: func_ov017_021c6784; size: 0x90.
extern "C" void GameState_ApplyMatchingNonProtagonistRecord(void *unused, Input *input, GameState *state, char *owner) {
    void *context = *(void**)(owner + 0x3718);
    char *record = (char*)OV017_GetEmbeddedField1C(context);
    if (!record) return;
    char *target = (char*)OV017_ReadWordField6B0(context);
    if (!target) return;
    if (*(signed char*)(record + 0x2a) == GameState_ReadProtagonistObjectIndex(state)) return;
    if (*(unsigned short*)(record + 8) != input->id) return;
    unsigned char index = input->index;
    Target *base = (Target*)(target + 0x81b0);
    unsigned char *entries = (unsigned char*)base->entries;
    unsigned short half = input->half;
    unsigned char *entry = entries + index * 8;
    *(unsigned short*)(entry + 2) = half;
    entry[1] = input->byte1;
    entries[index * 8] = input->byte0;
    *(unsigned*)(entry + 4) = input->word;
}
