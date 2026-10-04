#ifndef ARM7_SPI_SERVICE_H
#define ARM7_SPI_SERVICE_H
#include "ThreadContext.h"
#include "MessageQueue.h"
typedef struct {unsigned int type,command,arguments[4];} SpiTask;
/* The initializer binds these real allocations into a single service state. */
typedef struct {
 int busy,owner;
 ProcessorContext thread;
 unsigned int stack[128];
 MessageQueue queue;
 void *messages[16];
 SpiTask tasks[16];
 unsigned int nextTask;
 BlockedContextList waiters;
 unsigned int cookie;
} SpiServiceBody;
typedef struct {
 unsigned short initialized,padding;
 SpiServiceBody body;
} SpiServiceState;
typedef char SpiServiceBodySizeCheck[sizeof(SpiServiceBody)==0x49c?1:-1];
typedef char SpiServiceStateSizeCheck[sizeof(SpiServiceState)==0x4a0?1:-1];
extern SpiServiceState ARM7_SpiServiceState;
extern BlockedContextList ARM7_SpiServiceWaiters;
extern MessageQueue ARM7_SpiTaskQueue;
typedef char SpiTaskSizeCheck[sizeof(SpiTask)==24?1:-1];
#endif
