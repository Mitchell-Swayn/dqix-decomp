#include <globaldefs.h>
ARM
struct ClockDate { unsigned year,month,day,weekday; };
struct ClockTime { unsigned hour,minute,second; };
#pragma pack(4)
struct ClockOffsetState { unsigned valid; long long now,offset; };
#pragma pack()
extern "C" {
unsigned strlen(const char*);
char* strcpy(char*,const char*);
int strcmp(const char*,const char*);
int Runtime_ParseStringAsBaseTenInteger(const char*);
unsigned RealTimeClock_StartSynchronousRequestAndComplete(ClockDate*,ClockTime*);
long long Calendar_ConvertDateTimeToSeconds(const ClockDate*,const ClockTime*);
extern const char Network_SetTimeOffsetFromHttpDate_TextFri03Mar2006012813GMT[];
// Original data: arm9/main @ 0x20f3390; symbol: data_020f3390.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern int Dsqrt_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x224a1f4; symbol: data_ov031_0224a1f4.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex f0a12402eca12402e8a12402e4a12402e0a12402c4a12402c8a12402d4a12402d0a12402dca12402d8a12402cca12402.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern const char* NetworkSetTimeOffsetFromHttpDate_UnknownRoleDataReferences[];
// Original data: arm9/ov031 @ 0x224e688; symbol: data_ov031_0224e688.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern ClockOffsetState OnlineClockGetAdjustedDateTime_UnknownRoleZeroInitializedStorage;
}
// Original: arm9/ov031 @ 0x0221A218; symbol: func_ov031_0221a218; size: 0x21C.
extern "C" int Network_SetTimeOffsetFromHttpDate(const char* text) {
 long long now,remote;
 const char** months;
 int i;
 unsigned length=strlen(text);
 if(length!=strlen(Network_SetTimeOffsetFromHttpDate_TextFri03Mar2006012813GMT) || text[7]!=' ' || text[11]!=' ' || text[16]!=' ' || text[19]!=':' || text[22]!=':' || text[25]!=' ') goto fail;
 ClockDate date;
 ClockTime time;
 if(RealTimeClock_StartSynchronousRequestAndComplete(&date,&time)!=0) goto fail;
 now=Calendar_ConvertDateTimeToSeconds(&date,&time);
 if(now==-1) goto fail;
 char buffer[32];
 strcpy(buffer,text);
 buffer[7]=0;buffer[11]=0;buffer[16]=0;buffer[19]=0;buffer[22]=0;buffer[25]=0;
 Dsqrt_UnknownRoleZeroInitializedStorage=0;
 date.year=Runtime_ParseStringAsBaseTenInteger(buffer+12);
 if(Dsqrt_UnknownRoleZeroInitializedStorage==34) goto fail;
 months=NetworkSetTimeOffsetFromHttpDate_UnknownRoleDataReferences;
 date.year-=2000;
 date.month=13;
 i=0;
 do {
  if(strcmp(months[i],buffer+8)==0) { date.month=i+1; break; }
  ++i;
 } while(i<12);
 if(date.month>12) goto fail;
 Dsqrt_UnknownRoleZeroInitializedStorage=0;
 date.day=Runtime_ParseStringAsBaseTenInteger(buffer+5);
 if(Dsqrt_UnknownRoleZeroInitializedStorage==34) goto fail;
 Dsqrt_UnknownRoleZeroInitializedStorage=0;
 time.hour=Runtime_ParseStringAsBaseTenInteger(buffer+17);
 if(Dsqrt_UnknownRoleZeroInitializedStorage==34) goto fail;
 Dsqrt_UnknownRoleZeroInitializedStorage=0;
 time.minute=Runtime_ParseStringAsBaseTenInteger(buffer+20);
 if(Dsqrt_UnknownRoleZeroInitializedStorage==34) goto fail;
 Dsqrt_UnknownRoleZeroInitializedStorage=0;
 time.second=Runtime_ParseStringAsBaseTenInteger(buffer+23);
 if(Dsqrt_UnknownRoleZeroInitializedStorage==34) goto fail;
 remote=Calendar_ConvertDateTimeToSeconds(&date,&time);
 if(remote==-1) goto fail;
 OnlineClockGetAdjustedDateTime_UnknownRoleZeroInitializedStorage.offset=now-remote;
 OnlineClockGetAdjustedDateTime_UnknownRoleZeroInitializedStorage.now=now;
 OnlineClockGetAdjustedDateTime_UnknownRoleZeroInitializedStorage.valid=1;
 return 1;
fail:
 return 0;
}
