#include <globaldefs.h>
ARM
extern "C" int Util_PopFrontThreeHalfwordRecord(unsigned char*,unsigned short*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void Combat_InitializeCommandRecord(unsigned char*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" int InitializeZeroedRecordWithInvalidHalfword(void*);
extern "C" void Memory_Initialize32ByteRecordWithSentinels(void*);

#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov025 @ 0x021DEE20; symbol: Combat_AllocateLinkedCommandFromThreeHalfwordQueueRecord; size: 0x104.
extern "C" void Combat_AllocateLinkedCommandFromThreeHalfwordQueueRecord(char* self){unsigned short input[3];if(!Util_PopFrontThreeHalfwordRecord((unsigned char*)self,input))return;char* command=_ZN13SafeAllocator8AllocateEj((unsigned)(self+48),40);if(!command)return;Combat_InitializeCommandRecord((unsigned char*)command);H(command,0)=input[1];char* object=_ZN9GameState19GetCombatantByIndexEi(_ZN9GameState11GetInstanceEv(),input[0]);if(!object)return;B(command,8)=1;char* first=P(command,16)=_ZN13SafeAllocator8AllocateEj((unsigned)(self+48),52);if(!first)return;InitializeZeroedRecordWithInvalidHalfword(first);W(first,48)=0;H(P(command,16),32)=input[0];H(P(command,16),34)=H(P(object,0x138),0);H(P(command,16),36)=H(P(object,0x138),2);B(command,9)=1;char* second=P(command,20)=_ZN13SafeAllocator8AllocateEj((unsigned)(self+48),36);if(!second)return;Memory_Initialize32ByteRecordWithSentinels(second);W(second,32)=0;H(P(command,20),14)=input[0];H(command,24)=input[2];B(command,11)|=4;P(self,0x770c)=command;}