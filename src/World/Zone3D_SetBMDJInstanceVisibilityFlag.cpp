#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" int IsCurrentResourceRecordTypeFour();extern "C" void* ReadGlobalValueAt020FB3F0();extern "C" unsigned char* _ZN6Zone3D16FindBMDJInstanceEit(void*,int,unsigned short);
// Original: arm9/main @ 0x020AE694; symbol: func_020ae694; size: 0x54.
extern "C" void Zone3D_SetBMDJInstanceVisibilityFlag(int enabled,int group,unsigned short id){if(!id)return;if(IsCurrentResourceRecordTypeFour())return;unsigned char* p=_ZN6Zone3D16FindBMDJInstanceEit(ReadGlobalValueAt020FB3F0(),group,id);if(!p)return;if(!enabled)*(unsigned short*)(p+2)|=4;else *(unsigned short*)(p+2)&=~4;}
