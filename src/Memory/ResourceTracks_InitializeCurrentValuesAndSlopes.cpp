#include "Memory/SignedAllocator.h"
struct ResourceContext { void* allocator; unsigned unknown04; SignedAllocatorList triple0[3],triple1[3],triple2[3]; SignedAllocatorList single; SignedAllocatorList three[3]; SignedAllocatorList fourth; SignedAllocatorList pairs8[2],pairs16[2]; SignedAllocatorList twelve; SignedAllocatorList final[4]; SignedAllocatorList large; };
struct ResourcePoint { unsigned time; float value; };
struct ResourceVectorPoint { unsigned time; float values[3]; };
struct ResourceFour { unsigned char* values[4]; unsigned char counts[4]; };
struct ResourceTriples { unsigned char* values[3][3]; unsigned char counts[3][3]; };
struct ResourceSingle { unsigned char* values; unsigned char count; };
struct ResourceThreeAndOne { unsigned char* values[3]; unsigned char* fourth; unsigned char counts[3]; unsigned char fourthCount; };
struct ResourceTiming { unsigned char first,second,repeat,mode; };
struct LargeResource { void* nested; unsigned char* values; unsigned unknown08; unsigned short count; };
struct ResourceTrackState {
 unsigned unknown0,time,duration; unsigned char repeat,unknownD[0x1b]; void* boundResource; void* unknown2c; ResourceContext* context; unsigned unknown34; unsigned char mode,unknown39[0x13];
 float finalSlopes[4]; unsigned short finalIndices[4];
 float tripleSlopes[3][3]; unsigned short tripleIndices[3][3]; unsigned short unknown9a;
 float singleSlope; unsigned short singleIndex,unknowna2;
 float threeSlopes[3],vectorSlopes[3]; unsigned short threeIndices[3],fourthIndex;
 unsigned char unknownc4[0x54];
 float finalValues[4],tripleValues[3][3],singleValue; unsigned largeValue,delay; float threeValues[3],vectorValues[3];
};
extern "C" {
ResourceFour* Object_ReadOptionalResolvedValue(ResourceContext*);
ResourceTriples* ReadResolvedRecordWord4OrZero(ResourceContext*);
ResourceSingle* ReadResolvedRecordWordTwoOrZero(ResourceContext*);
ResourceThreeAndOne* Object_ReadOptionalResourceWordC(ResourceContext*);
ResourceTiming* ReadResolvedRecordWord10OrZero(ResourceContext*);
LargeResource* Object_ReadInitialOptionalResourceWord(ResourceContext*);
float Point_ComputeFloatingPointSlope(ResourcePoint**,ResourcePoint**);
}
// Original: arm9/main @ 0x02056D80; symbol: func_02056d80; size: 0x5B4.
extern "C" void ResourceTracks_InitializeCurrentValuesAndSlopes(ResourceTrackState* self) {
 if(!self->context || !self->boundResource)return;
 ResourceFour* four=Object_ReadOptionalResolvedValue(self->context);
 {
  ResourcePoint** first=(ResourcePoint**)self->context->final[0].ElementAfter(0);
  self->finalValues[0]=(*first)->value;
  if(four->counts[0]>1) {
   self->finalIndices[0]=1;
   ResourcePoint** next=(ResourcePoint**)self->context->pairs8[0].GetNthElement(1);
   if(next)self->finalSlopes[0]=Point_ComputeFloatingPointSlope(first,next);
  }
 }
 {
  ResourcePoint** first=(ResourcePoint**)self->context->final[1].ElementAfter(0);
  self->finalValues[1]=(*first)->value;
  if(four->counts[1]>1) {
   self->finalIndices[1]=1;
   ResourcePoint** next=(ResourcePoint**)self->context->pairs8[1].GetNthElement(1);
   if(next)self->finalSlopes[1]=Point_ComputeFloatingPointSlope(first,next);
  }
 }
 {
  ResourcePoint** first=(ResourcePoint**)self->context->final[2].ElementAfter(0);
  self->finalValues[2]=(*first)->value;
  if(four->counts[2]>1) {
   self->finalIndices[2]=1;
   ResourcePoint** next=(ResourcePoint**)self->context->pairs16[0].GetNthElement(1);
   if(next)self->finalSlopes[2]=Point_ComputeFloatingPointSlope(first,next);
  }
 }
 {
  ResourcePoint** first=(ResourcePoint**)self->context->final[3].ElementAfter(0);
  self->finalValues[3]=(*first)->value;
  if(four->counts[3]>1) {
   self->finalIndices[3]=1;
   ResourcePoint** next=(ResourcePoint**)self->context->pairs16[1].GetNthElement(1);
   if(next)self->finalSlopes[3]=Point_ComputeFloatingPointSlope(first,next);
  }
 }
 ResourceTriples* triples=ReadResolvedRecordWord4OrZero(self->context);
 for(int i=0;i<3;++i) {
  ResourcePoint** first=(ResourcePoint**)self->context->triple0[i].ElementAfter(0);
  self->tripleValues[0][i]=(*first)->value;
  if(triples->counts[0][i]>1) {
   self->tripleIndices[0][i]=1;
   ResourcePoint** next=(ResourcePoint**)self->context->triple0[i].GetNthElement(self->tripleIndices[0][i]);
   if(next)self->tripleSlopes[0][i]=Point_ComputeFloatingPointSlope(first,next);
  }
 }
 for(int i=0;i<3;++i) {
  ResourcePoint** first=(ResourcePoint**)self->context->triple1[i].ElementAfter(0);
  self->tripleValues[1][i]=(*first)->value;
  if(triples->counts[1][i]>1) {
   self->tripleIndices[1][i]=1;
   ResourcePoint** next=(ResourcePoint**)self->context->triple1[i].GetNthElement(self->tripleIndices[1][i]);
   if(next)self->tripleSlopes[1][i]=Point_ComputeFloatingPointSlope(first,next);
  }
 }
 for(int i=0;i<3;++i) {
  ResourcePoint** first=(ResourcePoint**)self->context->triple2[i].ElementAfter(0);
  self->tripleValues[2][i]=(*first)->value;
  if(triples->counts[2][i]>1) {
   self->tripleIndices[2][i]=1;
   ResourcePoint** next=(ResourcePoint**)self->context->triple2[i].GetNthElement(self->tripleIndices[2][i]);
   if(next)self->tripleSlopes[2][i]=Point_ComputeFloatingPointSlope(first,next);
  }
 }
 ResourceSingle* single=ReadResolvedRecordWordTwoOrZero(self->context);
 {
  ResourcePoint** first=(ResourcePoint**)self->context->single.ElementAfter(0);
  self->singleValue=(float)*(unsigned*)&(*first)->value;
  if(single->count>1) {
   self->singleIndex=1;
   ResourcePoint** next=(ResourcePoint**)self->context->single.GetNthElement(1);
   if(next)self->singleSlope=Point_ComputeFloatingPointSlope(first,next);
  }
 }
 ResourceThreeAndOne* three=Object_ReadOptionalResourceWordC(self->context);
 for(int i=0;i<3;++i) {
  ResourcePoint** first=(ResourcePoint**)self->context->three[i].ElementAfter(0);
  self->threeValues[i]=(*first)->value;
  if(three->counts[i]>1) {
   self->threeIndices[i]=1;
   ResourcePoint** next=(ResourcePoint**)self->context->three[i].GetNthElement(self->threeIndices[i]);
   if(next)self->threeSlopes[i]=Point_ComputeFloatingPointSlope(first,next);
  }
 }
 ResourceVectorPoint** first=(ResourceVectorPoint**)self->context->fourth.ElementAfter(0);
 self->vectorValues[0]=(*first)->values[0];
 self->vectorValues[1]=(*first)->values[1];
 self->vectorValues[2]=(*first)->values[2];
 if(three->fourthCount>1) {
  self->fourthIndex=1;
  ResourceVectorPoint** next=(ResourceVectorPoint**)self->context->fourth.GetNthElement(1);
  if(next) {
   {ResourceVectorPoint* a=*first; ResourceVectorPoint* b=*next; self->vectorSlopes[0]=(b->values[0]-a->values[0])/(float)(int)(b->time-a->time);}
   {ResourceVectorPoint* a=*first; ResourceVectorPoint* b=*next; self->vectorSlopes[1]=(b->values[1]-a->values[1])/(float)(int)(b->time-a->time);}
   {ResourceVectorPoint* a=*first; ResourceVectorPoint* b=*next; self->vectorSlopes[2]=(b->values[2]-a->values[2])/(float)(int)(b->time-a->time);}
  }
 }
 ResourceTiming* timing=ReadResolvedRecordWord10OrZero(self->context);
 self->time=0;
 self->duration=timing->first+timing->second;
 self->repeat=timing->repeat;
 self->mode=timing->mode;
 self->delay=timing->second;
 if(timing->repeat)self->repeat=1;
 if(Object_ReadInitialOptionalResourceWord(self->context)->count) {
  unsigned** first=(unsigned**)self->context->large.ElementAfter(0);
  self->largeValue=**first;
 }
}
