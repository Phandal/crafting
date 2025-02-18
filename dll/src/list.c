#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

void node_destroy(node_t *node) {
  if (node->string != NULL) {
    free(node->string);
  }

  free(node);
}

node_t *node_init(char *string) {
  node_t *node = calloc(1, sizeof(node_t));
  if (node == NULL) {
    return NULL;
  }

  size_t length = strlen(string) + 1;
  node->string = calloc(length, sizeof(char));
  if (node->string == NULL) {
    node_destroy(node);
    return NULL;
  }

  strncpy(node->string, string, length);
  return node;
}

list_t *list_init(void) { return (list_t *)calloc(1, sizeof(list_t)); }

node_t *list_end(list_t *list) {
  assert(list != NULL);
  assert(list->head != NULL);

  node_t *node = list->head;
  while (node != NULL && node->next != NULL) {
    node = node->next;
  }

  return node;
}

ListResult list_add(list_t *list, char *string) {
  node_t *new = node_init(string);

  if (list->head == NULL) {
    list->head = new;
  } else {
    node_t *end = list_end(list);
    end->next = new;
    new->prev = end;
  }
  return List_OK;
}

void list_destroy(list_t *list) {
  if (list == NULL) {
    return;
  }

  node_t *temp, *node = list->head;
  while (node != NULL) {
    temp = node;
    node = temp->next;
    node_destroy(temp);
  }
}