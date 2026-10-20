#include <globaldefs.h>
extern "C" void *Zone3D_GetMainInstance(void);
extern "C" void *ZoneState_GetTrackedZoneCache(void);
extern "C" void *ZoneState_FindTrackedZoneByIdentifier(void *, int);
extern "C" void ZoneState_MarkType2FeatureActivated(unsigned char *, int);
extern "C" void * _ZN6Zone3D15GetType2FeatureEi(void *, int);
extern "C" void _ZN6Zone3D20ActivateType2FeatureEPN12ZoneFeatures13Opcode6aEntryEbbi(void *, void *, int, int, int);
// Original: arm9/ov017 @ 0x021D19B0; symbol: func_ov017_021d19b0; size: 0x68.
extern "C" void Ov017_ApplyZoneFeatureRecord(char *unused, char *record) {
    void *zone = Zone3D_GetMainInstance();
    if (*(unsigned short *)(record + 4) == *(unsigned short *)zone) {
        void *feature = _ZN6Zone3D15GetType2FeatureEi(zone, *(unsigned short *)(record + 6));
        if (feature == 0) return;
        _ZN6Zone3D20ActivateType2FeatureEPN12ZoneFeatures13Opcode6aEntryEbbi(
            zone, feature, *(unsigned int *)(record + 8), 0, 0);
        return;
    }
    void *list = ZoneState_GetTrackedZoneCache();
    void *entry = ZoneState_FindTrackedZoneByIdentifier(list, *(unsigned short *)(record + 4));
    if (entry != 0) ZoneState_MarkType2FeatureActivated((unsigned char *)entry, *(unsigned short *)(record + 6));
}
