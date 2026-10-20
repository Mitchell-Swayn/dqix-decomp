#include <globaldefs.h>
ARM
struct IntegerParameterView;struct Node;
extern "C" int GameState_CopyCollectionFlagBitset(void*);
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" void Script_WriteIntegerReferenceOutput(Node*,unsigned);
// Original: arm9/ov023 @ 0x021E9190; symbol: func_ov023_021e9190; size: 0x78.
// Tests the script-selected bit in the sixty-byte flag snapshot and writes a Boolean output.
extern "C" int Script_WriteSelectedGameFlagToOutput(char* parameters) {
 unsigned flags[15];
 GameState_CopyCollectionFlagBitset(flags);
 int result=0;
 int bit=Script_ReadParameterAsInteger((IntegerParameterView*)parameters);
 if(flags[bit/32] & (1u<<(bit%32)))result=1;
 if(result)Script_WriteIntegerReferenceOutput((Node*)(parameters+8),1);
 else Script_WriteIntegerReferenceOutput((Node*)(parameters+8),0);
 return 1;
}
