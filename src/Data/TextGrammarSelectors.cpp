// func_02069234 matches prefixes and dispatches grammatical form selectors.
// Categories0..3 set article/form/case attributes;4..9 choose named actors.
struct TextGrammarSelector { const char* prefix; signed char category; signed char argument; unsigned short reserved; };
extern "C" {
extern char data_020f0709[];
extern char data_020f07bc[];
extern char data_020f06f0[];
extern char data_020f070e[];
extern char data_020f071d[];
extern char data_020f0727[];
extern char data_020f0713[];
extern char data_020f0718[];
extern char data_020f0704[];
extern char data_020f07c3[];
extern char data_020f07ca[];
extern char data_020f0764[];
extern char data_020f07d1[];
extern char data_020f07d8[];
extern char data_020f07df[];
}
extern "C" const TextGrammarSelector data_020e7f04[16] = {
    {data_020f0709, 0, 0, 0},
    {data_020f07bc, 0, 1, 0},
    {data_020f06f0, 1, 1, 0},
    {data_020f070e, 2, 0, 0},
    {data_020f071d, 2, 1, 0},
    {data_020f0727, 3, 0, 0},
    {data_020f0713, 3, 1, 0},
    {data_020f0718, 3, 2, 0},
    {data_020f0704, 3, 3, 0},
    {data_020f07c3, 4, -1, 0},
    {data_020f07ca, 5, -1, 0},
    {data_020f0764, 6, -1, 0},
    {data_020f07d1, 7, -1, 0},
    {data_020f07d8, 8, -1, 0},
    {data_020f07df, 9, -1, 0},
    {0, -1, -1, 0},
};
