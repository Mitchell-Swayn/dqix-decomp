#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Graphics/Vector.h>
extern "C" {

    void func_02094b9c(void *,const Vector3i *);
// Original: arm9/main @ 0x02094B5C; symbol: func_02094b5c; size: 0x40.
    void CopyGameObjectPositionToHandler(void *p,int id){
        unsigned char *q=(unsigned char *)GameState::GetInstance()->GetGameObjectByIndex(id);
        Vector3i v=*(Vector3i *)(q+68);
        func_02094b9c(p,&v);
    }
}
