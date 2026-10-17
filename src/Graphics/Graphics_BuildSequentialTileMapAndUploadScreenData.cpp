#include <globaldefs.h>
#include <std_library_functions.h>
#include "System/Cache.h"
#include "System/LoadToVRAM.h"
extern "C" unsigned short* data_020fe9a4;
extern "C" char data_020ef74c[];
// Original: arm9/main @ 0x02028F54; symbol: func_02028f54; size: 0x10C.
extern "C" ARM void Graphics_BuildSequentialTileMapAndUploadScreenData()
{
    void* data=data_020fe9a4;
    if(!data)return;
    if(data)memset(data,0,0x6000);
    unsigned short* out;
    unsigned short tile=0;
    int y=0;
    out=data_020fe9a4;
    for(;y<24;++y)for(int x=0;x<32;++x)
    {
        *out=tile;
        out++;
        tile++;
    }
    int mode=*(int*)(data_020ef74c+12);
    CleanInvalidateCacheRange(data_020fe9a4,0x600);
    if(mode==3)
    {
        LoadToMainBG1ScreenData(data_020fe9a4,0,0x600);
        return;
    }if(mode==4)
    {
        LoadToSubBG0ScreenData(data_020fe9a4,0,0x600);
        return;
    }if(mode==5)
    {
        LoadToMainBG1ScreenData(data_020fe9a4,0,0x600);
        return;
    }if(mode!=6)return;
    LoadToSubBG0ScreenData(data_020fe9a4,0,0x600);
}
