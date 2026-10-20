#include <globaldefs.h>
ARM
extern "C" void Runtime_RunEarlyExitHandlerAndTerminate(int);
// Original: arm9/ov017 @ 0x021D4980; symbol: func_ov017_021d4980; size: 0x2C.
// Reads an integer/index from a two-word tagged value; nonzero tags terminate with -1.
// The termination path has no established return value if the runtime hook returns.
struct TaggedWord {int tag,value;};
extern "C" int RequireZeroTagAndReadInteger(TaggedWord word,void* context) {
 if(word.tag)Runtime_RunEarlyExitHandlerAndTerminate(-1);
 else return word.value;
}
