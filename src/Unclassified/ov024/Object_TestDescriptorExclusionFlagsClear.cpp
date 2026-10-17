#include <globaldefs.h>
ARM
struct DescriptorFlagView { unsigned char pad[0x14]; unsigned flags; };
struct LinkedDescriptorView { unsigned char pad[0x138]; DescriptorFlagView* descriptor; };
extern "C" bool Object_TestNestedOffset138Word14Bit0(void*);
extern "C" bool Object_TestElement5Mask10(unsigned int*);
extern "C" int TestLinkedDescriptorFlag8(LinkedDescriptorView*);
extern "C" int TestLinkedDescriptorFlag80000(LinkedDescriptorView*);
extern "C" int TestDescriptorFlag20(unsigned char*);
extern "C" int TestRecordFlags18Mask2000(void*);
// Original: arm9/ov024 @ 0x021FA76C; symbol: func_ov024_021fa76c; size: 0x80.
extern "C" int Object_TestDescriptorExclusionFlagsClear(LinkedDescriptorView* p) {
if(Object_TestNestedOffset138Word14Bit0(p))return 0;
if(TestRecordFlags18Mask2000(p))return 0;
if(TestLinkedDescriptorFlag8(p))return 0;
if(Object_TestElement5Mask10((unsigned*)p->descriptor))return 0;
if(TestLinkedDescriptorFlag80000(p))return 0;
return TestDescriptorFlag20((unsigned char*)p)==0;
}
