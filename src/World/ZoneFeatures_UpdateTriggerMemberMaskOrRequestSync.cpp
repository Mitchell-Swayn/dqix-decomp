#include <globaldefs.h>
ARM
extern "C" {void Network_GetConnectionManager(void*);int Network_GetLocalMemberId();void ZoneFeatures_QueueTriggerSynchronization(int,int,int,int,unsigned char,int,int);
// Original: arm9/main @ 0x020A8A34; symbol: func_020a8a34; size: 0x94.
void ZoneFeatures_UpdateTriggerMemberMaskOrRequestSync(unsigned char* p,int mode,unsigned int index,int value){if(mode==0){p[5]&=~(1<<index);p[7]=value;}else if(mode==1){p[5]|=1<<index;p[7]=value;}else if(mode==2){Network_GetConnectionManager(p);unsigned char v=Network_GetLocalMemberId();ZoneFeatures_QueueTriggerSynchronization(p[0],p[1],p[2],p[4],v,1,0);}}}
