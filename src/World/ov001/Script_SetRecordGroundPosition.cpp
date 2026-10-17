#include <globaldefs.h>
ARM
#include <Graphics/Vector.h>
struct IntegerParameterView; struct FloatParameterView; class Zone3D;
extern "C" void* ReadGlobalValueAt020FB3F0();
extern "C" int Zone3D_FindGroundHeightBelowPosition(Zone3D* zone,const Vector3i* input);
extern "C" void Pool_InitializeNodeFromThreeValues(char *, Vector3i);
extern "C" char* GetBounded1416ByteRecord(int i);
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView* parameter);
extern "C" float ReadScriptParameterAsFloat(FloatParameterView* parameter);
// Original: arm9/ov001 @ 0x0215C900; symbol: func_ov001_0215c900; size: 0x94.
extern "C" int Script_SetRecordGroundPosition(char *params) {
    int id = ReadScriptParameterAsInteger((IntegerParameterView *)params);
    Vector3i position;
    position.x = (int)(4096.0f * ReadScriptParameterAsFloat((FloatParameterView *)(params + 8)));
    position.z = (int)(4096.0f * ReadScriptParameterAsFloat((FloatParameterView *)(params + 16)));
    position.y = 0xa000;
    position.y = Zone3D_FindGroundHeightBelowPosition((Zone3D *)ReadGlobalValueAt020FB3F0(), &position);
    char *record = GetBounded1416ByteRecord(id);
    int result;
    if (!record) result = 0;
    else { Pool_InitializeNodeFromThreeValues(record, position); result = 1; }
    return result;
}
