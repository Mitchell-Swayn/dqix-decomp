#include <globaldefs.h>
ARM
extern "C" char* _ZN16BackgroundLoader11GetInstanceEv(...);
extern "C" char* ZoneState2754_FindPrimaryRecordByKey(...);
extern "C" int _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(...);
extern "C" void Menu_ResetLayout(...);
extern "C" char ItemDetail_QueueCategoryLayout_PathDataAniLayIieLia[],ItemDetail_QueueCategoryLayout_PathDataAniLayIiuLia[];
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Four {short values[4];};struct Eight {short values[8];};
// Original: arm9/ov023 @ 0x021E0414; symbol: Graphics_QueueResourceForSerializedRecordCategory; size: 0xd4.
// Resolves selected serialized record, compares low-nibble category to cached signed byte and queues corresponding resource.
extern "C" int ItemDetail_QueueCategoryLayout(char* self){char* loader=_ZN16BackgroundLoader11GetInstanceEv();if(P(self,0x48))P(self,0x4c)=ZoneState2754_FindPrimaryRecordByKey(P(self,0x48),S(self,0x770));if(P(self,0x4c)){struct Category {unsigned value:4;unsigned rest:28;};int low=((Category*)(P(self,0x4c)+8))->value<=7;int flag;if(low)flag=1;else flag=0;if(*(signed char*)(self+0x79a)!=(signed char)flag){Menu_ResetLayout(self+0xcc);low=((Category*)(P(self,0x4c)+8))->value<=7;if(low)W(self,0x73c)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,ItemDetail_QueueCategoryLayout_PathDataAniLayIieLia,0);else W(self,0x73c)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,ItemDetail_QueueCategoryLayout_PathDataAniLayIiuLia,0);}}return 6;}
