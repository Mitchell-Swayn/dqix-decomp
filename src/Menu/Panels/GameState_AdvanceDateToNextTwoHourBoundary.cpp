#include <globaldefs.h>
ARM
#pragma always_inline on
struct GameResources;
extern "C" GameResources* GameResources_GetInstance();
struct Date {unsigned year:12,month:4,day:5,hour:5,minute:6;};
struct Days {unsigned values[12];};
// Original data: arm9/ov023 @ 0x21fd8a8; symbol: data_ov023_021fd8a8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 1f0000001c0000001f0000001e0000001f0000001e0000001f0000001f0000001e0000001f0000001e0000001f000000.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" const Days GameStateAdvanceDateToNextTwoHourBoundary_UnknownRoleInitializedBytes;
// Original: arm9/ov023 @ 0x021F6158; symbol: func_ov023_021f6158; size: 0x1CC.
extern "C" void GameState_AdvanceDateToNextTwoHourBoundary(Date* date) {
 char* state=*(char**)((char*)GameResources_GetInstance()+0x3b48);
 unsigned hour=date->hour;
 int nextDay=0;
 unsigned target=*(unsigned char*)(state+0x33);
 if(target<=hour) {
  date->hour=target; date->minute=0;nextDay=1;
 } else {
  int previous=target-2;
  if(previous<0)previous+=24;
  if(hour<(unsigned)previous) {
   date->minute=0;
   date->hour=*(unsigned char*)(state+0x33);
  }else {
   date->hour+=2;
   if(date->hour>=24) {date->hour-=24;nextDay=1;}
  }
 }
 if(nextDay) {
  ++date->day;
  Days days=GameStateAdvanceDateToNextTwoHourBoundary_UnknownRoleInitializedBytes;
  if((date->year&3)==0)days.values[1]=29;
  if((days.values-1)[date->month]<date->day || date->day==0) {
   date->day=1;
   ++date->month;
   if(date->month>12) {date->month=1;++date->year;}
  }
 }
}
