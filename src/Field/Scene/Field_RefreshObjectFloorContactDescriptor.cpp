#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Zone3D.h>
ARM
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma force_active on
struct FloorBounds {Vector3i upper,lower;};
struct FloorTriangle {Vector3i a,b,c,normal;};
struct FloorPackedTriangle {short components[12];};
struct FloorQuery {FloorPackedTriangle triangles[96];int unknown900,scale;Vector3i origin;int unknown914,rotation,unknown91c;unsigned char descriptorIndices[96];};
struct FloorDescriptor {unsigned short values[4];};
extern "C" {
Zone3D* Zone3D_GetMainInstance();void GameObject_InvalidateWallContact(GameObject*);
int Zone3D_CollectInstanceCollisionPolygons(Zone3D*,int,FloorQuery*,FloorBounds,void*);
void VectorQuad_ExpandSignedHalfwordComponents(FloorTriangle*,const FloorPackedTriangle*);
int Geometry_FindHighestUpwardTriangleAndIntersectPlane(FloorTriangle*,int,const Vector3i*,const Vector3i*,Vector3i*);
void GameObject_SetFloorContactDescriptor(GameObject*,const FloorDescriptor*);
long long FX_CosFx64c(int);long long FX_SinFx64c(int);
}
// Original: arm9/ov017 @ 0x02193DC4; symbol: func_ov017_02193dc4; size: 0x37C.
// Queries each zone instance beneath the object and applies its intersected floor-material descriptor.
extern "C" int Field_RefreshObjectFloorContactDescriptor(GameObject* actor) {
    GameState::GetInstance();GameResources_GetInstance();Zone3D* zone=Zone3D_GetMainInstance();
    FloorQuery query;FloorTriangle triangles[96];FloorBounds bounds;Vector3i position=actor->obj3D_.position_;
    int total=0;bounds.upper=position;bounds.lower=position;
    bounds.upper.x+=actor->obj3D_.GetRadius()/2;bounds.upper.y+=actor->obj3D_.GetHeight();bounds.upper.z+=actor->obj3D_.GetRadius()/2;
    bounds.lower.x-=actor->obj3D_.GetRadius()/2;bounds.lower.y-=0x28000;bounds.lower.z-=actor->obj3D_.GetRadius()/2;
    GameObject_InvalidateWallContact(actor);
    for(int i=0;i<zone->unknown_82c_;++i) {
        int count=Zone3D_CollectInstanceCollisionPolygons(zone,i,&query,bounds,actor);
        if(count<=0)continue;total+=count;
        for(int j=0;j<count;++j) {
            int offset=j*sizeof(FloorTriangle);FloorTriangle* triangle=(FloorTriangle*)((char*)triangles+offset);VectorQuad_ExpandSignedHalfwordComponents(triangle,&query.triangles[j]);
            Vector3fixMultiplyScalar((Vector3i*)((char*)triangles+offset),query.scale<<12,&triangle->a);
            Vector3fixMultiplyScalar(&triangle->b,query.scale<<12,&triangle->b);
            Vector3fixMultiplyScalar(&triangle->c,query.scale<<12,&triangle->c);
        }
        Vector3i relative=position;Vector3fix_Subtract(&relative,&query.origin,&relative);
        int angle=-(query.rotation-0x6487);
        int cosine=(int)(4096.0f*((float)FX_CosFx64c(angle)/4294967296.0f));
        int sine=(int)(4096.0f*((float)FX_SinFx64c(angle)/4294967296.0f));Matrix3x3 rotation;
        MTX_RotY33_(&rotation,sine,cosine);Mat3x3_ApplyToVector(&relative,&rotation,&relative);
        Vector3i upper,lower,hit;upper=relative;upper.y+=0x800;lower=relative;lower.y-=0x28000;
        int polygon=Geometry_FindHighestUpwardTriangleAndIntersectPlane(triangles,count,&upper,&lower,&hit);
        if(polygon==-1)continue;hit.y+=0x199;Vector3fix_Add(&hit,&query.origin,&hit);
        char** instances=*(char***)((char*)zone+0x824);char* instance=instances[i];
        if(!instance)continue;char* resource=*(char**)(instance+0x24);if(!resource)continue;
        char* data=*(char**)(resource+4);if(!data || **(int**)data!=3)continue;
        FloorDescriptor descriptor=*(FloorDescriptor*)(*(char**)(data+0x14)+query.descriptorIndices[polygon]*8);
        GameObject_SetFloorContactDescriptor(actor,&descriptor);
    }
    *(short*)((char*)actor+0xac)=0;return total;
}
