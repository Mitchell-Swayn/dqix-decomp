#include <globaldefs.h>
#pragma always_inline on
#include <GameState/GameState.h>
#include <Graphics/Vector.h>
#include <Graphics/NSBXX/RenderConfig.h>
static inline int MultiplyRounded(int lhs, int rhs) { return FIX32_MULTIPLY(lhs,rhs); }
struct PositionWords { int x, y, z; };
extern "C" void Vector3fix_Add(const Vector3fix*, const Vector3fix*, Vector3fix*);
struct PhaseBits { unsigned short phase:15; unsigned short flag:1; };
static inline unsigned GetHeightPhase(const char* object) { return ((const PhaseBits*)(object+0xc4))->phase; }
#pragma always_inline off
static inline int HasHeightPhase(const char* object) { return GetHeightPhase(object)!=0; }
#pragma always_inline on
// Original: arm9/main @ 0x02032FDC; symbol: func_02032fdc; size: 0x2D0.
// Draws with temporary height and camera-directed displacement, then restores height.
extern "C" ARM int Object3D_DrawWithTemporaryHeightAndCameraDisplacement(Object3D* object, bool applyClipping, Vector3fix* displacedPosition)
{
    char* bytes=(char*)object;
    int scale;
    int result;
    int originalHeight=object->position_.y;
    if (HasHeightPhase(bytes)) {
        unsigned phase=GetHeightPhase(bytes);
        scale=4096;
        if (phase>4900) scale=(int)(4096.0f*((float)(5000-(int)phase)/100.0f));
        else if (phase<100) scale=(int)(4096.0f*((float)phase/100.0f));
        PositionWords position=*(PositionWords*)&object->position_;
        int reducedHeight=(object->GetHeight()/3)*2;
        int adjustment=MultiplyRounded(reducedHeight,scale);
        position.y=position.y-adjustment;
        object->position_=*(Vector3fix*)&position;
    }
    if (*(int*)(bytes+0x124)) {
        PositionWords position=*(PositionWords*)&object->position_;
        position.y=*(int*)(bytes+0x124);
        object->position_=*(Vector3fix*)&position;
    }
    if (*(unsigned short*)(bytes+0xbc)) {
        unsigned ticks=GameState::GetInstance()->GetEffectiveDeltaTime();
        PositionWords direction;
        const int* cameraBasis=(const int*)&data_0210a010.viewMatrix;
        direction.x=cameraBasis[0];
        direction.y=cameraBasis[3];
        direction.z=cameraBasis[6];
        Vector3fixMultiplyScalar((Vector3fix*)&direction,*(short*)(bytes+0xba),(Vector3fix*)&direction);
        Vector3fix position;
        Vector3fix_Add(&object->position_,(Vector3fix*)&direction,&position);
        object->position_=position;
        if (displacedPosition) *displacedPosition=position;
        result=object->Draw(applyClipping);
        object->position_=object->position_;
        if (*(unsigned short*)(bytes+0xbc)<ticks) {
            *(unsigned short*)(bytes+0xbc)=0;
            *(short*)(bytes+0xba)=0;
        } else {
            short magnitude=(short)fix32abs(*(short*)(bytes+0xba));
            short remaining=magnitude-(int)(4096.0f*((float)ticks*((float)magnitude/4096.0f/(float)*(unsigned short*)(bytes+0xbc))));
            if (*(short*)(bytes+0xba)>0) *(short*)(bytes+0xba)=-remaining;
            else *(short*)(bytes+0xba)=remaining;
            *(unsigned short*)(bytes+0xbc)-=ticks;
        }
    } else {
        result=object->Draw(applyClipping);
        if (displacedPosition) *displacedPosition=object->position_;
    }
    if (HasHeightPhase(bytes)||*(int*)(bytes+0x124)) {
        PositionWords position=*(PositionWords*)&object->position_;
        position.y=originalHeight;
        object->position_=*(Vector3fix*)&position;
    }
    return result;
}
