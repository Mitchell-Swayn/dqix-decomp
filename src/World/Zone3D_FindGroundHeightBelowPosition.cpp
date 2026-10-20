#include "World/Zone3D.h"
struct GroundQueryBounds { Vector3i upper,lower; };
struct GroundTriangle { Vector3i a,b,c,normal; };
struct GroundPackedTriangle { short components[12]; };
struct GroundQueryResult { GroundPackedTriangle triangles[96]; int unknown900; int scale; Vector3i origin; unsigned char unknown914[0x6c]; };
extern "C" {
int Zone3D_CollectInstanceCollisionPolygons(Zone3D*,int,GroundQueryResult*,GroundQueryBounds,void*);
void VectorQuad_ExpandSignedHalfwordComponents(GroundTriangle*,const GroundPackedTriangle*);
int Geometry_FindHighestUpwardTriangleAndIntersectPlane(GroundTriangle*,int,const Vector3i*,const Vector3i*,Vector3i*);
}
// Tests a vertical segment against queried zone triangles and returns the resulting fixed-point height.
// Packed query fields at 0x904/0x908 supply the vertex scale and origin; the remaining tail is unknown.
// Original: arm9/main @ 0x02018FBC; symbol: func_02018fbc; size: 0x254.
extern "C" int Zone3D_FindGroundHeightBelowPosition(Zone3D* zone,const Vector3i* input) {
    GroundQueryResult query;
    GroundTriangle triangles[96];
    Vector3i position=*input;
    GroundQueryBounds bounds;
    bounds.upper=position;
    bounds.lower=position;
    bounds.upper.x+=0x800; bounds.upper.y+=0x1000; bounds.upper.z+=0x800;
    bounds.lower.x-=0x800; bounds.lower.y-=0xa000; bounds.lower.z-=0x800;
    int tile;
    if(zone->isInMainGrottoFloor_23b8_) {
        tile=(int)((float)(position.x+0x4000)/4096.0f/8.0f);
        tile+=(int)((float)(position.z+0x4000)/4096.0f/8.0f)*16;
    }
    for(int i=0;i<zone->unknown_82c_;++i) {
        if(zone->isInMainGrottoFloor_23b8_ && tile!=i) continue;
        int count=Zone3D_CollectInstanceCollisionPolygons(zone,i,&query,bounds,0);
        if(count<=0)continue;
        GroundTriangle* triangle=triangles;
        int scale;
        for(int j=0;j<count;) {
            scale=query.scale<<12;
            VectorQuad_ExpandSignedHalfwordComponents(triangle,&query.triangles[j]);
            Vector3fixMultiplyScalar(&triangle->a,scale,&triangle->a);
            Vector3fixMultiplyScalar(&triangle->b,scale,&triangle->b);
            Vector3fixMultiplyScalar(&triangle->c,scale,&triangle->c);
            ++j;
            ++triangle;
        }
        Vector3i relative,upper,lower,hit;
        Vector3fix_Subtract(&position,&query.origin,&relative);
        upper=relative;upper.y+=0x1000;
        lower=relative;lower.y-=0xa000;
        if(Geometry_FindHighestUpwardTriangleAndIntersectPlane(triangles,count,&upper,&lower,&hit)!=-1) {
            hit.y+=0x199;
            position.y=hit.y;
            relative.y=hit.y;
        }
    }
    return position.y;
}
