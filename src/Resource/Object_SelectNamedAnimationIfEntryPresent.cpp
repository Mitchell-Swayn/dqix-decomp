#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" int ActorSprite_FindNamedAnimation(void*,const char*);extern "C" void ActorSprite_SelectAnimation(void*,int);
// Original: arm9/main @ 0x0203F1E4; symbol: func_0203f1e4; size: 0x28.
extern "C" void Object_SelectNamedAnimationIfEntryPresent(unsigned char* p,const char* name){if(*(short*)(p+40)<0)return;int i=ActorSprite_FindNamedAnimation(p,name);ActorSprite_SelectAnimation(p,i);}
