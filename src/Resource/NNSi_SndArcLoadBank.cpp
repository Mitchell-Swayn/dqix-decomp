#include <globaldefs.h>
ARM
extern "C" {
unsigned char *NNS_SndArcGetBankInfo(int index);
void *NNS_SndArcGetWaveArcInfo(unsigned index);
unsigned int NNS_SndArcGetFileAddress(unsigned int i);
int NNSi_SndArcLoadWaveArc(void *resource, unsigned flags, int a, int b, int *out);
int SoundArchive_LoadBankFile(void *object, int argument, int flag);
int SoundArchive_LoadBankReferencedWaves(void *p, void *file, unsigned owner, int a, int b);
struct CommandLink {
    void *first;
    CommandLink *next;
};
struct CommandNode {
    unsigned char pad[0x18];
    CommandLink *link;
};
void SND_AssignWaveArc(char *owner, int index, CommandNode *node);
}

struct BankInfo {
    unsigned fileId;
    unsigned short waveArcNo[4];
};

struct WaveArcInfo {
    unsigned id : 24;
    unsigned flags : 8;
};

// Original: arm9/main @ 0x020BDED0; symbol: func_020bded0; size: 0x140.
// Loads a sound-archive bank file and binds up to four referenced wave archives.
extern "C" int NNSi_SndArcLoadBank(int index, unsigned flags, int heap, int set_addr, void **out)
{
    BankInfo *info = (BankInfo *)NNS_SndArcGetBankInfo(index);
    int file;
    int i;
    unsigned load_wave;

    if (info == 0)
        return 4;

    if (flags & 2) {
        file = SoundArchive_LoadBankFile((void *)info->fileId, heap, set_addr);
        if (file == 0)
            return 8;
    } else {
        file = (int)NNS_SndArcGetFileAddress(info->fileId);
    }

    load_wave = flags & 4;
    for (i = 0; i < 4; i++) {
        unsigned short wave_no = info->waveArcNo[i];
        WaveArcInfo *wave_info;
        int wave_file;
        int result;

        if (wave_no == 0xffff)
            continue;

        wave_info = (WaveArcInfo *)NNS_SndArcGetWaveArcInfo(wave_no);
        if (wave_info == 0)
            return 5;

        result = NNSi_SndArcLoadWaveArc((void *)info->waveArcNo[i], flags, heap, set_addr, &wave_file);
        if (result != 0)
            return result;

        if ((wave_info->flags & 1) != 0 && load_wave != 0) {
            if (SoundArchive_LoadBankReferencedWaves(
                    (void *)wave_file, (void *)file, (unsigned)i, (int)wave_info->id, heap)
                == 0)
                return 9;
        }

        if (file != 0 && wave_file != 0)
            SND_AssignWaveArc((char *)file, i, (CommandNode *)wave_file);
    }

    if (out != 0)
        *out = (void *)file;
    return 0;
}
