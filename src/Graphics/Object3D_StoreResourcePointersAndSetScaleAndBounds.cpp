#include <globaldefs.h>
#include <World/Object3D.h>
extern "C" {
// Original: arm9/main @ 0x020484F8; symbol: func_020484f8; size: 0x90.
    void Object3D_StoreResourcePointersAndSetScaleAndBounds(unsigned char *p,unsigned char **data){
        *(unsigned char **)(p+176)=data[1];
        *(unsigned char **)(p+172)=data[0];
        *(unsigned char **)(p+180)=data[2];
        Object3D *obj=(Object3D *)p;
        obj->SetScale(266,266,266);
        obj->SetRadius(*(short *)(*(unsigned char **)(p+172)+12)<<2);
        obj->SetHeight(*(short *)(*(unsigned char **)(p+172)+14));
        if(*(short *)(*(unsigned char **)(p+172)+8)==320)obj->EnableFlag(0x20000000);
        if(obj->GetFlags()&0x20000000)return;
        obj->UseRenderConfigDiffuseColor();
    }
}
