#include <globaldefs.h>
#include <std_library_functions.h>
ARM
#pragma force_active on
// Original data: arm9/ov001 @ 0x021656f4; symbol: data_ov001_021656f4.
// NUL-terminated path text: "chara/p_"; initialized bytes are preserved in its owning data range.
extern "C" char Event_ResolveCharacterArchiveMember_TextCharaP[];
// Original data: arm9/ov001 @ 0x021656fd; symbol: data_ov001_021656fd.
// NUL-terminated path text: "chara\\p_"; initialized bytes are preserved in its owning data range.
extern "C" char Event_ResolveCharacterArchiveMember_TextCharaP_Copy2[];
// Original data: arm9/ov001 @ 0x02165706; symbol: data_ov001_02165706.
// NUL-terminated path text: "chara/"; initialized bytes are preserved in its owning data range.
extern "C" char Event_ResolveCharacterArchiveMember_TextChara[];
// Original data: arm9/ov001 @ 0x0216570d; symbol: data_ov001_0216570d.
// NUL-terminated path text: "data/pack_lv5/chara_pc.gp2"; initialized bytes are preserved in its owning data range.
extern "C" char Event_ResolveCharacterArchiveMember_PathDataPackLv5CharaPcGp2[];
// Original data: arm9/ov001 @ 0x02165728; symbol: data_ov001_02165728.
// NUL-terminated path text: ".mon"; initialized bytes are preserved in its owning data range.
extern "C" char Event_ResolveCharacterArchiveMember_TextMon[];
// Original data: arm9/ov001 @ 0x0216572d; symbol: data_ov001_0216572d.
// NUL-terminated path text: "data/pack_lv5/enemy.gp2"; initialized bytes are preserved in its owning data range.
extern "C" char Script_LoadEnemyArchiveObject_PathDataPackLv5EnemyGp2[];
// Original: arm9/ov001 @ 0x0215AD3C; symbol: func_ov001_0215ad3c; size: 0xe0.
// Resolves player and monster archive paths into a member name and GP2 archive name.
extern "C" int Event_ResolveCharacterArchiveMember(const char* path, char* member, char* archive) {
    char* player = strstr(path, Event_ResolveCharacterArchiveMember_TextCharaP);
    if (!player) {
        // The original probes the backslash spelling but does not retain its result.
        strstr(path, Event_ResolveCharacterArchiveMember_TextCharaP_Copy2);
    }
    if (player) {
        strcpy(member, player + strlen(Event_ResolveCharacterArchiveMember_TextChara));
        strcpy(archive, Event_ResolveCharacterArchiveMember_PathDataPackLv5CharaPcGp2);
        return 1;
    }
    if (strstr(path, Event_ResolveCharacterArchiveMember_TextMon)) {
        char* filename = strrchr(path, '/');
        if (!filename) filename = strrchr(path, '\\');
        if (filename) ++filename;
        else filename = (char*)path;
        strcpy(member, filename);
        strcpy(archive, Script_LoadEnemyArchiveObject_PathDataPackLv5EnemyGp2);
        return 1;
    }
    return 0;
}
