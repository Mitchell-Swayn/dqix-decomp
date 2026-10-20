#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" int _ZNK8Object3D9GetHeightEv(void*);
extern "C" int _ZNK8Object3D9GetRadiusEv(void*);
// Original: arm9/ov000 @ 0x021635E4; symbol: func_ov000_021635e4; size: 0xAC.
extern "C" short World_GetObjectDimensionByMode(int index,unsigned mode){
 void* gs=_ZN9GameState11GetInstanceEv();
 if(!gs)return 266;
 void* object=_ZN9GameState20GetGameObjectByIndexEi(gs,index);
 if(!object)return 266;
 int result=4096;
 int height=_ZNK8Object3D9GetHeightEv(object);
 int radius=_ZNK8Object3D9GetRadiusEv(object);
 switch(mode){
 case 0:if(height>radius)height=radius;result=height;break;
 case 1:if(height<radius)height=radius;result=height;break;
 case 2:result=(height+radius)>>1;break;
 case 3:result=radius;break;
 case 4:result=height;break;
 }
 return result;
}
