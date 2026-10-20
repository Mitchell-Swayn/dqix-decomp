#include <globaldefs.h>
ARM
struct IntegerParameterView {unsigned type;union {int integer;float real;} value;};
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" bool GameState_CopyStatisticsRecord(void*);
extern "C" int GameState_StoreStatisticsRecord(const void*);
// Original: arm9/ov023 @ 0x021E92F0; symbol: Script_SetStatisticsFlag; size: 0x5C.
// Sets a signed-script-indexed bit in the word array at state-buffer+0x4C.
extern "C" int Script_SetStatisticsFlag(IntegerParameterView* parameter) {
 unsigned buffer[44];
 GameState_CopyStatisticsRecord(buffer);
 int index=Script_ReadParameterAsInteger(parameter);
 unsigned* bits=buffer+19;
 bits[index/32]|=1<<(index%32);
 GameState_StoreStatisticsRecord(buffer);
 return 1;
}
