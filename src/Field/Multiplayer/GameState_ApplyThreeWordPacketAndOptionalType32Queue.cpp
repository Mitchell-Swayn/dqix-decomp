#include <globaldefs.h>
ARM
extern "C" void PartyTransition_QueueDialogueIfProtagonistReady(char *,int);
struct ThreeWordStatusPacket {
 unsigned unknown00,first,second,third;
 unsigned short halfword;
 unsigned char queue:1;unsigned char flag:1;unsigned char unknown12:6;
 signed char value;
};
// Original: arm9/ov017 @ 0x021CF448; symbol: func_ov017_021cf448; size: 0x68.
// Applies packet words, halfword and two flags to shared fields, then optionally queues a type-32 record.
extern "C" void GameState_ApplyThreeWordPacketAndOptionalType32Queue(void *unused,const ThreeWordStatusPacket *packet,unsigned char *state,char *queueOwner) {
 *(unsigned *)(state+0x7f7c)=packet->first;
 *(unsigned *)(state+0x7f80)=packet->second;
 *(unsigned *)(state+0x7f84)=packet->third;
 *(unsigned short *)(state+0x7f88)=packet->halfword;
 state[0x7f74]=packet->queue;
 state[0x7f75]=packet->flag;
 if(state[0x7f74])PartyTransition_QueueDialogueIfProtagonistReady(queueOwner,packet->value);
}
