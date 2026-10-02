#include "World/Object3D.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

// Partial layouts inferred from the preview's consumers. Unnamed storage is
// retained until its owning interfaces are reconstructed.
struct PreviewSelection {
    char unknown0[12];
    short recordId;
    char unknownE[5];
    unsigned char unknownFlags : 1;
    unsigned char hasModel : 1;
};
struct PreviewRecord {
    char unknown0[12];
    unsigned char animationCount;
    char unknownD[3];
    float x, y, z, rotationY, scaleX, scaleY, scaleZ;
    const char** animations;
};
struct PreviewOptions {
    unsigned int unknown : 10;
    unsigned int alternate : 1;
};
struct ModelPreview {
    int unknown0;
    void* spriteManager;
    struct Sprite {
        char unknown0[20];
        int x, y;
        char unknown1C[12];
    } *sprites;
    char records[16];
    char habitat[36];
    Object3D* object;
    int unknown44;
    PreviewSelection* selection;
    PreviewSelection* priorSelection;
    PreviewOptions* options;
    PreviewOptions* priorOptions;
    void* spritePositions;
    char unknown5C[16];
    int modelTask;
    int animationTask;
    int animationIndex;
    char unknown78[4];
    unsigned char state;
    unsigned char unknown7D;
    unsigned char animationLoadState;
    unsigned char modelLoadState;
    unsigned char alternateIndex;
    unsigned char flags;
    union {
        unsigned char rotationFlags;
        struct {
            unsigned char rotating : 1;
            unsigned char unknownRotationFlags : 7;
        };
    };
    char unknown83[3];
    short tasks[5];
    union {
        unsigned char adjusted[3];
        struct {
            unsigned char rotationAdjusted[2];
            unsigned char switched;
        };
    };
    unsigned char unknown93;
    unsigned char drawSprites;
};
typedef char PreviewLayoutCheck[(sizeof(ModelPreview) == 0x98) ? 1 : -1];
typedef void (ModelPreview::*PreviewHandler)();
struct PreviewDispatch {
    char unknown0[16];
    PreviewHandler handlers[3];
};

