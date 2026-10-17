#include <globaldefs.h>
ARM
extern "C" unsigned short* ReadGlobalValueAt020FB3F0();extern "C" bool _Z12IsGrottoZonei(int);
// Original: arm9/main @ 0x020117F0; symbol: func_020117f0; size: 0x14.
extern "C" bool GameState_IsCurrentZoneGrotto(){return _Z12IsGrottoZonei(*ReadGlobalValueAt020FB3F0());}
