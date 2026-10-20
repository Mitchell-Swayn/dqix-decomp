#include <globaldefs.h>
ARM
#define D(p) ((unsigned)(p))
#define U32(p) (*(unsigned*)(p))
#define U16(p) (*(unsigned short*)(p))
#define S16(p) (*(short*)(p))
#define U8(p) (*(unsigned char*)(p))
#define S8(p) (*(signed char*)(p))
#define V32(p) (*(volatile unsigned*)(p))
#define V16(p) (*(volatile unsigned short*)(p))
extern "C" unsigned FieldMonster_GetContactRadiusScale(...);
extern "C" unsigned Vector3fix_Distance(...);
extern "C" unsigned _Z8fix32absi(...);
extern "C" unsigned _ZNK8Object3D8GetScaleEv(...);
extern "C" unsigned _ZNK8Object3D9GetRadiusEv(...);
// Original: arm9/ov017 @ 0x02196fc8; symbol: Graphics_TestNonzeroDistanceWithinCombinedRadii; size: 0xd8.
extern "C" int Graphics_TestNonzeroDistanceWithinCombinedRadii(unsigned first,unsigned second,int margin){
int radius=_ZNK8Object3D9GetRadiusEv(first),other;
if(U16(second)&32){int scale[3];_ZNK8Object3D8GetScaleEv(D(scale),second);int factor=scale[0]*15;int half=(int)FieldMonster_GetContactRadiusScale(second)>>1;other=(int)(((long long)half*factor+0x800)>>12);}
else other=(int)_ZNK8Object3D9GetRadiusEv(second)>>1;
int limit=margin+(other+(radius>>1));if(limit<(int)_Z8fix32absi(U32(first+0x44)-U32(second+0x44)))return 0;if(limit<(int)_Z8fix32absi(U32(first+0x4c)-U32(second+0x4c)))return 0;int distance=Vector3fix_Distance(first+0x44,second+0x44);if(limit<distance)return 0;return distance!=0;
}