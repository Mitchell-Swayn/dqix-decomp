#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];extern "C" int ReadSelectedCoordinatePair(void*,int*,int*);extern "C" unsigned char* TextCanvas_FindDisplayPartByKey(unsigned char*,unsigned);extern "C" bool TextCanvas_IsReady(int);extern "C" void GameState_CopyLanguageMappedBytes(char*,char*,char*,char*);
// Original: arm9/ov003 @ 0x021782A0; symbol: Input_TestMappedHorizontalTouchIntervals; size: 0xFC.
extern "C" int Shop_ReadQuantityConfirmationTouch(char* self){if(!Main_UnknownRoleZeroInitializedStorage_Variant4[95]||!U(Main_UnknownRoleZeroInitializedStorage_Variant4,36))return 0;int x,y;ReadSelectedCoordinatePair(Main_UnknownRoleZeroInitializedStorage_Variant4,&x,&y);if(y<93||y>110)return 0;char* record=(char*)TextCanvas_FindDisplayPartByKey((unsigned char*)P(self,0x89c),10);if(!record)return 0;if(!TextCanvas_IsReady((int)record))return 0;char a,b,c,d;GameState_CopyLanguageMappedBytes(&a,&b,&c,&d);short offset=H(record,0xac)<<3;short first=a+offset;short second=b+offset;short endFirst=c+first;short endSecond=d+second;if(x>=first&&x<=endFirst)return 1;if(first<=x&&x<=endSecond)return -1;return 0;}
