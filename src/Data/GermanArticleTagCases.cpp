// func_020e4958 expands article tags using one of four grammatical cases.
// Cases choose a six-byte GermanArticles entry; zero tagLength ends the scan.
struct GermanArticleTagCase { signed char articleIndex[4]; const char* tag; signed char tagLength; signed char reserved[3]; };
extern "C" {
extern char data_020f2d04[];
extern char data_020f2cf8[];
extern char data_020f2cfe[];
extern char data_020f2d12[];
extern char data_020f2d1a[];
extern char data_020f2d22[];
extern char data_020f2d0a[];
}
extern "C" const GermanArticleTagCase data_020eea50[8] = {
    {{0, 1, 2, 3}, data_020f2d04, 5, {0, 0, 0}},
    {{4, 0, 0, 4}, data_020f2cf8, 5, {0, 0, 0}},
    {{5, 1, 2, 5}, data_020f2cfe, 5, {0, 0, 0}},
    {{4, 0, 3, 4}, data_020f2d12, 7, {0, 0, 0}},
    {{6, 7, 8, 9}, data_020f2d1a, 7, {0, 0, 0}},
    {{10, 11, 11, 10}, data_020f2d22, 7, {0, 0, 0}},
    {{6, 7, 8, 6}, data_020f2d0a, 7, {0, 0, 0}},
    {{-1, -1, -1, -1}, 0, 0, {0, 0, 0}},
};
