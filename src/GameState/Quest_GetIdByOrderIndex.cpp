struct S{char pad[0xac];unsigned char values[204];};
// Original: arm9/main @ 0x020965AC; symbol: func_020965ac; size: 0x14.
extern "C" unsigned int Quest_GetIdByOrderIndex(S* p,unsigned int i){if(i<204)return p->values[i];return 255;}
