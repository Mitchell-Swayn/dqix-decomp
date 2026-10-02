#include "System/Matrix.h"
#include "Graphics/NSBXX/GeometryFifo.h"
#include "Graphics/NSBXX/RenderConfig.h"

struct SelectorMatrixState {
    unsigned char unknown00[8];
    unsigned int flags;
};

extern "C" {
int func_ov015_0218bc9c(SelectorMatrixState*);
extern unsigned char data_ov015_02193fe0[];
extern Matrix4x3* data_ov015_02194564[3];
extern Matrix4x3 data_ov015_02194570;
extern Matrix4x3 data_ov015_021945a0;
extern Matrix4x3 data_ov015_021945d0;

void func_ov015_0218bb3c(SelectorMatrixState* state)
{
    if (!(state->flags & 0x10)) return;
    if (data_ov015_02193fe0[1] == func_ov015_0218bc9c(state)) {
        if (data_ov015_02194564[2]) {
            GetCurrentPositionAndDirectionMatrices(data_ov015_02194564[2], 0);
            data_ov015_02194570 = *data_ov015_02194564[2];
            const Matrix4x3* inverse = RenderConfig::GetInverseViewMatrix();
            Mat4x3_Multiply(data_ov015_02194564[2], inverse, data_ov015_02194564[2]);
        }
    }
    if (data_ov015_02193fe0[2] == func_ov015_0218bc9c(state)) {
        if (data_ov015_02194564[0]) {
            GetCurrentPositionAndDirectionMatrices(data_ov015_02194564[0], 0);
            data_ov015_021945a0 = *data_ov015_02194564[0];
            const Matrix4x3* inverse = RenderConfig::GetInverseViewMatrix();
            Mat4x3_Multiply(data_ov015_02194564[0], inverse, data_ov015_02194564[0]);
        }
    }
    if (data_ov015_02193fe0[0] == func_ov015_0218bc9c(state)) {
        if (data_ov015_02194564[1]) {
            GetCurrentPositionAndDirectionMatrices(data_ov015_02194564[1], 0);
            data_ov015_021945d0 = *data_ov015_02194564[1];
            const Matrix4x3* inverse = RenderConfig::GetInverseViewMatrix();
            Mat4x3_Multiply(data_ov015_02194564[1], inverse, data_ov015_02194564[1]);
        }
    }
}
}
