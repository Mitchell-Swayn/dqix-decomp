#include <globaldefs.h>
ARM
extern "C" int _ZNK8Object3D9GetHeightEv(void*);
extern "C" int _ZNK8Object3D9GetRadiusEv(void*);
extern "C" int _Z8fix32absi(int);
extern "C" int Vector3fix_Distance(const void*,const void*);
// Original: arm9/ov017 @ 0x02194140; symbol: func_ov017_02194140; size: 0xAC.
extern "C" int Graphics_TestObjectBoundsOverlap(char* a,char* b) {
int ha=_ZNK8Object3D9GetHeightEv(a);
int hb=_ZNK8Object3D9GetHeightEv(b);
if(*(int*)(a+0x48)+ha<*(int*)(b+0x48) || *(int*)(b+0x48)+hb<*(int*)(a+0x48)) return 0;
int ra=_ZNK8Object3D9GetRadiusEv(a);
int rb=_ZNK8Object3D9GetRadiusEv(b);
int radius=(ra>>1)+(rb>>1);
if(radius<_Z8fix32absi(*(int*)(a+0x44)-*(int*)(b+0x44)) || radius<_Z8fix32absi(*(int*)(a+0x4c)-*(int*)(b+0x4c))) return 0;
return radius>=Vector3fix_Distance(a+0x44,b+0x44);
}
