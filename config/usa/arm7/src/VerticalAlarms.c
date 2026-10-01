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
VerticalAlarmState ARM7_VerticalAlarmState;
extern unsigned int ARM7_DisableSpecificInterrupts(unsigned int);
extern void ARM7_ArmVerticalAlarm(VerticalAlarm*);
void ARM7_InitializeVerticalAlarms(void)
{
    if (ARM7_VerticalAlarmState.initialized)
        return;
    ARM7_VerticalAlarmState.initialized=1;
    ARM7_VerticalAlarmState.first=0;
    ARM7_VerticalAlarmState.last=0;
    ARM7_DisableSpecificInterrupts(4);
    ARM7_VerticalAlarmState.frame=0;
    ARM7_VerticalAlarmState.previousScanline=0;
}
int ARM7_IsVerticalAlarmInitialized(void)
{
    return ARM7_VerticalAlarmState.initialized;
}
void ARM7_InsertVerticalAlarm(VerticalAlarm *alarm)
{
    VerticalAlarm *next=ARM7_VerticalAlarmState.first;
    VerticalAlarm *prev;
    while(next) {
        if(next->frame >= alarm->frame && (next->frame != alarm->frame || next->scanline > alarm->scanline)) {
            prev=next->prev;
            alarm->prev=prev;
            alarm->next=next;
            next->prev=alarm;
            if(prev) prev->next=alarm;
            else {ARM7_VerticalAlarmState.first=alarm;ARM7_ArmVerticalAlarm(alarm);}
            return;
        }
        next=next->next;
    }
    prev=ARM7_VerticalAlarmState.last;
    alarm->prev=prev;
    alarm->next=0;
    ARM7_VerticalAlarmState.last=alarm;
    if(prev)prev->next=alarm;
    else {ARM7_VerticalAlarmState.first=alarm;ARM7_ArmVerticalAlarm(alarm);}
}
void ARM7_RemoveVerticalAlarm(VerticalAlarm *alarm)
{
    VerticalAlarm *prev,*next;
    if (!alarm)
        return;
    next=alarm->next;
    prev=alarm->prev;
    if(next)next->prev=prev;
    else ARM7_VerticalAlarmState.last=prev;
    if(prev)prev->next=next;
    else ARM7_VerticalAlarmState.first=next;
}
void ARM7_ZeroInitializeVerticalAlarm(VerticalAlarm *alarm)
{
    alarm->callback = 0;
    alarm->tag = 0;
    alarm->unknown32 = 0;
}
