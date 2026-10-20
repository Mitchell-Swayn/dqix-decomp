struct F{char pad[0x56b];unsigned char bits:4;unsigned char rest:4;};
// Original: arm9/main @ 0x02061BD8; symbol: func_02061bd8; size: 0x2C.
extern "C" int GameObject_HasLinkedStatusNibble(char* p){F* q=*(F**)(p+0x150);if(!q)return 0;return q->bits!=0;}
