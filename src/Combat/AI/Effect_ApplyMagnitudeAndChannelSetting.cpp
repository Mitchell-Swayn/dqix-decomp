#include <globaldefs.h>
ARM
extern "C" int _fflt(int);
extern "C" void AppendTenByteRecordIfCapacity(void*, void*);
struct EffectParameters { unsigned words[3]; };
extern "C" void Effect_ApplyMagnitudeAndChannelSetting(unsigned char* object, int channel);
// Original: arm9/ov024 @ 0x021FD104; symbol: func_ov024_021fd104; size: 0x5C.
extern "C" void Effect_ApplyMagnitudeAndChannelSetting(unsigned char* object, int channel) {
    EffectParameters parameters = *(EffectParameters*)(object + 0x65c);
    int signedMagnitude = *(short*)(*(unsigned int*)(object + 0x64c) + 0x32);
    parameters.words[0] = (unsigned)_fflt(signedMagnitude);
    ((unsigned char*)&parameters)[4] = (unsigned char)channel;
    ((unsigned char*)&parameters)[7] = 0x64;
    ((unsigned char*)&parameters)[8] = 7;
    AppendTenByteRecordIfCapacity(*(void**)(object + 0x658), &parameters);
}
