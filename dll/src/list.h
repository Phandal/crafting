#ifndef DLL_H
#define DLL_H

typedef enum {
  List_OK,
  List_ERROR,
} ListResult;

typedef struct node {
  char *string;
  struct node *next;
  struct node *prev;
} node_t;

typedef struct list {
  node_t *head;
} list_t;

/**
 * Initializes a new list
 */
list_t *list_init(void);

ListResult list_add(list_t *list, char *string);

/**
 * Destroys a list as well as all the elements in the list
 */
void list_destroy(list_t *list);

#endif // DLL_H
