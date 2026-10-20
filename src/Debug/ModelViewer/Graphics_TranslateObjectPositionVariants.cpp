#include <globaldefs.h>
#include <System/Matrix.h>
ARM
extern "C" void __clear(void*,unsigned);
extern "C" void _ZN8Vector3iaSERKS_(void*,const void*);
struct Triple{int x,y,z;};
inline char* Embedded(char* p){return p+0x408;}
inline char* Position(char* p){return p+0x44;}
inline char* EmbeddedPosition(char* p){return Position(Embedded(p));}
// Original: arm9/ov015 @ 0x0218F44C; symbol: func_ov015_0218f44c; size: 0x1AC.
extern "C" void Graphics_TranslateObjectPositionVariants(char* self,Triple delta){
 Vector3fix temp;__clear(&temp,12);
 switch(*(unsigned char*)(self+0x1c)){
case 0:
 _ZN8Vector3iaSERKS_(&temp,*(char**)(self+0x24)+240);
 Vector3fix_Add(&temp,(Vector3fix*)&delta,&temp);
 _ZN8Vector3iaSERKS_(*(char**)(self+0x24)+240,&temp);
 _ZN8Vector3iaSERKS_(&temp,*(char**)(self+0x24)+68);
 Vector3fix_Add(&temp,(Vector3fix*)&delta,&temp);
 _ZN8Vector3iaSERKS_(*(char**)(self+0x24)+68,&temp);
 break;
case 1:
 _ZN8Vector3iaSERKS_(&temp,EmbeddedPosition(*(char**)(self+0x24)));
 Vector3fix_Add(&temp,(Vector3fix*)&delta,&temp);
 _ZN8Vector3iaSERKS_(EmbeddedPosition(*(char**)(self+0x24)),&temp);
 _ZN8Vector3iaSERKS_(&temp,*(char**)(self+0x24)+240);
 Vector3fix_Add(&temp,(Vector3fix*)&delta,&temp);
 _ZN8Vector3iaSERKS_(*(char**)(self+0x24)+240,&temp);
 _ZN8Vector3iaSERKS_(&temp,*(char**)(self+0x24)+928);
 Vector3fix_Add(&temp,(Vector3fix*)&delta,&temp);
 _ZN8Vector3iaSERKS_(*(char**)(self+0x24)+928,&temp);
 _ZN8Vector3iaSERKS_(&temp,*(char**)(self+0x24)+68);
 Vector3fix_Add(&temp,(Vector3fix*)&delta,&temp);
 _ZN8Vector3iaSERKS_(*(char**)(self+0x24)+68,&temp);
 break;
default:
 _ZN8Vector3iaSERKS_(&temp,*(char**)(self+0x24)+68);
 Vector3fix_Add(&temp,(Vector3fix*)&delta,&temp);
 _ZN8Vector3iaSERKS_(*(char**)(self+0x24)+68,&temp);
 break;
 }
}
