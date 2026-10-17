#include <globaldefs.h>
extern "C" void *GameState_GetObjectWithFlag100(void *, int);
extern "C" unsigned char *ReadWordFieldAtOffset150(void *);
// Original: arm9/ov017 @ 0x021CCBDC; symbol: func_ov017_021ccbdc; size: 0x58.
extern "C" void Ov017_CopyThreeValuesToGameObject(void *unused, char *record, void *state) {
    char *fields = record + 4;
    void *object = GameState_GetObjectWithFlag100(state, *(unsigned short *)(fields + 0x0c));
    if (object == 0) return;
    unsigned char *destination = ReadWordFieldAtOffset150(object);
    if (destination == 0) return;
    unsigned char start = *(unsigned char *)(fields + 0x0e);
    unsigned char i = 0;
    while (i < 3) {
        *(unsigned int *)(destination + 0x138 + (i + start) * 4) = *(unsigned int *)(fields + i * 4);
        i++;
    }
}
