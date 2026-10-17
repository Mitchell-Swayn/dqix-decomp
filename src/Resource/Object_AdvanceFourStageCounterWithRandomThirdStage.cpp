#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" void* _Z11GetBTRandomv();extern "C" int _Z13NextRandomMaxP6Randomi(void*,int);extern "C" int AreWordFlags100001900019Clear_Main0208810C(void*);extern "C" void Object_ResetStageAndSetFlag1000000(void*);
// Original: arm9/main @ 0x0208767C; symbol: func_0208767c; size: 0x88.
extern "C" int Object_AdvanceFourStageCounterWithRandomThirdStage(unsigned char* p,void* random){unsigned stage=p[36];if(stage>=4)return -2;if(stage==3){if(!random)random=_Z11GetBTRandomv();if(_Z13NextRandomMaxP6Randomi(random,2)>=1)return -1;}unsigned next=p[36]+1;p[36]=next;if((next&255)>=4&&AreWordFlags100001900019Clear_Main0208810C(p)){p[36]=4;Object_ResetStageAndSetFlag1000000(p);}return p[36];}
