#include <globaldefs.h>
ARM
struct FloatParameterView;
extern "C" { float ReadScriptParameterAsFloat(FloatParameterView*); void System_QueueAppendFourWordRecord(void*,int,int,int); extern unsigned char* data_ov001_02165880[]; }
// Original: arm9/ov001 @ 0x0215D608; symbol: func_ov001_0215d608; size: 0x7C.
extern "C" int Resource_DispatchThreeFixedPointScriptValues(unsigned char* parameters) {
 int y;
 int x=(int)(4096.0f*ReadScriptParameterAsFloat((FloatParameterView*)parameters));
 y=(int)(4096.0f*ReadScriptParameterAsFloat((FloatParameterView*)(parameters+8)));
 int z=(int)(4096.0f*ReadScriptParameterAsFloat((FloatParameterView*)(parameters+16)));
 System_QueueAppendFourWordRecord(data_ov001_02165880[9],x,y,z);
 return 1;
}
