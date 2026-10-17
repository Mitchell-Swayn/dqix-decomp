#include <globaldefs.h>
#include <World/WorldPlacementSource.h>
extern "C" {
// Original: arm9/main @ 0x020120D4; symbol: func_020120d4; size: 0x1C.
void GameState_SetByteField5CDAAndClearPlacementFlag(char *p,unsigned char v){*(unsigned char *)(p+0x5cda)=v;((char *)WorldPlacementSource::GetInstance())[10]=0;}
}
