#ifndef ARM7_VERTICAL_ALARM_H
#define ARM7_VERTICAL_ALARM_H
typedef void (*Callback)(void*);
typedef struct VerticalAlarm VerticalAlarm;
struct VerticalAlarm {
 Callback callback;
 void *userData;
 unsigned int tag,frame;
 short scanline,delay;
 VerticalAlarm *prev,*next;
 int periodic,unknown32,cancelled;
};
typedef struct {
 unsigned short initialized;
 int previousScanline;
 unsigned int frame;
 VerticalAlarm *first,*last;
} VerticalAlarmState;
typedef char VerticalAlarmSizeCheck[sizeof(VerticalAlarm)==40?1:-1];
typedef char VerticalAlarmStateSizeCheck[sizeof(VerticalAlarmState)==20?1:-1];
#endif
