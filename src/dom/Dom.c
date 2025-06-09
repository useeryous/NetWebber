#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// ---- Tag Type Enumeration ----
typedef enum {
    TAG_BLOCK,
    TAG_INLINE,
    TAG_VOID,
    TAG_UNKNOWN
} tagType;

// ---- HTML Tag Info Struct ----
typedef struct {
    const char *name;
    tagType type;
    bool has_closing;
} HtmlTagInfo;

// =======================
// DOM Node Definition
// =======================
typedef struct DOMNode {
    char tag[32];                // Tag name or "#text"
    char text[256];              // Only used if this is a text node
    struct DOMNode *first_child;
    struct DOMNode *next_sibling;
} DOMNode;

// ---- HTML5 Tags ----
HtmlTagInfo htmlTagType[] = {
    {"div", TAG_BLOCK, true},
    {"span", TAG_INLINE, true},
    {"img", TAG_VOID, false},
    // ... add more tags as needed
};
const char *html5_tags[] = {"div", "span", "img"};
const int html5_tags_count = 3;

// ---- HTML5 Attributes ----
const char *html5_attributes[] = {"id", "class", "src"};
const int html5_attributes_count = 3;

// ---- CSS Tags and Properties ----
const char *css_tags[] = {"color", "background"};
const int css_tags_count = 2;

// ---- External HTML/CSS buffers ----
char *html[] = {NULL};
int html_length = 0;

char *CSS[] = {NULL};
int CSS_COUNT = 0;

typedef enum {
    TOKEN_TAG_OPEN,
    TOKEN_TAG_CLOSE,
    TOKEN_TAG_SELFCLOSE,
    TOKEN_TEXT,
    TOKEN_EOF,
    TOKEN_ERROR
} TokenType;

typedef struct {
    TokenType type;
    char value[256];
} Token;

// ---- Tokenizer ----
static const char *tokenizer_input = NULL;
static size_t tokenizer_pos = 0;

void init_tokenizer(const char *input) {
    tokenizer_input = input;
    tokenizer_pos = 0;
}

Token next_token() {
    Token token;
    token.type = TOKEN_EOF;
    token.value[0] = '\0';
    // Dummy implementation
    return token;
}

// ---- Utility Functions ----
int stricmp(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        int c1 = tolower((unsigned char)*s1);
        int c2 = tolower((unsigned char)*s2);
        if (c1 != c2) return c1 - c2;
        s1++; s2++;
    }
    return *s1 - *s2;
}

int isHtmlTag(const char *tag) {
    for (int i = 0; i < html5_tags_count; ++i) {
        if (stricmp(tag, html5_tags[i]) == 0) return 1;
    }
    return 0;
}

int isHtmlAttribute(const char *attribute) {
    for (int i = 0; i < html5_attributes_count; ++i) {
        if (stricmp(attribute, html5_attributes[i]) == 0) return 1;
    }
    return 0;
}

int isCSSTag(const char *tag) {
    for (int i = 0; i < css_tags_count; ++i) {
        if (stricmp(tag, css_tags[i]) == 0) return 1;
    }
    return 0;
}

int isCSSProperty(const char *property) {
    // Dummy implementation
    return 0;
}

// Parser function (stub)
DOMNode* parse_dom(const char *html) {
    // Dummy implementation
    return NULL;
}

// Utility
void print_dom(const DOMNode *node, int depth) {
    // Dummy implementation
}

void free_dom(DOMNode *node) {
    // Dummy implementation
}