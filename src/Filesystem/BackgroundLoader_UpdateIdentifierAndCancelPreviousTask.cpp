#include <globaldefs.h>
#include <std_library_functions.h>
#include <Filesystem/BackgroundLoader.h>
extern "C" {
// Original: arm9/main @ 0x0208BECC; symbol: func_0208becc; size: 0x5C.
void BackgroundLoader_UpdateIdentifierAndCancelPreviousTask(char *p,int id,unsigned char v){if(id<0)return;if(*(short *)(p+0xd2)==id)return;*(short *)(p+0xd2)=id;p[0xdd]=v;if(*(volatile int *)(p+0xbc)>=0){BackgroundLoader::GetInstance()->RemoveTask(*(volatile int *)(p+0xbc));*(volatile int *)(p+0xbc)=-1;}*(unsigned short *)(p+0xda)|=32;p[0xd6]=0;}
}
