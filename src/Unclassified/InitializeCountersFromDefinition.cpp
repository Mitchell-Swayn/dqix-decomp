#include <globaldefs.h>
#include <Util/Random.h>
struct PackedCounters { unsigned first:10, second:10, third:10, reserved:2; };
struct CounterState { unsigned short current, secondary, initial, initialSecondary, limitA, limitB, limitC, pad; PackedCounters counters; unsigned char rest[42]; };
struct CounterDefinition { unsigned char pad[48]; unsigned short initial, secondary, limitA, limitB, limitC, unused; PackedCounters counters; unsigned char bytes[24]; };
extern "C" void Object_InitializePackedCountersWeightsAndTimers(unsigned short*);
extern "C" void CopyBytesAndTwoScalarFields(void*,const void*);
// Original: arm9/main @ 0x02089630; symbol: func_02089630; size: 0x128.
// Initialize counters from a definition, optionally varying the initial count by 80–100%.
extern "C" void InitializeCountersFromDefinition(CounterState* state, const CounterDefinition* definition, int exactInitial) {
 Object_InitializePackedCountersWeightsAndTimers((unsigned short*)state);
 Random* random=GetBTRandom();
 if(exactInitial) state->current=state->initial=definition->initial;
 else { unsigned initial=definition->initial; float factor=NextRandomFloatBetween(random,0.8f,1.0f); state->initial=(unsigned)(0.5f+initial*factor); state->current=state->initial; }
 state->secondary=state->initialSecondary=definition->secondary;
 state->limitC=definition->limitC;
 state->limitA=definition->limitA;
 state->limitB=definition->limitB;
 state->counters.first=(unsigned short)definition->counters.first;
 state->counters.second=(unsigned short)definition->counters.second;
 state->counters.third=(unsigned short)definition->counters.third;
 CopyBytesAndTwoScalarFields((unsigned char*)state+62,definition->bytes);
}
