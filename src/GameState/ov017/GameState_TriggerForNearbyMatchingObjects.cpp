#include <globaldefs.h>
ARM
struct Vector { int x,y,z; };
extern "C" { unsigned char* _ZN9GameState20GetUnknownGameObjectEv(void*); unsigned char* _ZN9GameState21GetPartyMemberByIndexEi(void*,int); int ReadIndexedSignedField1038(char*); unsigned short _ZNK8Object3D10GetField06Ev(void*); bool IsFirstSignedWordZero(const int*); int Vector3fix_Distance(const Vector*,const Vector*); void func_ov017_021a6b9c(void*,unsigned char); }
// Original: arm9/ov017 @ 0x021D1D00; symbol: func_ov017_021d1d00; size: 0xC0.
extern "C" void GameState_TriggerForNearbyMatchingObjects(int unused,void* unused2,void* state,unsigned char* resources,char* connection) {
 if(ReadIndexedSignedField1038(connection) && IsFirstSignedWordZero(*(int**)(resources+0x36fc))) {
  unsigned char* member=_ZN9GameState21GetPartyMemberByIndexEi(state,0);
  unsigned char* other=_ZN9GameState20GetUnknownGameObjectEv(state);
  if(member && other) {
   unsigned short first=_ZNK8Object3D10GetField06Ev(member);
   if(first==_ZNK8Object3D10GetField06Ev(other)) {
    Vector a=*(Vector*)(member+0x44);
    Vector b=*(Vector*)(other+0x44);
    if(Vector3fix_Distance(&a,&b)<0x7800) func_ov017_021a6b9c(resources,0);
   }
  }
 }
}
