/* C ABI declarations of the existing C++ methods, using their linker names. */
typedef struct GameState GameState;
typedef struct Object3D Object3D;
typedef struct Vector { int x, y, z; } Vector;
typedef struct Frame { Vector position, copy; } Frame;
typedef struct Layout { char pad[0xbe]; unsigned char disabled, padbf, type, padc1, padc2, flag; char pad2[0x6c]; unsigned* flags; } Layout;
typedef struct Control { char pad[0x56c]; unsigned char flag; } Control;
extern GameState* _ZN9GameState11GetInstanceEv(void);
extern Object3D* _ZN9GameState21GetPartyMemberByIndexEi(GameState*, int);
extern unsigned short _ZNK8Object3D10GetField06Ev(const Object3D*);
extern int ReadWordAtOffset1C8(Object3D*), Object_ReadRemoteMemberStateOrLocalByteBE(Object3D*), TestContextObjectRecordFlag4000(Object3D*);
extern Control* ReadWordFieldAtOffset150(Object3D*);
extern void ReadContextOrLocalObjectPosition(Vector*, Object3D*);
extern int Vector3fix_Distance(const Vector*, const Vector*);
#pragma opt_rebuildconditionals off
#pragma opt_rebuildlogicals off
#pragma opt_generateconditionalassignments off
// Original: arm9/main @ 0x020793C0; symbol: func_020793c0; size: 0x138.
int ProcessFourPartyMembersWithFrameState(Object3D* object, int limit)
{
    GameState* state = _ZN9GameState11GetInstanceEv();
    int i;
    Frame frame;
    for (i = 0; i < 4; ++i) {
        Object3D* member = _ZN9GameState21GetPartyMemberByIndexEi(state, i);
        Layout* layout;
        if (!member) {
            if (!i) return -1;
            continue;
        }
        if (ReadWordAtOffset1C8(member) != -1 || !Object_ReadRemoteMemberStateOrLocalByteBE(member)) continue;
        layout = (Layout*)member;
        if (_ZNK8Object3D10GetField06Ev(object) != _ZNK8Object3D10GetField06Ev(member) || layout->type == 6) continue;
        if (_ZNK8Object3D10GetField06Ev(member) != _ZNK8Object3D10GetField06Ev(object)) continue;
        if (ReadWordFieldAtOffset150(member)->flag || (*layout->flags & 1) || (int)layout->flag > 0 || TestContextObjectRecordFlag4000(member)) continue;
        ReadContextOrLocalObjectPosition(&frame.position, member);
        frame.copy = frame.position;
        if (Vector3fix_Distance(&frame.copy, (const Vector*)((char*)object + 0x44)) < limit) return (short)i;
    }
    return -1;
}
