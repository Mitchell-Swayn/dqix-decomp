#include "World/ZoneRecordLookup.h"

struct LabelState {
    unsigned char* owner;
    unsigned char unknown04[0x18];
    unsigned char kind;
    unsigned char unknown1d[3];
    int* ids;
    unsigned char unknown24[0x17];
    unsigned char variant;
    unsigned char valueAdjustment;
    unsigned char unknown3d[0xb];
    int alternate;
};

extern "C" {
void __clear(void*, unsigned int);
char* strcpy(char*, const char*);
int sprintf(char*, const char*, ...);
extern const char data_ov015_0219400a[];
extern const char data_ov015_0219400d[];
extern const char data_ov015_02194010[];
extern const char data_ov015_02194013[];
int func_020de234(ZoneSerializedRecord*, unsigned char);
struct LabelText8 { char text[8]; };
struct LabelMarkers10 { signed char text[10]; };
extern LabelText8 data_ov015_02193cd4;
extern LabelMarkers10 data_ov015_02193ce5;
extern const char data_ov015_02193fe4[];
extern const char data_ov015_02193fea[];
extern const char data_ov015_02193ffa[];

int func_ov015_0218c03c(LabelState* state, char* output, int index, int alternate)
{
    ZoneSerializedRecord* record = func_020dedd0((ZoneState2754*)(state->owner + 0x4c), (short)state->ids[index]);
    ZoneSerializedRecord* reference = func_020dedd0((ZoneState2754*)(state->owner + 0x4c), (short)state->ids[7]);
    int value = func_020de234(record, state->variant);
    LabelText8 suffix = data_ov015_02193cd4;
    char marker[2];
    char extra[2];
    __clear(marker, 2);
    __clear(extra, 2);
    switch (index) {
    case 4:
        strcpy(suffix.text, data_ov015_02193fe4);
        marker[0] = 'a';
        marker[1] = 0;
        value += state->valueAdjustment;
        break;
    case 3:
        marker[0] = 'a';
        marker[1] = 0;
        if (reference && reference->key > -1) {
            int category = func_020de234(reference, state->variant) / 100;
            if ((unsigned int)category >= 10) return 0;
            LabelMarkers10 markers = data_ov015_02193ce5;
            if (markers.text[category] == 0) return 0;
            marker[0] = markers.text[category];
            if (category == 3 && state->variant == 0 && record->key == 0x2329)
                marker[0] = 'f';
        }
        break;
    case 5:
    case 6:
        if (alternate) strcpy(suffix.text, data_ov015_02193fe4);
        break;
    }
    if (!alternate)
        sprintf(output, data_ov015_02193fea, (signed char)record->attributes.group, value, marker, extra, suffix.text);
    else
        sprintf(output, data_ov015_02193ffa, (signed char)record->attributes.group, value, marker, extra, suffix.text);
    return 1;
}

void func_ov015_0218c274(LabelState* state, char* output, int disabled)
{
    ZoneSerializedRecord* record = func_020dedd0((ZoneState2754*)(state->owner + 0x4c), (short)state->ids[8]);
    ZoneSerializedRecord* first = func_020dedd0((ZoneState2754*)(state->owner + 0x4c), (short)state->ids[0]);
    unsigned int firstValue = 0;
    unsigned int recordValue = 0;
    if (first) firstValue = (((unsigned int*)first->secondary.pointer)[1] << 12) >> 24;
    if (record) recordValue = (((unsigned int*)record->secondary.pointer)[1] << 12) >> 24;
    char suffix[4];
    __clear(suffix, 4);
    int marker;
    if (state->kind == 1) {
        strcpy(suffix, data_ov015_0219400a);
        marker = state->variant == 0 ? 'm' : 'w';
    } else {
        strcpy(suffix, data_ov015_0219400d);
        marker = state->alternate == 0 ? 'n' : 'b';
        if (disabled) marker = 'f';
    }
    if ((marker == 'n' || marker == 'f') && state->variant == 1)
        strcpy(suffix, data_ov015_02194010);
    sprintf(output, data_ov015_02194013, suffix, firstValue, recordValue, marker);
}
}
