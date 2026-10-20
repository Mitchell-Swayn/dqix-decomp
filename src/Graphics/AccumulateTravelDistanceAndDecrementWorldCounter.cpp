#include <globaldefs.h>
ARM
#include <Graphics/Vector.h>
extern "C" unsigned char* Zone3D_GetMainInstance();extern "C" unsigned char* GameResources_GetInstance();
// Original: arm9/main @ 0x020A7CE0; symbol: func_020a7ce0; size: 0x94.
extern "C" void AccumulateTravelDistanceAndDecrementWorldCounter(unsigned char* object){unsigned char* state=Zone3D_GetMainInstance();unsigned char* resources=GameResources_GetInstance();if(!(*(unsigned char**)(resources+0x3734))[3]){Vector3fix position=*(Vector3fix*)(object+0x44);int distance=Vector3fix_Distance(&position,(Vector3fix*)(object+0x144));int total=*(int*)(object+0x150)+distance;*(int*)(object+0x150)=total;if(total>=0x3000){int amount=total/0x3000;*(int*)(state+0x2794)-=amount;*(int*)(object+0x150)-=amount<<12;}*(Vector3fix*)(object+0x144)=position;}}
