#include "globaldefs.h"
#include "std_library_functions.h"
#include "TextEntryTypes.h"

extern "C" {
    int func_020426bc(const char* text, char* codes, int encoding);
    void func_02042764(const char* codes, char* text, int encoding);
    int func_ov003_0215ec90(TextEntryState* state);

    int func_ov003_0215ee44(TextEntryState* state)
    {
        state->mode = state->mode == 2 ? 1 : 2;
        state->alternate = 0;
        return 4;
    }

    int func_ov003_0215ee68(TextEntryState* state)
    {
        state->mode = 1;
        state->alternate = state->alternate == 0;
        return 5;
    }

    int func_ov003_0215ee88(TextEntryState* state)
    {
        state->mode = 1;
        state->alternate = 0;
        return 6;
    }

    int func_ov003_0215eea0(TextEntryState* state)
    {
        state->mode = 4;
        state->alternate = 0;
        return 7;
    }

    int func_ov003_0215eeb8(TextEntryState* state)
    {
        char* text = state->text;
        unsigned char encoding = state->encoding;
        char codes[256] = {};
        int length = func_020426bc(text, codes, encoding);
        if (length == 0) {
            return 9;
        }
        codes[length - 1] = 0;
        memset(text, 0, state->bufferSize);
        func_02042764(codes, text, encoding);
        return 8;
    }

    int func_ov003_0215ef2c(TextEntryState*)
    {
        return 10;
    }

    int func_ov003_0215ef34(TextEntryState* state)
    {
        state->mode = 8;
        state->alternate = 0;
        return 11;
    }

    int func_ov003_0215ef4c(TextEntryState*)
    {
        return 12;
    }

    typedef int (*TextEntryAction)(TextEntryState*);
    struct TextEntryActionTable {
        TextEntryAction handlers[9];
    };
    extern const TextEntryActionTable data_ov003_0217f3c8 = {{
        func_ov003_0215ec90,
        func_ov003_0215ee44,
        func_ov003_0215ee68,
        func_ov003_0215ee88,
        func_ov003_0215eea0,
        func_ov003_0215eeb8,
        func_ov003_0215ef2c,
        func_ov003_0215ef34,
        func_ov003_0215ef4c,
    }};

    int func_ov003_0215ef54(TextEntryState* state)
    {
        TextEntryKey* key = state->selectedKey;
        if (key != NULL) {
            TextEntryActionTable actions = data_ov003_0217f3c8;
            return actions.handlers[key->action](state);
        }
        return 0;
    }

    void func_ov003_0215efb8(TextEntryState* state)
    {
        state->selectedKey = NULL;
        state->layout = NULL;
        state->text = NULL;
        state->widthLimit = 0;
        state->bufferSize = 0;
        state->characterLimit = 0;
        state->lastInput = 0;
        state->repeatTimer = 0;
        state->mode = 1;
        state->encoding = 0;
        state->alternate = 0;
        state->unknown21 = 1;
        state->allowAlternateConfirm = 0;
        state->allowBackspace = 1;
        state->allowTouch = 1;
    }
}
