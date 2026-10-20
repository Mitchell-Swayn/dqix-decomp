struct Record {
    unsigned char first;
    unsigned char pad;
    unsigned short middle;
    unsigned char last;
};
// Original: arm9/ov002 @ 0x02153E90; symbol: func_ov002_02153e90; size: 0x14.
extern "C" void PartyMenu_ClearTargetActionResult(Record* p) {
    p->first=0;
    p->middle=0;
    p->last=0;
}
