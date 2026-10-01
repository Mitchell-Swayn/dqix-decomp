#pragma dont_inline on

/* Vertical-count alarm list, ordered by frame then signed scanline.
    * Names describe observed accesses; unknown32 is deliberately uninterpreted. */
typedef void (*Callback)(void*);
typedef struct VerticalAlarm VerticalAlarm;
struct VerticalAlarm {
    Callback callback;
    void *userData;
    unsigned int tag, frame;
    short scanline, delay;
    VerticalAlarm *prev, *next;
    int periodic, unknown32, cancelled;
};
typedef struct {
    unsigned short initialized;
    int previousScanline;
    unsigned int frame;
    VerticalAlarm *first, *last;
} VerticalAlarmState;
extern VerticalAlarmState ARM7_VerticalAlarmState;
extern int ARM7_DisableIRQInterrupts(void);
extern int ARM7_SetIRQInterruptState(int);
extern void ARM7_Panic(const char*,int,const char*,...);
extern const char ARM7_VerticalAlarmFile[],ARM7_VerticalAlarmError[];
extern const char ARM7_VerticalTagError[];
extern void ARM7_RemoveVerticalAlarm(VerticalAlarm*);
void ARM7_SetVerticalAlarmTag(VerticalAlarm *alarm,unsigned int tag)
{
 if(tag==0)ARM7_Panic(ARM7_VerticalAlarmFile,0x212,ARM7_VerticalTagError);
 if(alarm)alarm->tag=tag;
}
void ARM7_CancelVerticalAlarm(VerticalAlarm *alarm)
{
 int state=ARM7_DisableIRQInterrupts();
 alarm->cancelled=1;
 if(!alarm->callback){ARM7_SetIRQInterruptState(state);return;}
 ARM7_RemoveVerticalAlarm(alarm);
 alarm->callback=0;
 ARM7_SetIRQInterruptState(state);
}
void ARM7_CancelVerticalAlarmsByTag(unsigned int tag)
{
 int state=ARM7_DisableIRQInterrupts();
 VerticalAlarm *alarm,*next;
 if(!tag)ARM7_Panic(ARM7_VerticalAlarmFile,0x270,ARM7_VerticalTagError);
 alarm=ARM7_VerticalAlarmState.first;
 next=alarm?alarm->next:0;
 while(alarm){
  if(alarm->tag==tag)ARM7_CancelVerticalAlarm(alarm);
  alarm=next;
  next=next?next->next:0;
 }
 ARM7_SetIRQInterruptState(state);
}
