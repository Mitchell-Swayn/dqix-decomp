#include <globaldefs.h>
#include <std_library_functions.h>
#include <System/Matrix.h>
ARM
#pragma always_inline on
struct IntegerParameterView;
struct FloatParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" float Script_ReadParameterAsFloat(FloatParameterView*);
extern "C" char* Event_GetObjectSession(int);
extern "C" void CutsceneCamera_QueueTargetPosition(void*, Vector3fix);
// Original data: arm9/ov001 @ 0x02165880; symbol: data_ov001_02165880.
// Opaque fallback storage, viewed only through non-owning object-representation bytes.
// Observed operation: one four-byte pointer read at offset 0x24; no logical extent is inferred.
// Owning-type recovery and migration of every translation-unit view remain required.
extern "C" char EventGetObjectSession_UnknownRoleZeroInitializedStorage[];
#pragma force_active on
// Original: arm9/ov001 @ 0x0215DED8; symbol: func_ov001_0215ded8; size: 0xec.
// Queues an object's position as the camera target, with optional fixed-point x/y/z offsets.
extern "C" int Script_QueueCameraTargetFromObjectPosition(char* parameters, int count) {
    char* first = parameters;
    parameters += 8;
    char* object = Event_GetObjectSession(Script_ReadParameterAsInteger((IntegerParameterView*)first));
    if (!object) return 0;
    Vector3fix target;
    memcpy(&target, object + 0x74, 12);
    if (count >= 2) {
        float offset = Script_ReadParameterAsFloat((FloatParameterView*)parameters);
        parameters += 8;
        target.x += (int)(4096.0f * offset);
    }
    if (count >= 3) {
        float offset = Script_ReadParameterAsFloat((FloatParameterView*)parameters);
        parameters += 8;
        target.y += (int)(4096.0f * offset);
    }
    if (count >= 4) target.z += (int)(4096.0f * Script_ReadParameterAsFloat((FloatParameterView*)parameters));
    CutsceneCamera_QueueTargetPosition(*(void**)(EventGetObjectSession_UnknownRoleZeroInitializedStorage + 0x24), target);
    return 1;
}
