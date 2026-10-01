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
extern unsigned int ARM7_DisableSpecificInterrupts(unsigned int);
extern void ARM7_ArmVerticalAlarm(VerticalAlarm*);
extern int ARM7_DisableIRQInterrupts(void);
extern int ARM7_SetIRQInterruptState(int);
extern unsigned int ARM7_UpdateVerticalFrame(int);
extern void ARM7_Panic(const char*,int,const char*,...);
extern const char ARM7_VerticalAlarmFile[],ARM7_VerticalAlarmError[];
extern void ARM7_InsertVerticalAlarm(VerticalAlarm*);
extern void ARM7_SetInterruptHandler(unsigned int,void(*)(int));
extern void ARM7_VerticalAlarmInterrupt(int);
extern unsigned int ARM7_EnableSpecificInterrupts(unsigned int);
#define VCOUNT (*(volatile unsigned short*)0x04000006)
#define DISPSTAT (*(volatile unsigned short*)0x04000004)
void ARM7_SetVerticalTimeout(VerticalAlarm *alarm,int scanline,int delay,Callback callback,void *userData)
{
 int state=ARM7_DisableIRQInterrupts();
 int current;
 unsigned int frame;
 if(!alarm || alarm->callback)ARM7_Panic(ARM7_VerticalAlarmFile,0x189,ARM7_VerticalAlarmError);
 current=VCOUNT;
 frame=ARM7_UpdateVerticalFrame(current);
 alarm->periodic=0;
 alarm->scanline=scanline;
 alarm->frame=(scanline<=current)?frame+1:frame;
 alarm->delay=delay;
 alarm->callback=callback;
 alarm->userData=userData;
 alarm->cancelled=0;
 ARM7_InsertVerticalAlarm(alarm);
 ARM7_SetIRQInterruptState(state);
}
void ARM7_SetVerticalInterval(VerticalAlarm *alarm,int scanline,int delay,Callback callback,void *userData)
{
 int state=ARM7_DisableIRQInterrupts();
 int current;
 unsigned int frame;
 if(!alarm || alarm->callback)ARM7_Panic(ARM7_VerticalAlarmFile,0x1c5,ARM7_VerticalAlarmError);
 current=VCOUNT;
 frame=ARM7_UpdateVerticalFrame(current);
 alarm->periodic=1;
 alarm->scanline=scanline;
 alarm->frame=(scanline<=current)?frame+1:frame;
 alarm->delay=delay;
 alarm->callback=callback;
 alarm->userData=userData;
 alarm->cancelled=0;
 ARM7_InsertVerticalAlarm(alarm);
 ARM7_SetIRQInterruptState(state);
}
void ARM7_ArmVerticalAlarm(VerticalAlarm *alarm)
{
 int scanline;
 ARM7_SetInterruptHandler(4,ARM7_VerticalAlarmInterrupt);
 scanline=alarm->scanline;
 DISPSTAT=(DISPSTAT&0x3f)|((scanline&0xff)<<8)|((scanline&0x100)>>1);
 DISPSTAT|=0x20;
 ARM7_EnableSpecificInterrupts(4);
}
