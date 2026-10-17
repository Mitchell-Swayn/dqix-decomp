#include <globaldefs.h>
ARM
struct LinkedDescriptorView;
extern "C" int Object_TestDescriptorExclusionFlagsClear(LinkedDescriptorView* p);
extern "C" int TestField14Flags1And8And1000000Clear(char* p);
extern "C" bool Object_TestElement5Mask10(unsigned int* p);
extern "C" void CacheSelectedByteEntry(void*,int);
extern "C" void SubmitPercentScaledDisplayRecord(void*,float,int);
struct PercentageRecord { char pad[20]; unsigned low : 7; unsigned percentage : 7; unsigned high : 18; };
// Original: arm9/ov024 @ 0x021FD45C; symbol: func_ov024_021fd45c; size: 0xA8.
extern "C" void UpdateClampedDescriptorPercentage(char *self) {
    char *object = *(char **)(self + 0x668);
    if (!Object_TestDescriptorExclusionFlagsClear((LinkedDescriptorView *)object)) return;
    if (!TestField14Flags1And8And1000000Clear(*(char **)(object + 0x138))) return;
    if (Object_TestElement5Mask10(*(unsigned **)(object + 0x138))) return;
    PercentageRecord *record = *(PercentageRecord **)(self + 0x64c);
    float percentage = (float)record->percentage;
    float scale = (float)*(unsigned char *)(*(char **)(object + 0x138) + 0x47) / 100.0f;
    float value = percentage * scale;
    if (value > 100.0f) value = 100.0f;
    CacheSelectedByteEntry(self,1);
    SubmitPercentScaledDisplayRecord(self,value,4);
}
