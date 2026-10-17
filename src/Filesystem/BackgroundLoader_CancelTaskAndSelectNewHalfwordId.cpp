#include <globaldefs.h>
#include <std_library_functions.h>
#include <Filesystem/BackgroundLoader.h>
extern "C" {
// Original: arm9/main @ 0x0208BF28; symbol: func_0208bf28; size: 0x50.
void BackgroundLoader_CancelTaskAndSelectNewHalfwordId(char *p,int id,unsigned char v){if(id<0)return;*(short *)(p+0xd2)=id;p[0xdd]=v;if(*(volatile int *)(p+0xbc)>=0){BackgroundLoader::GetInstance()->RemoveTask(*(volatile int *)(p+0xbc));*(volatile int *)(p+0xbc)=-1;}*(unsigned short *)(p+0xda)|=32;p[0xd6]=0;}
}
