#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void Vector3fix_Add(const void*,const void*,void*);
extern "C" void Vector3fix_Subtract(const void*,const void*,void*);
extern "C" void _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(const void*,int,void*);
extern "C" void _Z22Vector3fixDivideScalarPK8Vector3iiPS_(const void*,int,void*);
// Original: arm9/ov001 @ 0x02158494; symbol: func_ov001_02158494; size: 0x1C0.
extern "C" int UpdateAlternatingVectorOffsets(char* source,char* state) {
 if(*(int*)(source+0x1c)<=-1) {
 *(int*)(state+0x134)=1;
 memcpy(state+0x144,state+0x4c,12);
 memcpy(state+0x150,state+0x58,12);
 int phase=*(int*)(state+0x44)%4;
 if(phase==0) {
 Vector3fix_Add(state+0x4c,source+4,state+0x4c);
 Vector3fix_Add(state+0x58,source+4,state+0x58);
 } else if(phase==2) {
 Vector3fix_Subtract(state+0x4c,source+4,state+0x4c);
 Vector3fix_Subtract(state+0x58,source+4,state+0x58);
 }
 ++*(int*)(state+0x44);
 } else {
 if(*(int*)(state+0x44)>=*(int*)(source+0x1c)) {
 *(int*)(state+0x44)=0;*(int*)(state+0x134)=0;return 0;
 }
 if(*(int*)(state+0x44)<=0) {
 *(int*)(state+0x134)=1;
 memcpy(state+0x138,source+4,12);
 }
 memcpy(state+0x144,state+0x4c,12);
 memcpy(state+0x150,state+0x58,12);
 int phase=*(int*)(state+0x44)%4;
 if(phase==0) {
 Vector3fix_Add(state+0x4c,state+0x138,state+0x4c);
 Vector3fix_Add(state+0x58,state+0x138,state+0x58);
 } else if(phase==2) {
 Vector3fix_Subtract(state+0x4c,state+0x138,state+0x4c);
 Vector3fix_Subtract(state+0x58,state+0x138,state+0x58);
 int vec[3];
 _Z22Vector3fixDivideScalarPK8Vector3iiPS_(source+4,*(int*)(source+0x1c)<<12,vec);
 _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(vec,*(int*)(state+0x44)<<12,vec);
 Vector3fix_Subtract(vec,state+0x138,source+4);
 }
 ++*(int*)(state+0x44);
 }
 return 1;
}
