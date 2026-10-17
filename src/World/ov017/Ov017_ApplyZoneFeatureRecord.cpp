#include <globaldefs.h>
extern "C" void *ReadGlobalValueAt020FB3F0(void);
extern "C" void *ReadGlobalAt020FDD44(void);
extern "C" void *FindRecordAmongFourByNonnegativeKey(void *, int);
extern "C" void SetHalfwordIdBitOrReportError(unsigned char *, int);
extern "C" void * _ZN6Zone3D15GetType2FeatureEi(void *, int);
extern "C" void _ZN6Zone3D20ActivateType2FeatureEPN12ZoneFeatures13Opcode6aEntryEbbi(void *, void *, int, int, int);
// Original: arm9/ov017 @ 0x021D19B0; symbol: func_ov017_021d19b0; size: 0x68.
extern "C" void Ov017_ApplyZoneFeatureRecord(char *unused, char *record) {
    void *zone = ReadGlobalValueAt020FB3F0();
    if (*(unsigned short *)(record + 4) == *(unsigned short *)zone) {
        void *feature = _ZN6Zone3D15GetType2FeatureEi(zone, *(unsigned short *)(record + 6));
        if (feature == 0) return;
        _ZN6Zone3D20ActivateType2FeatureEPN12ZoneFeatures13Opcode6aEntryEbbi(
            zone, feature, *(unsigned int *)(record + 8), 0, 0);
        return;
    }
    void *list = ReadGlobalAt020FDD44();
    void *entry = FindRecordAmongFourByNonnegativeKey(list, *(unsigned short *)(record + 4));
    if (entry != 0) SetHalfwordIdBitOrReportError((unsigned char *)entry, *(unsigned short *)(record + 6));
}
