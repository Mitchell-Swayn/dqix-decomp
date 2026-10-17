// Original ARM fields and widths reviewed.
struct Flags{unsigned int value:12;unsigned int rest:20;};
// Original: arm9/main @ 0x0204A040; symbol: func_0204a040; size: 0x14.
extern "C" unsigned int ReadLinkedByteField6COrReturnFF(char* p){char* q=*(char**)(p+0x13c);if(q)return (unsigned char)q[0x6c];return 255;}
