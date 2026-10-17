#include <globaldefs.h>
ARM
#include <Filesystem/BackgroundLoader.h>
// Original: arm9/main @ 0x020DBF70; symbol: func_020dbf70; size: 0x34.
extern "C" void BackgroundLoader_RemoveTaskAndClearLoadedPointer(int object){if(*(int*)(object+12)<0)return;BackgroundLoader* loader=BackgroundLoader::GetInstance();loader->RemoveTask(*(int*)(object+12));*(int*)(object+12)=-1;*(int*)(object+16)=0;}
