#include <globaldefs.h>
#include <std_library_functions.h>
#include <Filesystem/BackgroundLoader.h>
extern "C" {
// Original: arm9/main @ 0x020DFE88; symbol: func_020dfe88; size: 0x38.
int BackgroundLoader_CancelTaskAndResetCountAndValue(char *p){BackgroundLoader *loader=BackgroundLoader::GetInstance();int task=*(int *)(p+0x10);if(task>=0){loader->RemoveTask(task);*(int *)(p+0x10)=-1;}*(short *)(p+14)=0;*(int *)(p+20)=0;return 1;}
}
