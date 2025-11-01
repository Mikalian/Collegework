#include "linked_list.h"
#include <stdlib.h>

typedef struct list_node {
   struct list_node *prev, *next;
   ll_data_t data;
}node;

struct list {
   struct list_node *first, *last;
};

struct list *list_create(void){
    struct list * new_list = malloc(sizeof(struct list));
    if(!new_list){
        return NULL; //Allocation error. 
    }
    new_list->first = NULL;
    new_list->last = NULL;
    
    return new_list; //Returns pointer to the new list.
}

void list_push(struct list *list, ll_data_t item_data){
    node * new_node = malloc(sizeof(node));
    if (!new_node) {
        list_destroy(list);
        return; //Allocation error.
    }

    new_node->data = item_data;
    new_node->next = NULL;
    new_node->prev = list->last;
    
    //If list empty.
    if(list->first == NULL){
        list->first = new_node;
    }
    else{
        list->last->next = new_node;
    }
    list->last = new_node;
}

void list_unshift(struct list *list, ll_data_t item_data){
    //If empty we can simply do a list push.
    if (list->first == NULL){
        list_push(list,item_data);
        return;
    }
    
    node * new_node = malloc(sizeof(node));
    if (!new_node) {
        list_destroy(list);
        return; //Allocation error.
    }
    new_node->prev = NULL;
    new_node->data = item_data;
    new_node->next = list->first;
    list->first->prev = new_node;
    list->first = new_node;
}

ll_data_t list_pop(struct list *list){
    
    //If empty.
    if(list->first == NULL){
        return -1;
    }
    
    ll_data_t deleted_data = list->last->data;
    node * to_delete = list->last;

    //If not the only node in the list.
    if (list->last->prev != NULL){
         list->last->prev->next = NULL;
    }
    else{
        list->first = NULL;
    }
    list->last = list->last->prev;  
    free(to_delete);
    
    return deleted_data;
}

ll_data_t list_shift(struct list *list){
    
    //If empty.
    if(list->first == NULL){
        return -1;
    }
    
    ll_data_t deleted_data = list->first->data;
    node * to_delete = list->first;

    //If not the only node in the list.
    if (list->first->next != NULL){
         list->first->next->prev = NULL;
    }
    else{
        list->last = NULL;
    }
    
    list->first = list->first->next;  
    free(to_delete);
    
    return deleted_data;
}

void list_delete(struct list *list, ll_data_t data) {
    
    node * curr = list->first;
    node * to_delete = NULL;

    //If list empty.
    if(list->first == NULL){
        return;
    }

    while (curr != NULL) {
        if (curr->data == data) {
            to_delete = curr;

            if (curr->prev != NULL) {
                curr->prev->next = curr->next;
            } 
            else{
                list->first = curr->next;
            }
            if (curr->next != NULL) {
                curr->next->prev = curr->prev;
            } 
            else{
                list->last = curr->prev;
            }
            curr = curr->next; 
            free(to_delete);

            break; //Stops to only delete the first occurance.
        } else {
            curr = curr->next;
        }
    }
}

size_t list_count(const struct list *list){
    node * curr = list->first;
    size_t count = 0;
    
    while (curr != NULL){
        count++;
        curr = curr->next;
    }
    return count;
}

void list_destroy(struct list *list){
    node * curr = list->first;
    node * to_delete = NULL;
    while(curr != NULL){
        to_delete = curr;
        curr = curr->next;
        free(to_delete);
    }
}
