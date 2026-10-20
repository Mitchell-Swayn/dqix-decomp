#include <globaldefs.h>
ARM
struct Work {unsigned field[3];unsigned busy;void(*callback)(int,void*);int* output;int* output2;void* argument;unsigned state,step;void(*interrupt)();};
struct DateRaw {unsigned year:8,month:5,a:3,day:6,b:10;};
struct TimeRaw {unsigned hour:6,a:2,minute:7,b:1,second:7,c:9;};
struct AlarmRaw {unsigned weekday:3,a:4,wflag:1,hour:6,b:1,hflag:1,minute:7,mflag:1,c:8;};
struct StatusRaw {unsigned short mode:4,a:2,interrupt:1,b:9;};
extern "C" {
// Original data: arm9/main @ 0x2111818; symbol: data_02111818.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern Work RTCGetDate_UnknownRoleZeroInitializedStorage;
int RealTimeClock_DecodePackedDecimal(unsigned);int RTC_GetDayOfWeek(const int*);bool RealTimeClock_ReadRegisterCommand39();
}
#define DATE (*(DateRaw*)0x027ffde8)
#define TIME (*(TimeRaw*)0x027ffdec)
#define ALARM (*(AlarmRaw*)0x027ffdec)
#define STATUS (*(StatusRaw*)0x027ffdea)
// Original: arm9/main @ 0x020CF294; symbol: func_020cf294; size: 0x550.
extern "C" void System_HandleRtcFifoResponse(int tag,unsigned data,int error){
 if(error){
 if(RTCGetDate_UnknownRoleZeroInitializedStorage.step)RTCGetDate_UnknownRoleZeroInitializedStorage.step=0;
 if(RTCGetDate_UnknownRoleZeroInitializedStorage.busy)RTCGetDate_UnknownRoleZeroInitializedStorage.busy=0;
 void(*callback)(int,void*)=RTCGetDate_UnknownRoleZeroInitializedStorage.callback;
 if(callback){RTCGetDate_UnknownRoleZeroInitializedStorage.callback=0;callback(6,RTCGetDate_UnknownRoleZeroInitializedStorage.argument);}return;
 }
 unsigned char command=(data&0x7f00)>>8;
 unsigned char resultCode=data&0xff;
 if(command==0x30){if(RTCGetDate_UnknownRoleZeroInitializedStorage.interrupt)RTCGetDate_UnknownRoleZeroInitializedStorage.interrupt();return;}
 int result;
 if(resultCode==0){
 result=0;
 switch(RTCGetDate_UnknownRoleZeroInitializedStorage.state){
 case 0:{int* out=RTCGetDate_UnknownRoleZeroInitializedStorage.output;
 out[0]=RealTimeClock_DecodePackedDecimal(DATE.year);out[1]=RealTimeClock_DecodePackedDecimal(DATE.month);out[2]=RealTimeClock_DecodePackedDecimal(DATE.day);out[3]=RTC_GetDayOfWeek(out);break;}
 case 1:{int* out=RTCGetDate_UnknownRoleZeroInitializedStorage.output;
 out[0]=RealTimeClock_DecodePackedDecimal(TIME.hour);out[1]=RealTimeClock_DecodePackedDecimal(TIME.minute);out[2]=RealTimeClock_DecodePackedDecimal(TIME.second);break;}
 case 2:{int* out=RTCGetDate_UnknownRoleZeroInitializedStorage.output;
 out[0]=RealTimeClock_DecodePackedDecimal(*(unsigned*)0x027ffde8&0xff);out[1]=RealTimeClock_DecodePackedDecimal(DATE.month);out[2]=RealTimeClock_DecodePackedDecimal(DATE.day);out[3]=RTC_GetDayOfWeek(out);
 out=RTCGetDate_UnknownRoleZeroInitializedStorage.output2;out[0]=RealTimeClock_DecodePackedDecimal(TIME.hour);out[1]=RealTimeClock_DecodePackedDecimal(TIME.minute);out[2]=RealTimeClock_DecodePackedDecimal(TIME.second);break;}
 case 3:case 4:case 5:case 11:case 12:case 13:case 14:case 15:break;
 case 6:{int* out=RTCGetDate_UnknownRoleZeroInitializedStorage.output;switch(STATUS.mode){case 4:*out=1;break;default:*out=0;break;}break;}
 case 7:{int* out=RTCGetDate_UnknownRoleZeroInitializedStorage.output;if(STATUS.interrupt)*out=1;else *out=0;break;}
 case 8:{int* out=RTCGetDate_UnknownRoleZeroInitializedStorage.output;
 out[0]=ALARM.weekday;out[1]=RealTimeClock_DecodePackedDecimal(ALARM.hour);out[2]=RealTimeClock_DecodePackedDecimal(ALARM.minute);out[3]=0;
 if(ALARM.wflag)out[3]+=1;if(ALARM.hflag)out[3]+=2;if(ALARM.mflag)out[3]+=4;break;}
 case 9:
 if(RTCGetDate_UnknownRoleZeroInitializedStorage.step==0){
 if(*RTCGetDate_UnknownRoleZeroInitializedStorage.output==1){
 if(STATUS.mode!=4){RTCGetDate_UnknownRoleZeroInitializedStorage.step++;STATUS.mode=4;if(!RealTimeClock_ReadRegisterCommand39()){RTCGetDate_UnknownRoleZeroInitializedStorage.step=0;result=3;}}
 }else{
 if(STATUS.mode!=0){RTCGetDate_UnknownRoleZeroInitializedStorage.step++;STATUS.mode=0;if(!RealTimeClock_ReadRegisterCommand39()){RTCGetDate_UnknownRoleZeroInitializedStorage.step=0;result=3;}}
 }
 }else RTCGetDate_UnknownRoleZeroInitializedStorage.step=0;
 break;
 case 10:
 if(RTCGetDate_UnknownRoleZeroInitializedStorage.step==0){
 if(*RTCGetDate_UnknownRoleZeroInitializedStorage.output==1){
 if(!STATUS.interrupt){RTCGetDate_UnknownRoleZeroInitializedStorage.step++;STATUS.interrupt=1;if(!RealTimeClock_ReadRegisterCommand39()){RTCGetDate_UnknownRoleZeroInitializedStorage.step=0;result=3;}}
 }else{
 if(STATUS.interrupt){RTCGetDate_UnknownRoleZeroInitializedStorage.step++;STATUS.interrupt=0;if(!RealTimeClock_ReadRegisterCommand39()){RTCGetDate_UnknownRoleZeroInitializedStorage.step=0;result=3;}}
 }
 }else RTCGetDate_UnknownRoleZeroInitializedStorage.step=0;
 break;
 default:RTCGetDate_UnknownRoleZeroInitializedStorage.step=0;result=4;break;
 }
 }else{
 RTCGetDate_UnknownRoleZeroInitializedStorage.step=0;
 switch(resultCode){case 1:result=4;break;case 2:result=5;break;case 3:result=1;break;case 0:case 4:default:result=6;break;}
 }
 if(RTCGetDate_UnknownRoleZeroInitializedStorage.step)return;
 if(RTCGetDate_UnknownRoleZeroInitializedStorage.busy)RTCGetDate_UnknownRoleZeroInitializedStorage.busy=0;
 void(*callback)(int,void*)=RTCGetDate_UnknownRoleZeroInitializedStorage.callback;
 if(callback){RTCGetDate_UnknownRoleZeroInitializedStorage.callback=0;callback(result,RTCGetDate_UnknownRoleZeroInitializedStorage.argument);}
}
