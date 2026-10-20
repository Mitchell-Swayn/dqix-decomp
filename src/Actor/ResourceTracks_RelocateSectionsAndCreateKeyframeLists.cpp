#pragma opt_propagation off
#include <globaldefs.h>
struct Relocated551 { void* header; int base; };
extern "C" {
int* ResourceTracks_GetResolvedResourceTable(Relocated551*);int* ResourceTracks_GetLargePayloadSection(Relocated551*);int* ResourceTracks_GetTripleScalarSection(Relocated551*);
int* ResourceTracks_GetSingleScalarSection(Relocated551*);int* ResourceTracks_GetScalarAndVectorSection(Relocated551*);int* ResourceTracks_GetPairedScalarSection(Relocated551*);
int* ResourceTracks_GetPairedVectorSection(Relocated551*);int* ResourceTracks_GetRandomizedAngleSection(Relocated551*);int* ResourceTracks_GetFourScalarSection(Relocated551*);void AllocateAndAppendResourcePayloadNodesAcrossLists(Relocated551*);
}
// Original: arm9/main @ 0x02055180; symbol: func_02055180; size: 0x22C.
extern "C" ARM int ResourceTracks_RelocateSectionsAndCreateKeyframeLists(Relocated551* s,void* header,void* base,void* required){
 if(!header)return 0;if(!base)return 0;if(!required)return 0;
 s->header=header;s->base=(int)base;
 volatile int* baseOffset=&s->base;
 int* p=ResourceTracks_GetResolvedResourceTable(s);if(!p)return 0;
 for(int i=0;i<9;i++){int base=*baseOffset;int value=p[i];p[i]=base+value;}
 p=ResourceTracks_GetLargePayloadSection(s);if(!p)return 0;{int base=*baseOffset;int value=p[0];p[0]=base+value;}{int base=*baseOffset;int value=p[1];p[1]=base+value;}
 p=ResourceTracks_GetTripleScalarSection(s);if(!p)return 0;
 for(int i=0;i<3;i++){int* q=p+i;int base=*baseOffset;int value=p[i];p[i]=base+value;base=*baseOffset;value=q[3];q[3]=base+value;base=*baseOffset;value=q[6];q[6]=base+value;}
 p=ResourceTracks_GetSingleScalarSection(s);if(!p)return 0;{int base=*baseOffset;int value=p[0];p[0]=base+value;}
 p=ResourceTracks_GetScalarAndVectorSection(s);if(!p)return 0;for(int i=0;i<4;i++){int base=*baseOffset;int value=p[i];p[i]=base+value;}
 p=ResourceTracks_GetPairedScalarSection(s);if(!p)return 0;for(int i=0;i<2;i++){int base=*baseOffset;int value=p[i];p[i]=base+value;}
 p=ResourceTracks_GetPairedVectorSection(s);if(!p)return 0;for(int i=0;i<2;i++){int base=*baseOffset;int value=p[i];p[i]=base+value;}
 p=ResourceTracks_GetRandomizedAngleSection(s);if(!p)return 0;{int base=*baseOffset;int value=p[1];p[1]=base+value;}
 p=ResourceTracks_GetFourScalarSection(s);if(!p)return 0;for(int i=0;i<4;i++){int base=*baseOffset;int value=p[i];p[i]=base+value;}
 AllocateAndAppendResourcePayloadNodesAcrossLists(s);return 1;
}
