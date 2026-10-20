extern "C" char* ResourceTracks_GetResolvedResourceTable(char*);
// Original: arm9/main @ 0x020550D8; symbol: func_020550d8; size: 0x18.
extern "C" int ResourceTracks_GetScalarAndVectorSection(char* p){char* q=ResourceTracks_GetResolvedResourceTable(p);int v;if(q==0)v=0;else v=*(int*)(q+12);return v;}
