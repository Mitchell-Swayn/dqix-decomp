#include <globaldefs.h>
ARM
typedef int fx32;
typedef long long fx64;
#define FX32_INT_SHIFT 12
struct Mtx43 { int _[12]; };
extern "C" void fix32_QueueComputeReciprocal(int);
extern "C" int fix32_GetDivisionResult();
extern "C" void MI_Copy48B(const void*,void*);
// Original: arm9/main @ 0x020C19D4; symbol: Mat4x3_Invert; size: 0x38C.
extern "C" int Mat4x3_Invert(const struct Mtx43 *mtx, struct Mtx43 *inv){
    struct Mtx43 tempmat;
    struct Mtx43 *dst;
    fx32 det0, det1, det2, det;
    fx32 var0, var1, var2, var3;
    if (mtx == inv)
        dst = &tempmat;
    else
        dst = inv;
    //subdeterminants
    det0 = (fx32)(((fx64)mtx->_[4] * mtx->_[8] - (fx64)mtx->_[5] * mtx->_[7] + (fx64)(1 << (FX32_INT_SHIFT - 1))) >> FX32_INT_SHIFT);
    det1 = (fx32)(((fx64)mtx->_[3] * mtx->_[8] - (fx64)mtx->_[5] * mtx->_[6] + (fx64)(1 << (FX32_INT_SHIFT - 1))) >> FX32_INT_SHIFT);
    det2 = (fx32)(((fx64)mtx->_[3] * mtx->_[7] - (fx64)mtx->_[4] * mtx->_[6] + (fx64)(1 << (FX32_INT_SHIFT - 1))) >> FX32_INT_SHIFT);
    //matrix determinant
    det = (fx32)(((fx64)mtx->_[0] * det0 - (fx64)mtx->_[1] * det1 + (fx64)mtx->_[2] * det2 + (fx64)(1 << (FX32_INT_SHIFT - 1))) >> FX32_INT_SHIFT);

    if (det == 0)
        return -1; //not invertible

    fix32_QueueComputeReciprocal(det);

    var0 = (fx32)(((fx64)mtx->_[1] * mtx->_[8] - (fx64)mtx->_[7] * mtx->_[2]) >> FX32_INT_SHIFT);
    var1 = (fx32)(((fx64)mtx->_[1] * mtx->_[5] - (fx64)mtx->_[4] * mtx->_[2]) >> FX32_INT_SHIFT);
    var2 = (fx32)(((fx64)mtx->_[0] * mtx->_[8] - (fx64)mtx->_[6] * mtx->_[2]) >> FX32_INT_SHIFT);
    var3 = (fx32)(((fx64)mtx->_[0] * mtx->_[5] - (fx64)mtx->_[3] * mtx->_[2]) >> FX32_INT_SHIFT);

    fx32 ret = fix32_GetDivisionResult();
    dst->_[0] =  (fx32)(((fx64)ret * det0) >> FX32_INT_SHIFT);
    dst->_[1] = -(fx32)(((fx64)ret * var0) >> FX32_INT_SHIFT);
    dst->_[2] =  (fx32)(((fx64)ret * var1) >> FX32_INT_SHIFT);
    dst->_[3] = -(fx32)(((fx64)ret * det1) >> FX32_INT_SHIFT);
    dst->_[4] =  (fx32)(((fx64)ret * var2) >> FX32_INT_SHIFT);
    dst->_[5] = -(fx32)(((fx64)ret * var3) >> FX32_INT_SHIFT);

    dst->_[6] = (fx32)(((fx64)ret * det2) >> FX32_INT_SHIFT);
    fx32 temp = (fx32)(((fx64)mtx->_[0] * mtx->_[7] - (fx64)mtx->_[6] * mtx->_[1]) >> FX32_INT_SHIFT);
    dst->_[7] = -(fx32)(((fx64)ret * temp) >> FX32_INT_SHIFT);
    fx32 temp1 = (fx32)(((fx64)mtx->_[0] * mtx->_[4] - (fx64)mtx->_[3] * mtx->_[1]) >> FX32_INT_SHIFT);
    dst->_[8] = (fx32)(((fx64)ret * temp1) >> FX32_INT_SHIFT);
    dst->_[9] =  -(fx32)(((fx64)dst->_[0] * mtx->_[9] + (fx64)dst->_[3] * mtx->_[10] + (fx64)dst->_[6] * mtx->_[11]) >> FX32_INT_SHIFT);
    dst->_[10] = -(fx32)(((fx64)dst->_[1] * mtx->_[9] + (fx64)dst->_[4] * mtx->_[10] + (fx64)dst->_[7] * mtx->_[11]) >> FX32_INT_SHIFT);
    dst->_[11] = -(fx32)(((fx64)dst->_[2] * mtx->_[9] + (fx64)dst->_[5] * mtx->_[10] + (fx64)dst->_[8] * mtx->_[11]) >> FX32_INT_SHIFT);

    if (dst == &tempmat)
        MI_Copy48B(&tempmat, inv);
    return 0;
}
