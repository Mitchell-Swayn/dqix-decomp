#include <globaldefs.h>
ARM
#pragma optimization_level 4
struct Owner {char unknown[0x24]; signed int active:1;};
struct State;
struct Entry {unsigned char* data;unsigned reserved;};
struct ChannelOwner {char pad[0x20];unsigned format; signed int active:1;unsigned flags:31;unsigned total,period,field30,field34,position,field3c;int slot;unsigned field44;int count;unsigned char indices[1];};
extern "C" Entry NNSSndStrmSetup_UnknownRoleZeroInitializedStorage_Variant2[];
extern "C" unsigned char NNSSndStrmSetup_UnknownRoleZeroInitializedStorage[];
extern "C" void SoundStream_RefillBufferOnAlarm(void* p);
extern "C" void ResourceEntry_UpdateIfActive(Owner* object);
extern "C" unsigned _u32_div_f(unsigned,unsigned);
extern "C" int Sound_AllocateStreamAlarmSlot();
extern "C" void SoundCommand_SubmitPackedPcmChannelSetup(unsigned a,unsigned b,unsigned c,unsigned d,unsigned e,unsigned f,unsigned g,unsigned h,unsigned i,unsigned j);
extern "C" void SoundCommand_SubmitOpcodeEighteenWithResolvedValue(unsigned a,unsigned b,unsigned c,unsigned d,unsigned e);
extern "C" void _ZN19SignedAllocatorList11InsertAtEndEP21SignedAllocatorHeader(void*,void*);
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" void SoundStream_DispatchNextBufferSlice(State* p,void* argument);
// Original: arm9/main @ 0x020BC9D0; symbol: NNS_SndStrmSetup; size: 0x1A0.
// Reserves a command slot, initializes channel slices, and primes ring-buffer dispatch.
extern "C" int NNS_SndStrmSetup(ChannelOwner* owner,unsigned format,unsigned char* buffer,unsigned size,unsigned rate,unsigned period,unsigned field30,unsigned field34) {
 if(owner->active) ResourceEntry_UpdateIfActive((Owner*)owner);
 unsigned quotient=_u32_div_f(size,owner->count*(period<<5));
 owner->total=(quotient*period)<<5;
 unsigned amount=owner->total;
 if(format==1) amount>>=1;
 unsigned interval=_u32_div_f(rate*amount,period);
 if((owner->slot=Sound_AllocateStreamAlarmSlot())<0) return 0;
 int i=0;
 if(owner->count>0) do {
  unsigned channel=owner->indices[i];
  NNSSndStrmSetup_UnknownRoleZeroInitializedStorage_Variant2[channel].data=buffer+owner->total*i;
  NNSSndStrmSetup_UnknownRoleZeroInitializedStorage_Variant2[channel].reserved=0;
  SoundCommand_SubmitPackedPcmChannelSetup(channel,format,(unsigned)NNSSndStrmSetup_UnknownRoleZeroInitializedStorage_Variant2[channel].data,1,0,owner->total>>2,127,0,rate<<5,64);
  ++i;
 } while(i<owner->count);
 SoundCommand_SubmitOpcodeEighteenWithResolvedValue(owner->slot,interval,interval,(unsigned)SoundStream_RefillBufferOnAlarm,(unsigned)owner);
 _ZN19SignedAllocatorList11InsertAtEndEP21SignedAllocatorHeader(NNSSndStrmSetup_UnknownRoleZeroInitializedStorage,owner);
 owner->format=format;
 owner->period=period;
 owner->field30=field30;
 owner->field34=field34;
 owner->position=0;
 owner->field3c=0;
 owner->active=1;
 int irq=_Z20DisableIRQInterruptsv();
 owner->period=1;
 SoundStream_DispatchNextBufferSlice((State*)owner,0);
 owner->period=period;
 _Z20SetIRQInterruptStatei(irq);
 return 1;
}
