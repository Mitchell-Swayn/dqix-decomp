#include <globaldefs.h>
ARM
extern "C" {int Network_ResolveHostnameToBigEndianAddress(const char*,unsigned*);unsigned Network_ResolveHostWithScratchSocket(const char*);}
// Original: arm9/ov031 @ 0x02240FC8; symbol: ParseTemporarilyTerminatedAddress; size: 0x98.
// Temporarily terminates address substring, parses and byte swaps fallback resolver output.
extern "C" unsigned Http_ResolveRequestHostAddress(char* self){char* text=*(char**)(self+0x24);int length=*(int*)(self+12);signed char saved=text[length];text[length]=0;char* base=*(char**)(self+0x24);int skip=*(int*)(self+8)?8:7;unsigned parsed;unsigned address;if(Network_ResolveHostnameToBigEndianAddress(base+skip,&parsed)){address=parsed;}else{unsigned x=Network_ResolveHostWithScratchSocket(base+skip);if(!x)return 0;address=((x>>24)&255)|((x>>8)&0xff00)|((x<<8)&0xff0000)|((x<<24)&0xff000000);}(*(char**)(self+0x24))[*(int*)(self+12)]=saved;return address;}
