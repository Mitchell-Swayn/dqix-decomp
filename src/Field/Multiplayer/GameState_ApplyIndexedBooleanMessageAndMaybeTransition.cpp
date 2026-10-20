#include <globaldefs.h>
ARM
#define D(p) ((unsigned)(p))
#define U32(p) (*(unsigned*)(p))
#define U16(p) (*(unsigned short*)(p))
#define S16(p) (*(short*)(p))
#define U8(p) (*(unsigned char*)(p))
#define S8(p) (*(signed char*)(p))
#define V32(p) (*(volatile unsigned*)(p))
#define V16(p) (*(volatile unsigned short*)(p))
extern "C" unsigned BitArray_SetIndexedBoolean(...);
extern "C" unsigned Zone3D_GetMainInstance(...);
extern "C" unsigned GameState_GetSerializedProgressState(...);
extern "C" unsigned Network_GetLocalMemberId(...);
extern "C" unsigned _ZN6Zone3D21SetTransitionRequest2Eb(...);
// Original: arm9/ov017 @ 0x021cdb4c; symbol: GameState_ApplyIndexedBooleanMessageAndMaybeTransition; size: 0xd8.
extern "C" void GameState_ApplyIndexedBooleanMessageAndMaybeTransition(unsigned unused,unsigned message,unsigned unused2,unsigned unused3,unsigned connection){
if(S8(message+4)>=0){int index=Network_GetLocalMemberId(connection);if(S8(message+4)!=index)return;}unsigned flags=GameState_GetSerializedProgressState();unsigned zone=Zone3D_GetMainInstance();switch(U8(message+5)){
case 0:break;case 1:BitArray_SetIndexedBoolean(flags,flags+0x8c,U16(message+6)+0x212,U32(message+8));break;case 2:break;case 3:break;case 4:break;case 5:break;case 6:break;case 8:BitArray_SetIndexedBoolean(flags,flags+0x8c,U16(message+6)+0x79e,U32(message+8));break;case 7:BitArray_SetIndexedBoolean(flags,flags+0x8c,U16(message+6)+0x33e,U32(message+8));_ZN6Zone3D21SetTransitionRequest2Eb(zone,1);break;}
}