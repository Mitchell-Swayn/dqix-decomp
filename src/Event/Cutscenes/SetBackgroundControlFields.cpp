// Original: arm9/ov001 @ 0x02162678; symbol: func_ov001_02162678; size: 0x2C.
extern "C" void SetBackgroundControlFields(unsigned int priority,unsigned int characterBase,unsigned int screenBase,unsigned int size) { volatile unsigned short* control=(volatile unsigned short*)0x0400000e; *control=(unsigned short)((*control&0x43)|(priority<<14)|(characterBase<<7)|(screenBase<<8)|(size<<2)); }
