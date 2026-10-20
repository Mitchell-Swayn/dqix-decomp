#include <globaldefs.h>
#include <Graphics/Model3D.h>
struct Object {char pad[8];Model3D* model;char padc[0x194];unsigned char bones[7];};
extern "C" const char Model3D_ResolveNamedBoneIndices_TextHead[],Model3D_ResolveNamedBoneIndices_TextWaist[],Model3D_ResolveNamedBoneIndices_TextChest[],Model3D_ResolveNamedBoneIndices_TextArm1L[],Model3D_ResolveNamedBoneIndices_TextArm1R[],Model3D_ResolveNamedBoneIndices_TextLeg1L[],Model3D_ResolveNamedBoneIndices_TextLeg1R[];
// Original: arm9/main @ 0x02053E10; symbol: func_02053e10; size: 0xA4.
extern "C" void Model3D_ResolveNamedBoneIndices(Object* p) {Model3D* m=p->model;if(!m)return;p->bones[0]=m->GetBoneIndex(Model3D_ResolveNamedBoneIndices_TextHead);p->bones[1]=m->GetBoneIndex(Model3D_ResolveNamedBoneIndices_TextWaist);p->bones[2]=m->GetBoneIndex(Model3D_ResolveNamedBoneIndices_TextChest);p->bones[3]=m->GetBoneIndex(Model3D_ResolveNamedBoneIndices_TextArm1L);p->bones[4]=m->GetBoneIndex(Model3D_ResolveNamedBoneIndices_TextArm1R);p->bones[5]=m->GetBoneIndex(Model3D_ResolveNamedBoneIndices_TextLeg1L);p->bones[6]=m->GetBoneIndex(Model3D_ResolveNamedBoneIndices_TextLeg1R);}
