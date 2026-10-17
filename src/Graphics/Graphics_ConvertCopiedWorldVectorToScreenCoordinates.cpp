#pragma always_inline on
struct Words3 { int x,y,z; }; struct Vector3i { int x,y,z; }; int ConvertWorldToScreenCoordinates(const Vector3i*,int*,int*);
// Original: arm9/main @ 0x0202EC84; symbol: func_0202ec84; size: 0x44.
 extern "C" int Graphics_ConvertCopiedWorldVectorToScreenCoordinates(void*,const Words3 *input,int *out1,int *out2) { Words3 local=*input; int a,b; int result=ConvertWorldToScreenCoordinates((const Vector3i*)&local,&a,&b); *out1=a; *out2=b; return result; }
