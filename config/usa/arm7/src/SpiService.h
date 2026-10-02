#ifndef ARM7_SPI_SERVICE_H
#define ARM7_SPI_SERVICE_H
#include "ThreadContext.h"
typedef struct MessageQueue MessageQueue;
typedef struct {unsigned int type,command,arguments[4];} SpiTask;
typedef struct {unsigned int unknown0;int busy,owner;} SpiServiceState;
extern SpiServiceState ARM7_SpiServiceState;
extern BlockedContextList ARM7_SpiServiceWaiters;
extern MessageQueue ARM7_SpiTaskQueue;
typedef char SpiTaskSizeCheck[sizeof(SpiTask)==24?1:-1];
#endif
