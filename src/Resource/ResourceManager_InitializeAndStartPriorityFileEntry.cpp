#include <globaldefs.h>
#include <Memory/SignedAllocator.h>
#include <System/ProcessorContext.h>
ARM
struct Flags {unsigned bit0:1,bit1:1,bit2:1,bit3:1,bit4:1,bit5:1,bit6:1,rest:25;};
struct Entry {unsigned char pad[0x110];struct EntryFlags {signed active:1;unsigned other:31;} flags;unsigned char pad2[0x18];int available;unsigned char pad3[0x1c];void* owner;int priority;unsigned char pad4[0x20];};
struct Handle {Entry* entry;};
struct State {unsigned rangeValue,rangeFirst,rangeZero,rangeLast;unsigned char callbackPrefix[0x154];int (*open)(void*,void*);int (*ready)(void*);void (*read)(void*,void*,int,int);void (*close)(void*);};
struct Object {char pad[0x120];unsigned counter;};
extern "C" Entry* ResourceManager_ClaimIndexedPriorityEntry(Handle*,int,int);
extern "C" void SoundStream_SelectFileOrMemoryBackend(State*,unsigned);
extern "C" void SoundStream_ReleasePlayerHandleAndPlaybackState(char*);
extern "C" void NNSi_SndFaderInit(unsigned*);
extern "C" void NNSi_SndFaderSet(State*,unsigned,unsigned);
extern "C" int SoundStream_RetainPlayerChannels(unsigned char*,int,const unsigned char*);
extern "C" unsigned _u32_div_f(unsigned,unsigned);
extern "C" int NNS_SndStrmSetup(void*,unsigned,unsigned char*,unsigned,unsigned,unsigned,unsigned,unsigned);
extern "C" void ResourceJob_DecrementCounterAndCompleteAtZero(Object*);
extern "C" void NNS_SndStrmSetChannelPan(char*,int,unsigned);
extern "C" void ResourceBuffer_ReplaceOldestOwnerRequestAndEnqueue(int,int,void**,unsigned,int,void*);
// Original: arm9/main @ 0x020BEED8; symbol: func_020beed8; size: 0x270.
// Claims a priority file entry, initializes ranges and channels, and unwinds failures.
extern "C" int ResourceManager_InitializeAndStartPriorityFileEntry(Handle* manager,unsigned char* description,int index,int priority,unsigned field144,unsigned milliseconds,unsigned field134,unsigned field138,unsigned field13c,unsigned field140) {
 Entry* claimed=ResourceManager_ClaimIndexedPriorityEntry(manager,index,priority);
 char* job=(char*)claimed;
 if(!job) return 0;
 SoundStream_SelectFileOrMemoryBackend((State*)job,*(unsigned*)description);
 if(!(*(int(**)(char*,unsigned))(job+0x164))(job,*(unsigned*)description)) {SoundStream_ReleasePlayerHandleAndPlaybackState(job);return 0;}
 *(unsigned*)(job+0x160)=(unsigned)(((unsigned long long)*(unsigned short*)(job+0xc4)*milliseconds)/1000);
 Flags* flags=(Flags*)(job+0x110);
 if(*(unsigned*)(job+0x160) && *(unsigned char*)(job+0xc0)==2) flags->bit4=1;else flags->bit4=0;
 *(unsigned*)(job+0x114)=4;flags->bit5=0;flags->bit1=0;
 *(unsigned*)(job+0x118)=0;flags->bit2=0;flags->bit3=0;
 *(unsigned*)(job+0x11c)=0;
 *(unsigned*)(job+0x134)=field134;*(unsigned*)(job+0x138)=field138;*(unsigned*)(job+0x13c)=field13c;*(unsigned*)(job+0x140)=field140;*(unsigned*)(job+0x144)=field144;
 *(unsigned*)(job+0x15c)=0;*(unsigned*)(job+0x154)=description[4];*(unsigned*)(job+0x158)=127;
 NNSi_SndFaderInit((unsigned*)(job+0xe8));
 NNSi_SndFaderSet((State*)(job+0xe8),0x7f00,1);
 int format;switch(*(unsigned char*)(job+0xc0)){case 0:format=0;break;case 1:case 2:format=1;break;}
 int count=*(unsigned char*)(job+0xc2);if(description[7]&1)count=2;if(count>*(unsigned char*)(job+0x124))count=*(unsigned char*)(job+0x124);
 flags->bit6=(count==1);
 if(!SoundStream_RetainPlayerChannels((unsigned char*)job,count,(unsigned char*)(job+0x126))){(*(void(**)(char*))(job+0x168))(job);SoundStream_ReleasePlayerHandleAndPlaybackState(job);return 0;}
 unsigned length=_u32_div_f(*(unsigned*)(job+0x130)*count,*(unsigned char*)(job+0x124));
 if(!NNS_SndStrmSetup(job,format,*(unsigned char**)(job+0x12c),length,*(unsigned short*)(job+0xc6),4,(unsigned)ResourceBuffer_ReplaceOldestOwnerRequestAndEnqueue,(unsigned)job)){
  ResourceJob_DecrementCounterAndCompleteAtZero((Object*)job);
  (*(void(**)(char*))(job+0x168))(job);SoundStream_ReleasePlayerHandleAndPlaybackState(job);return 0;
 }
 if(count==2){NNS_SndStrmSetChannelPan(job,0,0);NNS_SndStrmSetChannelPan(job,1,127);}
 return 1;
}
