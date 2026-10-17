#pragma thumb off
#pragma optimization_level 2

// Original: arm9/main @ 0x0208036C; symbol: func_0208036c; size: 0xFC.
extern "C" char* TraverseDirectionalLinksWithStopFlags(void* owner,char* node,int direction,unsigned* flags,unsigned char latch){if(!node)return 0;char* next;switch(direction){case 0x40:while((next=*(char**)(node+0x1c))!=0){if(*(unsigned char*)(next+0x2a)&2)break;node=next;}break;case 0x80:while((next=*(char**)(node+0x18))!=0){if(*(unsigned char*)(next+0x2a)&2)break;node=next;}break;case 0x20:if(latch)*flags|=0x20;else while((next=*(char**)(node+0x24))!=0){if(*(unsigned char*)(next+0x2a)&2)break;node=next;}break;case 0x10:if(latch)*flags|=0x10;else while((next=*(char**)(node+0x20))!=0){if(*(unsigned char*)(next+0x2a)&2)break;node=next;}break;}return node;}
