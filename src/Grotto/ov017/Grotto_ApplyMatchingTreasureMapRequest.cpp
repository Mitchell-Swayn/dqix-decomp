#include <globaldefs.h>
ARM
extern "C" bool _Z28GetTreasureMapTypeFromItemIDtPh(unsigned short,unsigned char*);
extern "C" void EnableField55F4Bits(unsigned char* p,unsigned int bits);
extern "C" void SetByteAt5901AndFlag8000At55F4(unsigned char*,int);
extern "C" void func_ov000_0216341c(void*,unsigned,unsigned,unsigned);
extern "C" void* OV017_ReadWordField6AC(void*);
extern "C" void* OV017_GetEmbeddedField1C(void*);
struct Input { unsigned unused; unsigned short id,item; signed char value; };
struct MapType { unsigned char a,b; unsigned short c; };
// Original: arm9/ov017 @ 0x021CD510; symbol: func_ov017_021cd510; size: 0x80.
extern "C" void Grotto_ApplyMatchingTreasureMapRequest(void *unused, Input *input, void *unused2, char *owner) {
    void *context = *(void**)(owner + 0x3718);
    char *record = (char*)OV017_GetEmbeddedField1C(context);
    if (*(unsigned short*)(record + 8) != input->id) return;
    MapType type;
    if (!_Z28GetTreasureMapTypeFromItemIDtPh(input->item, (unsigned char*)&type)) return;
    unsigned char *target = (unsigned char*)OV017_ReadWordField6AC(context);
    if (!target) return;
    func_ov000_0216341c(target, type.a, type.b, type.c);
    if (input->value >= 0) SetByteAt5901AndFlag8000At55F4(target, input->value);
    EnableField55F4Bits(target, 0x8000);
}
