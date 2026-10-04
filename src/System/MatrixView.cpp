#include "System/Matrix.h"

void Mat4x3_WriteViewMatrix(const Vector3fix* eye, const Vector3fix* up, const Vector3fix* target, Matrix4x3* out)
{
    Vector3fix forward;
    Vector3fix right;
    Vector3fix vertical;
    forward.x = eye->x - target->x;
    forward.y = eye->y - target->y;
    forward.z = eye->z - target->z;
    Vector3fix_Normalize(&forward, &forward);
    Vector3fix_CrossProduct(up, &forward, &right);
    Vector3fix_Normalize(&right, &right);
    Vector3fix_CrossProduct(&forward, &right, &vertical);
    out->entries[0] = right.x;
    out->entries[1] = vertical.x;
    out->entries[2] = forward.x;
    out->entries[3] = right.y;
    out->entries[4] = vertical.y;
    out->entries[5] = forward.y;
    out->entries[6] = right.z;
    out->entries[7] = vertical.z;
    out->entries[8] = forward.z;
    out->translation.x = -Vector3fix_InnerProduct(eye, &right);
    out->translation.y = -Vector3fix_InnerProduct(eye, &vertical);
    out->translation.z = -Vector3fix_InnerProduct(eye, &forward);
}
