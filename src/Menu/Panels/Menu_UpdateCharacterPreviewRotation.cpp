#include <globaldefs.h>
typedef unsigned short ushort;
ARM
struct Offset50VectorWords { union { struct { int x, y, z; }; int values[3]; }; };
extern "C" void *Menu_GetCharacterPreviewBaseModel(void *object);
extern "C" void Object3D_ReadRotationVector(Offset50VectorWords* out, char* p);
int fix32ReduceAngle0To2Pi(int);
extern "C" void Ov023_InitializeFourEmbeddedFields(char *object, unsigned int value);
extern "C" void CharacterPreview_SetBodyRotation(void *obj, unsigned value);
extern "C" int Menu_HitTestEnabledLayoutGroups(char*self);
extern "C" bool Input_TestKeyMask(ushort *param_1, ushort param_2);
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage;
static inline int Absolute(int n){return n<0?-n:n;}
struct Owner {char pad[0x128];char* model;char pad12c[0x508];unsigned short flags;};
// Original: arm9/ov023 @ 0x021E463C; symbol: func_ov023_021e463c; size: 0x368.
// Applies left/right yaw from layout hit-tests or key masks, and eases simultaneous input toward fixed angle 491.
extern "C" void Menu_UpdateCharacterPreviewRotation(Owner* self, unsigned frames)
{
    Offset50VectorWords auto_rot;
    Offset50VectorWords input_rot;
    Offset50VectorWords auto_src;
    Offset50VectorWords input_src;
    ((void(*)(void*))Menu_GetCharacterPreviewBaseModel)(self->model);
    if (self->flags & 2) {
        bool done = false;
        Object3D_ReadRotationVector(&auto_src, self->model);
        auto_rot = auto_src;
        int old = auto_rot.y;
        int difference = fix32ReduceAngle0To2Pi(491 - old);
        int angle;
        if (difference >= 0 && difference < 0x3244) {
            angle = old + difference / 12;
            for (unsigned i = 0; i < frames - 1; i++)
                angle += fix32ReduceAngle0To2Pi(491 - angle) / 12;
        } else if (difference >= 0x3244 && difference < 0x6488) {
            angle = old - (0x6488 - difference) / 12;
            for (unsigned i = 0; i < frames - 1; i++)
                angle -= (0x6488 - fix32ReduceAngle0To2Pi(491 - angle)) / 12;
        }
        Ov023_InitializeFourEmbeddedFields(self->model, (unsigned)fix32ReduceAngle0To2Pi(angle));
        difference = fix32ReduceAngle0To2Pi(491 - angle);
        if (Absolute(difference) < 40)
            done = true;
        else if (Absolute(0x6488 - difference) < 40)
            done = true;
        if (done) {
            Ov023_InitializeFourEmbeddedFields(self->model, (unsigned)fix32ReduceAngle0To2Pi(491));
            self->flags &= ~2;
        }
    } else if (self->flags & 1) {
        bool left = false, right = false, handled = false;
        if (Main_UnknownRoleZeroInitializedStorage_Variant4[0x55]) {
            int key = Menu_HitTestEnabledLayoutGroups((char*)self + 0xd4);
            if (key == 34) left = true;
            if (key == 35) right = true;
            handled = true;
        } else if (Main_UnknownRoleZeroInitializedStorage_Variant4[0x5f] &&
                   *(unsigned short*)(Main_UnknownRoleZeroInitializedStorage_Variant4 + 0x24)) {
            if (self->flags & 0x100) left = true;
            if (self->flags & 0x200) right = true;
            handled = true;
        } else if (Main_UnknownRoleZeroInitializedStorage_Variant4[0x54]) {
            handled = true;
        }
        if (!handled) {
            if (Input_TestKeyMask(&KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 0x200))
                left = true;
            if (Input_TestKeyMask(&KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 0x100))
                right = true;
        }
        if (left && right)
            self->flags |= 2;
        else if (left || right) {
            Object3D_ReadRotationVector(&input_src, self->model);
            input_rot = input_src;
            if (left)
                input_rot.y += (int)(4096.0f * (0.08f * (float)frames));
            if (right)
                input_rot.y -= (int)(4096.0f * (0.08f * (float)frames));
            input_rot.y = fix32ReduceAngle0To2Pi(input_rot.y);
            CharacterPreview_SetBodyRotation(self->model, (unsigned)&input_rot);
        }
        if (left)
            self->flags |= 0x100;
        else
            self->flags &= ~0x100;
        if (right)
            self->flags |= 0x200;
        else
            self->flags &= ~0x200;
    }
}
