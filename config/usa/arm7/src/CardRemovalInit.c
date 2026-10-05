/* Register card-removal IPC handling after the remote handler is ready. */
#pragma dont_inline on
#include "CardRemoval.h"
extern void ARM7_StartIPC(void);
extern int ARM7_IsIpcHandlerRegistered(int,int);
extern void ARM7_SetIpcHandler(int,void(*)(int,unsigned int,int));
extern void ARM7_CardRemovalCallback(int,unsigned int,int);
extern int ARM7_CheckCardIdentity(void);
extern int ARM7_CheckCardInterrupt(void);
void ARM7_InitializeCardRemoval(void)
{
 if(!ARM7_CardRemovalState.initialized) {
  ARM7_CardRemovalState.initialized=1;
  ARM7_StartIPC();
  while(!ARM7_IsIpcHandlerRegistered(14,0)) {}
  ARM7_SetIpcHandler(14,ARM7_CardRemovalCallback);
 }
}
