#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "list.h"


struct list_head *getCutNode(struct list_head *head)
{
    // turtle and rabbit
    struct list_head *turtle, rabbit;

    turtle = head->next;
    rabbit = head->next;
    while ((rabbit->next->next != head) && (rabbit->next != head)) {
        rabbit = rabbit->next->next;
        turtle = turtle->next;
    }


    return turtle;
}

void div(struct list_head *head,
         struct list_head *left,
         struct list_head *right)
{
    if (list_empty(head) || list_is_singular(head))
        return;

    struct list_head *midNode = getCutNode(head);

    list_cut_position(left, head, midNode);
    list_cut_position(right, midNode->next, head->prev);
}

void merge(struct list_head *head,
           struct list_head *left,
           struct list_head *right)
{
}

void mergeSort(struct list_head *head)
{
    if (list_is_singular(head) || list_empty(head))
        return;

    struct list_head subLeft, subRight;
    INIT_LIST_HEAD(&subLeft);
    INIT_LIST_HEAD(&subRight);

    // div list to left and right
    div(head, subLeft, subRight);
    // continue div until
    mergeSort(subLeft);
    mergeSort(sunRight);
    merge(head, subLeft, subRight);
}


int main(void)
{
    return 0;
}