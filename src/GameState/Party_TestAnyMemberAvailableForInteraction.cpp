#include <globaldefs.h>
extern "C" int ReadAvailableMemberValueRelativeToProtagonist(unsigned char, unsigned int, unsigned int, unsigned int);
// Original: arm9/main @ 0x020DCBBC; symbol: func_020dcbbc; size: 0x64.
extern "C" int Party_TestAnyMemberAvailableForInteraction(const unsigned char *items, int count, unsigned int arg3, unsigned int arg4, unsigned int arg5) {
 int result = 0;
 int index = 0;
 unsigned int duplicate = arg4;
 for (; index < count; index = (index + 1) * 0x1000000 >> 0x18) {
  int current = ReadAvailableMemberValueRelativeToProtagonist(items[index], arg3, arg4, arg5);
  result = (result | current) != 0;
 }
 return result;
}
