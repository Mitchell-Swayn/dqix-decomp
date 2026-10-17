#pragma thumb off
#pragma optimization_level 3
#pragma optimize_for_size on
#pragma optimize_for_size off
namespace Script { class Parameter { public:int ToInt() const; }; }
extern "C" {void Object_AllocateFortyFourByteEntriesAndInvalidateKeys(void*,void*,unsigned);extern void* data_02108da8[2];}
// Original: arm9/main @ 0x0207236C; symbol: func_0207236c; size: 0x2C.
extern "C" int Script_ConvertParameterToHalfwordAndDispatch(const Script::Parameter* value){int count=value->ToInt();count&=0xffff;Object_AllocateFortyFourByteEntriesAndInvalidateKeys(data_02108da8[1],data_02108da8[0],count);return 1;}
