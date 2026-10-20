#include <globaldefs.h>
ARM
#include <Graphics/Vector.h>
struct IntegerParameterView; struct FloatParameterView; class Zone3D;
extern "C" void* Zone3D_GetMainInstance();
extern "C" int Zone3D_FindGroundHeightBelowPosition(Zone3D* zone,const Vector3i* input);
extern "C" void Pool_InitializeNodeFromThreeValues(char *, Vector3i);
extern "C" char* Event_GetObjectSession(int i);
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView* parameter);
extern "C" float Script_ReadParameterAsFloat(FloatParameterView* parameter);
// Original: arm9/ov001 @ 0x0215C900; symbol: func_ov001_0215c900; size: 0x94.
extern "C" int Script_SetRecordGroundPosition(char *params) {
    int id = Script_ReadParameterAsInteger((IntegerParameterView *)params);
    Vector3i position;
    position.x = (int)(4096.0f * Script_ReadParameterAsFloat((FloatParameterView *)(params + 8)));
    position.z = (int)(4096.0f * Script_ReadParameterAsFloat((FloatParameterView *)(params + 16)));
    position.y = 0xa000;
    position.y = Zone3D_FindGroundHeightBelowPosition((Zone3D *)Zone3D_GetMainInstance(), &position);
    char *record = Event_GetObjectSession(id);
    int result;
    if (!record) result = 0;
    else { Pool_InitializeNodeFromThreeValues(record, position); result = 1; }
    return result;
}
