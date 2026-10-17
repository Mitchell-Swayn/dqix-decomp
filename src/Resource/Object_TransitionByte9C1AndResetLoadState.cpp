#include <globaldefs.h>
#include "Resource/Brightness.h"
extern "C" GameResources* GameResources_GetInstance();extern "C" void BackgroundLoader_ClearLoadStateAndRemoveTasks(void*);
// Original: arm9/main @ 0x02022D78; symbol: func_02022d78; size: 0x50.
extern "C" ARM void Object_TransitionByte9C1AndResetLoadState(unsigned char* p,unsigned char next){if(p[0x9c3])SetSubBrightness(GameResources_GetInstance(),-16,0);BackgroundLoader_ClearLoadStateAndRemoveTasks(p);p[0xa34]=p[0x9c1];p[0x9c1]=next;p[0x9c3]=1;p[0x9c2]=0;}
