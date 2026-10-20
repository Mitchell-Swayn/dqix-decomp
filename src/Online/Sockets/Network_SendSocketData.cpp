#include <globaldefs.h>
ARM
extern "C" int Network_SendAvailableChunksWithOptionalWaitForAll(...);
extern "C" int _Z11UnlockMutexP5Mutex(...);
extern "C" int _Z12TryLockMutexP5Mutex(...);
extern "C" int _Z9LockMutexP5Mutex(...);
extern "C" int Network_IsSocketHandleInvalid(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov031 @ 0x02206150; symbol: ValidateSocketAndSendChunksUnderOptionalMutexWait.
extern "C" int Network_SendSocketData(char*self,char*source,int size,unsigned short port,unsigned address,unsigned flags){
if(Network_IsSocketHandleInvalid())return -28;struct Socket{char pad[112];short flags;inline bool Valid(){bool result=false;if(this&&(flags&1))result=true;return result;}inline short Flags(){return *(volatile short*)&flags;}};int valid=0;if(self)valid=(((Socket*)self)->Flags()&1)!=0;if(!valid)return -39;int mode=*(signed char*)(self+115);int restricted=1;if(mode!=0&&mode!=4)restricted=0;if(restricted){if(!(((Socket*)self)->Flags()&4)||(((Socket*)self)->Flags()&8))return -56;}char*owner=P(self,104);unsigned wait;if((flags&4)||!*(signed char*)(self+114)){if(!_Z12TryLockMutexP5Mutex(owner+224))return -6;wait=0;}else{_Z9LockMutexP5Mutex(owner+224);wait=1;}int result=Network_SendAvailableChunksWithOptionalWaitForAll(self,source,size,port,address,wait);_Z11UnlockMutexP5Mutex(owner+224);return result;
}
