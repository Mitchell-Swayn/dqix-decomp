#include <globaldefs.h>
ARM
extern "C" void* ReadOverlayControlSecondWord();
extern "C" void* GetEmbeddedRegionAtOffset3760(void*);
extern "C" char* Grotto_FindEntryBySlotIndex(void*,int);
extern "C" char* GameState_GetIndexedWordIfValid(void*,int);
struct Descriptor { unsigned short id; signed char type; unsigned char pad; float value; unsigned short unknown; unsigned char first,second; };
// Original: arm9/ov024 @ 0x021F691C; symbol: func_ov024_021f691c; size: 0x98.
extern "C" int Grotto_ApplyPositiveSlotDescriptor(Descriptor *descriptor, unsigned short *idOut, unsigned char *out, int slot) {
    if (descriptor->value > 0.0f) {
        unsigned short id = descriptor->id;
        if (descriptor->type >= 0) {
            char *target = Grotto_FindEntryBySlotIndex(GetEmbeddedRegionAtOffset3760(ReadOverlayControlSecondWord()), slot);
            if (target) {
                target[0x22] = descriptor->type;
                char *record = GameState_GetIndexedWordIfValid(target, descriptor->type);
                if (record) *(short*)(target + 0x2c) = *(short*)(record + 0x18);
            }
        }
        *(unsigned short*)out = id;
        *idOut = id;
        if (descriptor->first != 255) out[3] = descriptor->first;
        if (descriptor->second != 255) out[2] = descriptor->second;
        return 1;
    }
    return 0;
}
