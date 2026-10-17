#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
extern "C" {
extern char data_020f00cc[];
// Original: arm9/main @ 0x02046C98; symbol: func_02046c98; size: 0x30.
void BackgroundLoader_QueueFileWhenExternalObjectAbsent(unsigned int *p){if(p[58])return;p[59]=(unsigned int)BackgroundLoader::GetInstance()->QueueLoadFile(data_020f00cc,0);}
}
