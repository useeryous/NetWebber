#ifndef DOM_H
#define DOM_H

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

// Parser function
DOMNode* parse_dom(const char *html);

// Utility
void print_dom(const DOMNode *node, int depth);
void free_dom(DOMNode *node);

// ---- HTML5 Tags ----
extern HtmlTagInfo htmlTagType[];
extern const char *html5_tags[];
extern const int html5_tags_count;

// ---- HTML5 Attributes ----
extern const char *html5_attributes[];
extern const int html5_attributes_count;

// ---- CSS Tags and Properties ----
extern const char *css_tags[];
extern const int css_tags_count;

// ---- External HTML/CSS buffers ----
extern char *html[];
extern int html_length;

extern char *CSS[];
extern int CSS_COUNT;

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

void init_tokenizer(const char *input);
Token next_token();

// ---- Utility Functions ----
int stricmp(const char *s1, const char *s2);

int isHtmlTag(const char *tag);
int isHtmlAttribute(const char *attribute);

int isCSSTag(const char *tag);
int isCSSProperty(const char *property);

#endif // DOM_H
