#ifndef _HTTP_REQUEST_H_
#define _HTTP_REQUEST_H_

#include <stdbool.h>

typedef struct _bd_request _bd_request_t;

typedef enum _bd_method {
    UNKNOW = -1,
    GET = 0,
    POST,
    DELETE,
    PUT,
} _bd_method_t;

const char *
get_cookie(const _bd_request_t *request, const char *name, const char *domain, const char *path);

const char *
get_param(const _bd_request_t *request, const char *name);

const char *
get_header(const _bd_request_t *request, const char *name);

_bd_method_t
get_method(const _bd_request_t *request);

const char *
get_path(const _bd_request_t *request);

const _bd_request_t *
parse(const char *buf, size_t len);

#endif /* _HTTP_REQUEST_H_ */
