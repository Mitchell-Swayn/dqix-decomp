#include <globaldefs.h>
#include <System/Matrix.h>
ARM
// Original: arm9/ov000 @ 0x0216D234; symbol: func_ov000_0216d234; size: 0x9C.
extern "C" void Math_BuildYUpBasisAndTranslation(const Vector3fix* direction,const Vector3fix* translation,Matrix4x3* out){
Vector3fix up;Vector3fix cross;up.x=0;up.y=0x1000;up.z=0;
Vector3fix_CrossProduct(direction,&up,&cross);
out->rows[0].x=cross.x;out->rows[0].y=cross.y;out->rows[0].z=cross.z;
out->rows[1].x=up.x;out->rows[1].y=up.y;out->rows[1].z=up.z;
out->rows[2].x=direction->x;out->rows[2].y=direction->y;out->rows[2].z=direction->z;
out->rows[3].x=translation->x;out->rows[3].y=translation->y;out->rows[3].z=translation->z;
}
