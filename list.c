#include <stdlib.h>
#include "list.h"

List *initList() {
    List *list = malloc(sizeof(*list));
    list->last = NULL;
    return list;
}
void listUnshiftId(List *list, int id) {
    if (list == NULL) {
        exit(EXIT_FAILURE);
    }
    Element *elem = malloc(sizeof(*elem));
    elem->id = id;
    elem->previous = NULL;
    if(list->last != NULL) {
        elem->previous = list->last;
        list->last = elem;
    } else {
        list->last = elem;
    }
}
int listShiftId(List *list) {
    int id = 0;
    if (list == NULL) {
        exit(EXIT_FAILURE);
    }
    if (list->last != NULL) {
        Element *elem = list->last;
        id = elem->id;
        list->last = list->last->previous;
        free(elem);
    }
    return id;
}

