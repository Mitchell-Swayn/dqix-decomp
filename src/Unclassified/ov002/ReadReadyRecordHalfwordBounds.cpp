extern "C" char* FindReadyRecordByIdBeforeStopIndex(void*,int);
// Original: arm9/ov002 @ 0x02157030; symbol: func_ov002_02157030; size: 0x4C.
extern "C" void ReadReadyRecordHalfwordBounds(char* p,int id,short* a,short* b,short* c,short* d) {
    char* q=FindReadyRecordByIdBeforeStopIndex(p+0xec8,id);
    if(!q)return;
    *a=*(short*)(q+0xac);
    *b=*(short*)(q+0xae);
    *c=*(short*)(q+0xa8);
    *d=*(short*)(q+0xaa);
}
