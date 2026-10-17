#include <globaldefs.h>
ARM
struct Vec {int x,y,z;};struct Matrix {int entries[12];};
extern "C" {void* _ZN9GameState11GetInstanceEv();char* _ZN9GameState20GetGameObjectByIndexEi(void*,int);void ClearWordFlagBitZeroAtOffset168(void*);void Object_CopyBlockAtOffsetF0(char*,Matrix*);int _Z8fix32sini(int);int _Z8fix32cosi(int);void Math_BuildYUpBasisAndTranslation(const Vec*,const Vec*,Matrix*);}
// Original: arm9/ov000 @ 0x0216D560; symbol: func_ov000_0216d560; size: 0xA0.
extern "C" void UpdateMatrixFromIndexedObjectHeading(char* p,int index){
char* object=_ZN9GameState20GetGameObjectByIndexEi(_ZN9GameState11GetInstanceEv(),index);
if(!object){*(int*)(p+0x224)=-1;ClearWordFlagBitZeroAtOffset168(p);}
else{
Vec position=*(Vec*)(object+0x44);Vec rotation=*(Vec*)(object+0x50);Vec direction;Matrix matrix;
int heading=rotation.y;
direction.x=_Z8fix32sini(heading);direction.y=0;direction.z=_Z8fix32cosi(heading);
Math_BuildYUpBasisAndTranslation(&direction,&position,&matrix);
Object_CopyBlockAtOffsetF0(p,&matrix);
}
}
