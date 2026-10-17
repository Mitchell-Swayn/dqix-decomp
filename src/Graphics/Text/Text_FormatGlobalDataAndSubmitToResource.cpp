#include <globaldefs.h>
ARM
extern "C" char data_020f2948[],data_020f294f[];extern "C" char* GameResources_GetInstance();extern "C" void InitializeStateFieldsAndFourEntries(void*);extern "C" char* ReadGlobalValueAt020FB3F0();extern "C" int sprintf(char*,const char*,...);extern "C" void BackgroundLoader_QueueArchiveFileAndMarkPending(void*,const char*,const char*);
// Original: arm9/main @ 0x020DC3D4; symbol: func_020dc3d4; size: 0x54.
extern "C" void Text_FormatGlobalDataAndSubmitToResource(){char text[24];void* p=*(void**)(GameResources_GetInstance()+0x36d0);InitializeStateFieldsAndFourEntries(p);sprintf(text,data_020f2948,ReadGlobalValueAt020FB3F0()+38);BackgroundLoader_QueueArchiveFileAndMarkPending(p,data_020f294f,text);}
