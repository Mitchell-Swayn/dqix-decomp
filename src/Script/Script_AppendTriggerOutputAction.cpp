#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0206445C; symbol: func_0206445c; size: 0x34.
extern "C" void Script_AppendTriggerOutputAction(void*,unsigned char* entry,unsigned char* owner){*(void**)(entry+24)=0;unsigned char* node=*(unsigned char**)(owner+48);if(!node){*(void**)(owner+48)=entry;return;}unsigned char* next;while((next=*(unsigned char**)(node+24))!=0)node=next;*(void**)(node+24)=entry;}
