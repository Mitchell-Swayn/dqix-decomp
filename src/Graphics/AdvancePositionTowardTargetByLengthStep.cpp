#include <globaldefs.h>
#include <Graphics/Vector.h>
// Original: arm9/main @ 0x02033E38; symbol: func_02033e38; size: 0x90.
extern "C" void AdvancePositionTowardTargetByLengthStep(unsigned char* p) { Vector3fix delta,result; short step=*(short*)(p+198); if(step){ Vector3fix_Subtract((Vector3fix*)(p+200),(Vector3fix*)(p+68),&delta); int length=Vector3fix_Length(&delta); if(length<step){ *(Vector3fix*)(p+68)=*(Vector3fix*)(p+200); *(short*)(p+198)=0; }else { int scale=fix32_Divide(step,length); Vector3fixMultiplyScalar(&delta,scale,&delta); Vector3fix_Add((Vector3fix*)(p+68),&delta,&result); *(Vector3fix*)(p+68)=result; } } }
