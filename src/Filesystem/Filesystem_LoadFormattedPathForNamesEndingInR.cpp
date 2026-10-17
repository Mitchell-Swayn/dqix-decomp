#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
extern "C" unsigned strlen(const char *);extern "C" int sprintf(char *,const char *,...); extern "C" char data_020efe50[]; extern "C" void Graphics_LoadRResourceFramesPaletteAndGroups(void *,char *,unsigned,void *);
// Original: arm9/main @ 0x0203FCE0; symbol: func_0203fce0; size: 0x7C.
 extern "C" void Filesystem_LoadFormattedPathForNamesEndingInR(void *p,char *name,unsigned flags) { char path[128];if(*(name+strlen(name)-1)=='r') { sprintf(path,data_020efe50,name);BackgroundLoader::AddLockGlobal();void *file=LoadFileIntoMemory(path,data_0211e33c,0);if(file)Graphics_LoadRResourceFramesPaletteAndGroups(p,path,flags,file);BackgroundLoader::RemoveLockGlobal(); } }
