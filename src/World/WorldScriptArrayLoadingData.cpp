#include "World/WorldScriptArrayList.h"
#include "Resource/Script.h"

extern "C" {
    int func_0208d540(Script::Parameter*, int);
    int func_0208d548(Script::Parameter*, int);
    int func_0208d550(Script::Parameter*, int);
    int func_0208d594(Script::Parameter*, int);

    WorldScriptArrayLoadingState data_02108fc0;
    Script::OpcodeLookupEntry data_020f121c[5] = {
        {100, func_0208d540}, {101, func_0208d548},
        {102, func_0208d550}, {103, func_0208d594}, {0, 0}
    };
}