extern "C" {
PreviewRecord* func_02097224(void*, int);
void func_ov014_02188d10(void*);
void func_ov014_02184f78(ModelPreview*, PreviewSelection*, PreviewOptions*, int);
extern const char data_ov014_021895c8[];
extern const char data_ov014_021895ce[];
extern const short data_ov014_02189478[];
extern const short data_ov014_0218948c[];
extern const short data_ov014_0218948e[];
void func_ov023_021e2bdc(void*, int, short*, short*);
void func_0205ac40(void*, ModelPreview::Sprite*);
void func_ov014_02185c48(ModelPreview*);
int func_02012430(void*, int);
int func_02012468(void*, int);
extern char data_02114e30[];
extern unsigned int data_ov014_02189800[];
extern PreviewHandler data_020e6d5c;
extern PreviewDispatch data_ov014_021895a0;
extern PreviewHandler data_ov014_021895b0[];

void func_ov014_02184700(ModelPreview* preview)
{
    func_ov014_02185c48(preview);
    if (preview->object) {
        preview->object->AdvanceEffects();
        int rotationY = 0;
        if (preview->selection) {
            PreviewRecord* record = func_02097224(preview->records, preview->selection->recordId);
            if (record) rotationY = (int)(4096.0f * record->rotationY);
        }
        Object3D* object = preview->object;
        int rotating = preview->rotating;
        int step;
        int keepRotating;
        int manual;
        Vector3i movedRotation, currentRotation;
        if (!object) {
            keepRotating = 0;
        } else {
            manual = 0;
            preview->adjusted[0] = 0;
            preview->adjusted[1] = 0;
            keepRotating = rotating;
            step = 0;
            if (func_02012430(data_02114e30, 0x200) && func_02012430(data_02114e30, 0x100)) {
                if (!rotating) {
                    keepRotating = 1;
                    preview->adjusted[0] = 1;
                    preview->adjusted[1] = 1;
                }
            } else if (func_02012430(data_02114e30, 0x200) && !func_02012468(data_02114e30, 0x100)) {
                manual = 1;
                preview->adjusted[0] = 1;
                step = 204;
            } else if (func_02012430(data_02114e30, 0x100) && !func_02012468(data_02114e30, 0x200)) {
                manual = 1;
                preview->adjusted[1] = 1;
                step = -204;
            }
            if (rotating) {
                currentRotation = object->rotation_;
                int delta = rotationY - currentRotation.y;
                if (currentRotation.y >= rotationY + 0x3243) delta = rotationY + 0x6487 - currentRotation.y;
                step = delta / 5;
                if (!func_02012430(data_02114e30, 0x100) && !func_02012430(data_02114e30, 0x200) && currentRotation.y == rotationY) keepRotating = 0;
            }
            if (manual || rotating) {
                step *= GameState::GetInstance()->GetTickCount();
                movedRotation = object->rotation_;
                movedRotation.y += step;
                if (rotating) {
                    if (movedRotation.y < rotationY + 204 || movedRotation.y > rotationY + 0x63bb) movedRotation.y = rotationY;
                    if (!preview->adjusted[0] || !preview->adjusted[1] || movedRotation.y == rotationY) {
                        preview->adjusted[0] = 0;
                        preview->adjusted[1] = 0;
                    }
                }
                if (movedRotation.y < 0) movedRotation.y += 0x6487;
                if (movedRotation.y >= 0x6487) movedRotation.y -= 0x6487;
                object->rotation_ = movedRotation;
            }
        }
        preview->rotationFlags = (preview->rotationFlags & ~1) | (keepRotating & 1);
        if (preview->object->HasAnimationStopped() || preview->object->HasAnimationReachedEnd()) {
            const char* name;
            Object3D* object = preview->object;
            name = (const char*)object->activeAnimationRecord_;
            if (name && strcmp(data_ov014_021895c8, name) && strcmp(data_ov014_021895ce, name)) object->MaybeSetRegularAnimation(data_ov014_021895c8, 0);
        }
    }
    preview->switched = 0;
    // Original lazy initialization of the third member-function-table entry.
    if (!(data_ov014_02189800[1] & 1)) {
        data_ov014_021895a0.handlers[2] = data_020e6d5c;
        data_ov014_02189800[1] |= 1;
    }
    if (data_ov014_021895b0[preview->state]) (preview->*data_ov014_021895b0[preview->state])();
}

void func_ov014_02184a64(ModelPreview* preview)
{
    if (!preview->state) return;
    if (!preview->selection || !preview->options) return;
    if (!preview->selection->hasModel) return;
    int showModel = 0;
    int showAlternate = 0;
    if (preview->flags & 0x20) {
        if (preview->priorSelection && preview->priorSelection->hasModel) showModel = 1;
        if (preview->priorOptions && preview->priorOptions->alternate) showAlternate = 1;
    } else {
        if (preview->selection->hasModel) showModel = 1;
        if (preview->options->alternate) showAlternate = 1;
    }
    if (showModel || showAlternate) {
        for (int i = 0; i < 3; ++i) {
            short x = 0, y = 0;
            int show = i == 2 ? showAlternate : showModel;
            if (show) {
                func_ov023_021e2bdc(preview->spritePositions, data_ov014_02189478[i], &x, &y);
                if (preview->adjusted[i]) {
                    x += data_ov014_0218948c[2*i];
                    y += data_ov014_0218948e[2*i];
                }
                ModelPreview::Sprite* sprite = &preview->sprites[i];
                sprite->x = x << 12;
                sprite->y = y << 12;
                if (preview->drawSprites) func_0205ac40(preview->spriteManager, &preview->sprites[i]);
            }
        }
    }
    if ((preview->flags & 4) && preview->object) preview->object->Draw(true);
}

void func_ov014_02184c08(ModelPreview* preview)
{
    if (!preview->selection) return;
    PreviewRecord* record = func_02097224(preview->records, preview->selection->recordId);
    if (!record) return;
    Vector3i position, rotation, scale;
    position.x = (int)(4096.0f * record->x);
    position.y = (int)(4096.0f * record->y);
    position.z = (int)(4096.0f * record->z);
    rotation.x = 0;
    rotation.y = (int)(4096.0f * record->rotationY);
    rotation.z = 0;
    scale.x = (int)(4096.0f * record->scaleX);
    scale.y = (int)(4096.0f * record->scaleY);
    scale.z = (int)(4096.0f * record->scaleZ);
    preview->object->position_ = position;
    preview->object->rotation_ = rotation;
    preview->object->SetScale(&scale);
}

void func_ov014_02184d08(ModelPreview* preview)
{
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (preview->flags & 1) {
        preview->flags &= ~1;
        if (preview->modelTask >= 0) {
            loader->RemoveTask(preview->modelTask);
            preview->modelTask = -1;
        }
        for (int i = 0; i < 5; ++i) {
            int task = preview->tasks[i];
            if (task >= 0) {
                BackgroundLoader::GetInstance()->RemoveTask(task);
                preview->tasks[i] = -1;
            }
        }
        func_ov014_02188d10(preview->habitat);
        preview->modelLoadState = 0;
    }
    if (preview->flags & 0x10) return;
    preview->flags |= 0x10;
    if (preview->animationTask >= 0) {
        loader->RemoveTask(preview->animationTask);
        preview->animationTask = -1;
    }
    preview->animationLoadState = 0;
}

void func_ov014_02184dcc(ModelPreview* preview)
{
    if (preview->flags & 1) return;
    if (preview->flags & 8) return;
    if (!preview->options) return;
    if (!preview->options->alternate) return;
    unsigned char index = preview->alternateIndex;
    func_ov014_02184f78(preview, preview->selection, preview->options, 0);
    preview->alternateIndex = index + 1;
    preview->alternateIndex &= 1;
    preview->switched = 1;
    preview->flags |= 8;
}

void func_ov014_02184e3c(ModelPreview* preview)
{
    if (!preview->object || !preview->object->loadedAnimationPackageList_ || !preview->selection) return;
    PreviewRecord* record = func_02097224(preview->records, preview->selection->recordId);
    if (!record) return;
    const char* name = (const char*)preview->object->activeAnimationRecord_;
    if (name && strcmp(data_ov014_021895c8, name) && strcmp(data_ov014_021895ce, name)) return;
    ++preview->animationIndex;
    if (record->animationCount <= preview->animationIndex) {
        preview->animationIndex = 0;
        if (record->animationCount > 1) preview->animationIndex = 1;
    }
    const char* animation = record->animations[preview->animationIndex];
    if (animation && animation[0]) preview->object->MaybeSetRegularAnimation(animation, 0);
}
}
