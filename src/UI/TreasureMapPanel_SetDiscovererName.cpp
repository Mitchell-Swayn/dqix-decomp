#include <globaldefs.h>
extern "C" {
char *strcpy(char *, const char *);
void Text_MapInputBytesToVariableLengthOutputSequences(const char *, char *, int, int);
extern const char TreasureMapPanel_SetClearerName_Text[];
// Original: arm9/main @ 0x020264E4; symbol: func_020264e4; size: 0x44.
ARM void TreasureMapPanel_SetDiscovererName(void *param_1, char *param_2, int param_3, int param_4) {
    if (param_2 != 0) {
        param_3 = *param_2;
        if (param_3 != 0) {
            Text_MapInputBytesToVariableLengthOutputSequences(param_2, (char *)param_1 + 0x6f4, 1, param_4);
            return;
        }
    }
    strcpy((char *)param_1 + 0x6f4, TreasureMapPanel_SetClearerName_Text);
}
}
