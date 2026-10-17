#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
extern "C" char data_020f0079[],data_020f007c[],data_0210782c[],data_02107830[],data_02107834[],data_02107838[];extern "C" void TextLookup_LoadAndRelocateTwoResourceFiles(void*,void*,void*,void*);
// Original: arm9/main @ 0x02042944; symbol: func_02042944; size: 0x54.
extern "C" ARM void LoadTwoFontArchivesUnderLoaderLock(void* p){BackgroundLoader::AddLockGlobal();TextLookup_LoadAndRelocateTwoResourceFiles(p,data_020f0079,data_0210782c,data_02107834);TextLookup_LoadAndRelocateTwoResourceFiles(p,data_020f007c,data_02107830,data_02107838);BackgroundLoader::RemoveLockGlobal();}
