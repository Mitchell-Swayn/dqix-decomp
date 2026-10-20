#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020CEE54; symbol: func_020cee54; size: 0x14.
extern "C" void LinkedList_PushFrontUsingWordTwoLink(unsigned** root,unsigned* entry){if(root){entry[2]=(unsigned)*root;*root=entry;}}
