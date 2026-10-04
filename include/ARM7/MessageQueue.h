#ifndef ARM7_MESSAGE_QUEUE_H
#define ARM7_MESSAGE_QUEUE_H
#include "ThreadContext.h"
typedef BlockedContextList ThreadQueue;
typedef struct MessageQueue {
 ThreadQueue sendWaiters,receiveWaiters;
 void **messages;
 int capacity,head,count;
} MessageQueue;
typedef char MessageQueueSizeCheck[sizeof(MessageQueue)==32?1:-1];
#endif
