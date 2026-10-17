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
extern const char data_ov031_0224a224[];
extern int data_020f3390;
extern const char* data_ov031_0224a1f4[];
extern ClockOffsetState data_ov031_0224e688;
}
// Original: arm9/ov031 @ 0x0221A218; symbol: func_ov031_0221a218; size: 0x21C.
extern "C" int Network_SetTimeOffsetFromHttpDate(const char* text) {
 long long now,remote;
 const char** months;
 int i;
 unsigned length=strlen(text);
 if(length!=strlen(data_ov031_0224a224) || text[7]!=' ' || text[11]!=' ' || text[16]!=' ' || text[19]!=':' || text[22]!=':' || text[25]!=' ') goto fail;
 ClockDate date;
 ClockTime time;
 if(RealTimeClock_StartSynchronousRequestAndComplete(&date,&time)!=0) goto fail;
 now=Calendar_ConvertDateTimeToSeconds(&date,&time);
 if(now==-1) goto fail;
 char buffer[32];
 strcpy(buffer,text);
 buffer[7]=0;buffer[11]=0;buffer[16]=0;buffer[19]=0;buffer[22]=0;buffer[25]=0;
 data_020f3390=0;
 date.year=Runtime_ParseStringAsBaseTenInteger(buffer+12);
 if(data_020f3390==34) goto fail;
 months=data_ov031_0224a1f4;
 date.year-=2000;
 date.month=13;
 i=0;
 do {
  if(strcmp(months[i],buffer+8)==0) { date.month=i+1; break; }
  ++i;
 } while(i<12);
 if(date.month>12) goto fail;
 data_020f3390=0;
 date.day=Runtime_ParseStringAsBaseTenInteger(buffer+5);
 if(data_020f3390==34) goto fail;
 data_020f3390=0;
 time.hour=Runtime_ParseStringAsBaseTenInteger(buffer+17);
 if(data_020f3390==34) goto fail;
 data_020f3390=0;
 time.minute=Runtime_ParseStringAsBaseTenInteger(buffer+20);
 if(data_020f3390==34) goto fail;
 data_020f3390=0;
 time.second=Runtime_ParseStringAsBaseTenInteger(buffer+23);
 if(data_020f3390==34) goto fail;
 remote=Calendar_ConvertDateTimeToSeconds(&date,&time);
 if(remote==-1) goto fail;
 data_ov031_0224e688.offset=now-remote;
 data_ov031_0224e688.now=now;
 data_ov031_0224e688.valid=1;
 return 1;
fail:
 return 0;
}
