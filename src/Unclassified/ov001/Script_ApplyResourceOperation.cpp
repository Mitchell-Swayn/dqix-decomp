#include <globaldefs.h>
#include <Resource/GameResources.h>
ARM
struct IntegerParameterView;
extern "C" ARM int ReadScriptParameterAsInteger(IntegerParameterView *);
extern "C" void Graphics_TranslateLinkedFixedPointCoordinatePair(GameResources *, int, int);
// Original: arm9/ov001 @ 0x02160A48; symbol: func_ov001_02160a48; size: 0x34.
extern "C" int Script_ApplyResourceOperation(IntegerParameterView *parameters) {
    int first = ReadScriptParameterAsInteger(parameters);
    int second = ReadScriptParameterAsInteger((IntegerParameterView *)((char *)parameters + 8));
    Graphics_TranslateLinkedFixedPointCoordinatePair(GameResources_GetInstance(), first, second);
    return 1;
}
