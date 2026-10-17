#include <globaldefs.h>
#include <Graphics/Model3D.h>
struct Object {char pad[8];Model3D* model;char padc[0x194];unsigned char bones[7];};
extern "C" const char data_020f048a[],data_020f048f[],data_020f0495[],data_020f049b[],data_020f04a1[],data_020f04a7[],data_020f04ad[];
// Original: arm9/main @ 0x02053E10; symbol: func_02053e10; size: 0xA4.
extern "C" void Model3D_ResolveNamedBoneIndices(Object* p) {Model3D* m=p->model;if(!m)return;p->bones[0]=m->GetBoneIndex(data_020f048a);p->bones[1]=m->GetBoneIndex(data_020f048f);p->bones[2]=m->GetBoneIndex(data_020f0495);p->bones[3]=m->GetBoneIndex(data_020f049b);p->bones[4]=m->GetBoneIndex(data_020f04a1);p->bones[5]=m->GetBoneIndex(data_020f04a7);p->bones[6]=m->GetBoneIndex(data_020f04ad);}
