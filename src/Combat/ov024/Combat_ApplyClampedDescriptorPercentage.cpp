#include <globaldefs.h>
ARM
struct LinkedDescriptorView;
struct Descriptor {char pad[20];unsigned low:7;unsigned rate:7;unsigned high:18;};
extern "C" int Object_TestDescriptorExclusionFlagsClear(LinkedDescriptorView*);
extern "C" bool TestFlags1And1000000Clear(unsigned*);
extern "C" int TestDescriptorFlag20(void*);
extern "C" void CacheSelectedByteEntry(void*,int);
extern "C" void SubmitPercentScaledDisplayRecord(void*,float,int);
// Original: arm9/ov024 @ 0x021FD5C4; symbol: func_ov024_021fd5c4; size: 0xA8.
extern "C" void Combat_ApplyClampedDescriptorPercentage(char* self) {
char* object=*(char**)(self+0x668);
if(!Object_TestDescriptorExclusionFlagsClear((LinkedDescriptorView*)object)) return;
if(!TestFlags1And1000000Clear(*(unsigned**)(object+0x138))) return;
if(TestDescriptorFlag20(object)) return;
float rate=(float)(*(Descriptor**)(self+0x64c))->rate;
rate*=((float)*(unsigned char*)(*(char**)(object+0x138)+0x4a))/100.0f;
if(rate>100.0f) rate=100.0f;
CacheSelectedByteEntry(self,1);
SubmitPercentScaledDisplayRecord(self,rate,7);
}
