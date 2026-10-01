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
unsigned int ARM7_UpdateVerticalFrame(int scanline)
{
 int state=ARM7_DisableIRQInterrupts();
 if(scanline<ARM7_VerticalAlarmState.previousScanline)
  ARM7_VerticalAlarmState.frame++;
 ARM7_VerticalAlarmState.previousScanline=scanline;
 ARM7_SetIRQInterruptState(state);
 return ARM7_VerticalAlarmState.frame;
}
