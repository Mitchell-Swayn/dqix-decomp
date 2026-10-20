#include <globaldefs.h>
#include <World/Object3D.h>
ARM
struct IntegerParameterView { unsigned type; union { int integer; float real; } value; };
struct Node { unsigned type; unsigned* nested; };
struct ScriptParameterPair { IntegerParameterView index; Node output; };
struct SelectedObjectRecord { unsigned kind, unused1, unused2; Object3D* object; };
struct SelectedObjectTable { unsigned unknown; SelectedObjectRecord* records; };
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" SelectedObjectTable EventGetObjectSession_UnknownRoleZeroInitializedStorage;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" void Script_WriteIntegerReferenceOutput(Node*, unsigned);
// Original: arm9/ov001 @ 0x0215CCDC; symbol: func_ov001_0215ccdc; size: 0x74.
// Writes animation-running state for supported object kinds; missing supported objects leave output unchanged.
extern "C" int Script_WriteSelectedObjectAnimationRunning(ScriptParameterPair* parameters) {
    int index=Script_ReadParameterAsInteger(&parameters->index);
    unsigned kind=EventGetObjectSession_UnknownRoleZeroInitializedStorage.records[index].kind;
    if (kind==0 || kind==4 || kind==5 || kind==1 || kind==6) {
        Object3D* object=EventGetObjectSession_UnknownRoleZeroInitializedStorage.records[index].object;
        if (object) Script_WriteIntegerReferenceOutput(&parameters->output, !object->HasAnimationStopped());
    } else {
        Script_WriteIntegerReferenceOutput(&parameters->output, 1);
    }
    return 1;
}
