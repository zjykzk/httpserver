#include <string.h>
#include <stddef.h>

#include "request.h"
#include "bmacro.h"
#include "slist.h"

typedef struct {
    char *key;
    char *value;

    _bd_list_node_t link;
} _bd_kventry_t;

typedef struct {
    char *key;
    char *value;
    char *domain;
    char *path;

    _bd_list_node_t link;
} _bd_cookie_t;

struct _bd_request {
    _bd_method_t method;
    const char *path;
    _bd_kventry_t *params;
    _bd_kventry_t *headers;
    _bd_cookie_t *cookie;
};

#define INIT_REQUEST(r) { UNKNOW, NULL, NULL, NULL }

const char *
get_cookie(const _bb_request_t *request, const char *name, const char *domain, const char *path) {
    assert(name != NULL);
    _bd_cookie_t *cookie = request->cookie;
    if (cookie == NULL) 
        return NULL;
    _bd_list_node_t *pos;
    list_for_each(pos, &cookie->link) {
        cookie = list_entry(pos, _bd_cookie_t, link);
    }
    return NULL;
}

static __inline const char *
get_value(_bd_list_node_t *list, const char *key) {
    _bd_list_node_t *pos;
    list_for_each(pos, list) {
        _bd_kventry_t *param = list_entry(pos, _bd_kventry_t, link);
        if (strcmp(param->key, key) == 0) {
            return param->value;
        }
    }
    return NULL;
}

const char *
get_param(const _bb_request_t *request, const char *name) {
    assert(name != NULL);
    return request->params == NULL ? NULL : get_value(&request->params->link, name);
}

const char *
get_header(const _bb_request_t *request, const char *name) {
    assert(name != NULL);
    return request->headers == NULL ? NULL : get_value(&request->headers->link, name);
}

__inline _bb_method_t
get_method(const _bb_request_t *request) {
    return request->method;
}

__inline const char *
get_path(const _bb_request_t *request) {
    return request->path;
}

const _bb_request_t *
parse(const char *buf, size_t len) {
    return NULL; // TODO
}

