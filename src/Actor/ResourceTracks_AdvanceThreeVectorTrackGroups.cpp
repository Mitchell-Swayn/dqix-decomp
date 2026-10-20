#pragma thumb off
#include "Memory/SignedAllocator.h"
struct Point { int x;float y; };
extern "C" int ResourceTracks_GetTripleScalarSection(char*);
extern "C" float Point_ComputeFloatingPointSlope(Point**,Point**);
struct Record {char pad[0x24];unsigned char first[3],second[3],third[3];};
struct TrackData { char header[8]; SignedAllocatorList first[3],second[3],third[3]; };
struct State { unsigned pad0;unsigned frame;char pad8[0x28];TrackData* tracks;char pad34[0x30];float first[3],second[3],third[3];unsigned short firstIndex[3],secondIndex[3],thirdIndex[3]; };
// Original: arm9/main @ 0x020559CC; symbol: ResourceTracks_AdvanceThreeVectorTrackGroups; size: 0x264.
extern "C" void ResourceTracks_AdvanceThreeVectorTrackGroups(State* state) {
 Record* record=(Record*)ResourceTracks_GetTripleScalarSection((char*)state->tracks);
 for(int i=0;i<3;i++) {
  if(record->first[i]>1 && record->first[i]>state->firstIndex[i]) {
   Point** point=(Point**)state->tracks->first[i].GetNthElement(state->firstIndex[i]);
   if(point && (unsigned)(*point)->x<state->frame) {
    state->firstIndex[i]++;
    if(state->firstIndex[i]>=record->first[i]) state->first[i]=0;
    else { Point** next=(Point**)state->tracks->first[i].GetNthElement(state->firstIndex[i]);
     if(next) state->first[i]=Point_ComputeFloatingPointSlope(point,next);
    }
   }
  }
 }
 for(int i=0;i<3;i++) {
  if(record->second[i]>1 && record->second[i]>state->secondIndex[i]) {
   Point** point=(Point**)state->tracks->second[i].GetNthElement(state->secondIndex[i]);
   if(point && (unsigned)(*point)->x<state->frame) {
    state->secondIndex[i]++;
    if(state->secondIndex[i]>=record->second[i]) state->second[i]=0;
    else { Point** next=(Point**)state->tracks->second[i].GetNthElement(state->secondIndex[i]);
     if(next) state->second[i]=Point_ComputeFloatingPointSlope(point,next);
    }
   }
  }
 }
 for(int i=0;i<3;i++) {
  if(record->third[i]>1 && record->third[i]>state->thirdIndex[i]) {
   Point** point=(Point**)state->tracks->third[i].GetNthElement(state->thirdIndex[i]);
   if(point && (unsigned)(*point)->x<state->frame) {
    state->thirdIndex[i]++;
    if(state->thirdIndex[i]>=record->third[i]) state->third[i]=0;
    else { Point** next=(Point**)state->tracks->third[i].GetNthElement(state->thirdIndex[i]);
     if(next) state->third[i]=Point_ComputeFloatingPointSlope(point,next);
    }
   }
  }
 }
}
