#include <globaldefs.h>
extern "C" unsigned char* SpriteAnimation_FindTrackByKey();
// Original: arm9/main @ 0x0205A3AC; symbol: func_0205a3ac; size: 0x24.
extern "C" ARM void SpriteAnimation_StopTrack(){unsigned char* object=SpriteAnimation_FindTrackByKey();if(object){object[21]&=~7;object[21]|=1;}}
