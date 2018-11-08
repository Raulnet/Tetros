#ifndef TETRIS_LIST_H
#define TETRIS_LIST_H
typedef struct List List;
typedef struct Element Element;
struct Element {
    int id;
    Element *previous;
};
struct List {
    Element *last;
};

List *initList();

void listUnshiftId(List *list, int id);

int listShiftId(List *list);

#endif //TETRIS_LIST_H
