#include <globaldefs.h>
ARM
struct Vector3fix { int x,y,z; };
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void Vector3fix_Add(const Vector3fix*,const Vector3fix*,Vector3fix*);
extern "C" void Vector3fix_Subtract(const Vector3fix*,const Vector3fix*,Vector3fix*);
extern "C" void _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(const Vector3fix*,int,Vector3fix*);
extern "C" void _Z22Vector3fixDivideScalarPK8Vector3iiPS_(const Vector3fix*,int,Vector3fix*);
// Original: arm9/ov001 @ 0x02158654; symbol: func_ov001_02158654; size: 0x170.
extern "C" int Object_UpdateAlternatingDisplacement(char* action,char* object) {
 if(*(int*)(action+0x1c)<=-1) {
  *(int*)(object+0x134)=1;
  memcpy(object+0x150,object+0x58,12);
  int phase=*(int*)(object+0x44)%4;
  if(phase==0)Vector3fix_Add((Vector3fix*)(object+0x58),(Vector3fix*)(action+4),(Vector3fix*)(object+0x58));
  else if(phase==2)Vector3fix_Subtract((Vector3fix*)(object+0x58),(Vector3fix*)(action+4),(Vector3fix*)(object+0x58));
  *(int*)(object+0x44)+=1;
  *(int*)(object+0xa24)=1;
 } else {
  if(*(int*)(object+0x44)>=*(int*)(action+0x1c)) {
   *(int*)(object+0x44)=0;
   *(int*)(object+0x134)=0;
   return 0;
  }
  if(*(int*)(object+0x44)<=0) {
   *(int*)(object+0x134)=1;
   memcpy(object+0x138,action+4,12);
   *(int*)(object+0xa24)=1;
  }
  memcpy(object+0x150,object+0x58,12);
  int phase=*(int*)(object+0x44)%4;
  if(phase==0)Vector3fix_Add((Vector3fix*)(object+0x58),(Vector3fix*)(object+0x138),(Vector3fix*)(object+0x58));
  else if(phase==2) {
   Vector3fix_Subtract((Vector3fix*)(object+0x58),(Vector3fix*)(object+0x138),(Vector3fix*)(object+0x58));
   Vector3fix tmp;
   _Z22Vector3fixDivideScalarPK8Vector3iiPS_((Vector3fix*)(action+4),*(int*)(action+0x1c)<<12,&tmp);
   _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(&tmp,*(int*)(object+0x44)<<12,&tmp);
   Vector3fix_Subtract(&tmp,(Vector3fix*)(object+0x138),(Vector3fix*)(action+4));
  }
  *(int*)(object+0x44)+=1;
 }
 return 1;
}
