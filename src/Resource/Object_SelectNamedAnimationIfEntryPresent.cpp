#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" int Object_FindNamedAnimationInSelectedEntry(void*,const char*);extern "C" void SelectResourceIndexAndResetProgress(void*,int);
// Original: arm9/main @ 0x0203F1E4; symbol: func_0203f1e4; size: 0x28.
extern "C" void Object_SelectNamedAnimationIfEntryPresent(unsigned char* p,const char* name){if(*(short*)(p+40)<0)return;int i=Object_FindNamedAnimationInSelectedEntry(p,name);SelectResourceIndexAndResetProgress(p,i);}
