#include <globaldefs.h>
typedef struct Vec {int x,y,z;} Vec;typedef struct Matrix{int values[12];} Matrix;typedef struct Source{Vec position,rotation,scale;Matrix matrix;} Source;typedef struct Object{int word;Source transform;} Object;
// Original: arm9/main @ 0x0202ED0C; symbol: func_0202ed0c; size: 0x58.
ARM void Camera_CopyViewConfiguration(Object*dst,const Source*src){dst->transform.position=src->position;dst->transform.rotation=src->rotation;dst->transform.scale=src->scale;dst->transform.matrix=src->matrix;}
