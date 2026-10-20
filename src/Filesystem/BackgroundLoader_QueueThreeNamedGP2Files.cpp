#include <globaldefs.h>
ARM
#include <Filesystem/BackgroundLoader.h>
#include <std_library_functions.h>
extern "C" void __clear(void*,unsigned);extern "C" char BackgroundLoader_QueueThreeNamedGP2Files_FormatSLGBin[],BackgroundLoader_QueueThreeNamedGP2Files_FormatSTxtBin[],BackgroundLoader_QueueThreeNamedGP2Files_FormatSWndBin[];
// Original: arm9/main @ 0x0207F914; symbol: func_0207f914; size: 0xE0.
extern "C" void BackgroundLoader_QueueThreeNamedGP2Files(unsigned* p,unsigned value,const char* gp2,unsigned index){
    if(value&&gp2&&index){
        p[5]=value;BackgroundLoader* loader=BackgroundLoader::GetInstance();
        char third[32],second[32],first[32];__clear(third,32);__clear(second,32);__clear(first,32);
        sprintf(first,BackgroundLoader_QueueThreeNamedGP2Files_FormatSLGBin,index);sprintf(second,BackgroundLoader_QueueThreeNamedGP2Files_FormatSTxtBin,index);sprintf(third,BackgroundLoader_QueueThreeNamedGP2Files_FormatSWndBin,index);
        p[8]=loader->QueueLoadFileInGP2(gp2,first,0);p[9]=loader->QueueLoadFileInGP2(gp2,second,0);p[10]=loader->QueueLoadFileInGP2(gp2,third,0);
    }
}
