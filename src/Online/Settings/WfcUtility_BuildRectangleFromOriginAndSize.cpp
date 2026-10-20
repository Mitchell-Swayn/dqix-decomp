// Original: arm9/ov031 @ 0x0223CB34; symbol: func_ov031_0223cb34; size: 0x34.
extern "C" void WfcUtility_BuildRectangleFromOriginAndSize(unsigned short* origin,unsigned short* size,unsigned short* out) {
    out[0]=origin[0];
    out[1]=origin[1];
    out[2]=origin[0]+size[0];
    out[3]=origin[1]+size[1];
}
