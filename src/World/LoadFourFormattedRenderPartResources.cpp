#include <globaldefs.h>
#include <std_library_functions.h>
#include <World/Zone3DContainers.h>
extern "C" {
    extern char LoadFourFormattedRenderPartResources_FormatArrowDSpr[];

    void ResourceFile_LoadNamedRFileUnderLoaderLock(void *,const char *,int);
// Original: arm9/main @ 0x02096604; symbol: func_02096604; size: 0x9C.
    void LoadFourFormattedRenderPartResources(unsigned char *p,int value){
        char path[64];
        for(int i=0;i<4;i++){
            sprintf(path,LoadFourFormattedRenderPartResources_FormatArrowDSpr,i);
            ((ZoneContainerRenderPart *)(p+i*136))->Reset();
            ResourceFile_LoadNamedRFileUnderLoaderLock(p+i*136,path,value);
        }p[544]=0;
        p[545]=0;
        p[546]=0;
        p[547]=0;
        p[548]=0;
        p[549]=0;
        *(short *)(p+552)=0;
        *(short *)(p+554)=0;
        *(short *)(p+556)=0;
        p[560]=0;
        p[550]=0;
    }
}
