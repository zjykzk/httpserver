#ifndef _SLIST_H_
#define _SLIST_H_

#include "bmacro.h"

typedef struct _bd_slist_node _bd_slist_node_t;

struct _bd_slist_node {
    _bd_slist_node_t *next;
};

#define SLIST_INIT(h) { &(h) }

#define container_of(member_ptr, container_type, member)      \
    ((container_type *)                                       \
     (((char *) member_ptr) - __offset(container_type, member)))

#define list_entry(member_ptr, container_type, member) \
    container_of(member_ptr, container_type, member)

#define list_for_each(pos, header) \
    for (pos = (header)->next;     \
            __prefetch(pos->next), pos != header; pos = pos->next)

static __inline _bd_slist_node_t
list_add(_bd_slist_node_t *header, _bd_slist_node_t *node) {
    node->next = header->node;
    header->node = node;
    return header;
}

#endif /* _SLIST_H_ */
