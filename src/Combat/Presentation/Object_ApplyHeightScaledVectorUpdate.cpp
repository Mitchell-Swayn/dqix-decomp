#include <globaldefs.h>
ARM
extern "C" unsigned _fadd(unsigned,unsigned);
extern "C" unsigned _fdiv(unsigned,unsigned);
extern "C" unsigned _fmul(unsigned,unsigned);
extern "C" unsigned _fsub(unsigned,unsigned);
extern "C" int _ffix(unsigned);
extern "C" unsigned _fflt(int);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_ReadUnknownB0(void*);
extern "C" char* Combat_GetIndexedActionTarget(void*,int);
extern "C" void* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" int _ZNK8Object3D9GetHeightEv(void*);
struct Vec {int x,y,z;};
extern "C" Vec* _ZN8Vector3iaSERKS_(Vec*,const Vec*);
extern "C" char* BattleScene_GetActiveInstance();
union FloatBits { unsigned u;float f; };
// Original: arm9/ov025 @ 0x021E5A6C; symbol: func_ov025_021e5a6c; size: 0x1FC.
extern "C" int Object_ApplyHeightScaledVectorUpdate(char* action,void* list) {
 void* gs=_ZN9GameState11GetInstanceEv();
 char* target=GameState_ReadUnknownB0(gs);
 if(*(unsigned char*)(action+0x14)==0) {
  if(target)_ZN8Vector3iaSERKS_((Vec*)(target+0x10),(Vec*)(action+8));
 } else if(*(unsigned char*)(action+0x14)==2) {
  int height=1;
  char* entry=Combat_GetIndexedActionTarget(list,0);
  if(entry) {
   void* obj=_ZN9GameState19GetCombatantByIndexEi(gs,*(short*)(entry+0xe));
   if(obj)height=_ZNK8Object3D9GetHeightEv(obj);
  }
  float scale=1.0f;
  if(height>=0x24cc) {
   scale=scale+(0.6f*((float)height/4096.0f-2.3f))/1.7f;
   if(scale>=1.6f)scale=1.6f;
  }
  float a=(float)*(int*)(action+0xc)/4096.0f;
  float b=(float)*(int*)(action+0x10)/4096.0f;
  a=a*scale;b=b*scale;
  *(int*)(action+0xc)=(int)(4096.0f*a);
  *(int*)(action+0x10)=(int)(4096.0f*b);
  if(target)_ZN8Vector3iaSERKS_((Vec*)(target+0x10),(Vec*)(action+8));
 } else if(target) {
  Vec a=*(Vec*)(target+0x10);
  Vec b=*(Vec*)(action+8);
  a.x+=b.x;a.y+=b.y;a.z+=b.z;
  _ZN8Vector3iaSERKS_((Vec*)(target+0x10),&a);
 }
 char* control=BattleScene_GetActiveInstance();
 if(control)*(unsigned char*)(control+0x6fd5)=1;
 return 1;
}
