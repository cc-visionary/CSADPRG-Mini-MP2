#include <stdio.h>
#include <stdlib.h>
#include "set.h"

// https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/

Set *create() {
    Set* set = (Set*)malloc(sizeof(Set));
    if(set == NULL) {
        printf("Out of Memory Space");
        exit(0);
    }
    set->data = NULL;
    set->next = NULL;
    return set;
}

// adds element in its order
Set *add(Set** s, int e) {
    Set *first = *s, *ptr = *s, *prev, *t;
    // if current data is null, add that data to current node
    if(first->data == NULL) first->data = e;
    // if not, then add new node
    else {
        Set* temp = create();
        temp->data = e;
        if(ptr->data < e) {
            while(ptr->next != NULL) {
                // check first if next index is greater than element to be added
                t = ptr->next;
                // if it is break
                if(t->data > e) break;
                ptr = ptr->next;
            }
            temp->next = ptr->next;
            ptr->next = temp;
        } else {
            // else if element to be added is smaller from the first element, add that element at the beginning
            temp->next = first;
            first = temp;
            *s = temp;
        }   
    }
    return first;
}

// NOTE: sunion was used because "union" is a keyword in C
Set *sunion(Set *s1, Set *s2) {
    Set *combined = create(), *ptr1 = s1, *ptr2 = s2, *first;
    first = combined;
    while(ptr1 != NULL || ptr2 != NULL) {
        // if ptr1 is null but ptr2 is not
        if(ptr1 == NULL && ptr2 != NULL) {
            add(&combined, ptr2->data);
            ptr2 = ptr2->next;
        // if ptr1 is not null but ptr2 is
        } else if(ptr1 != NULL && ptr2 == NULL) {
            add(&combined, ptr1->data);
            ptr1 = ptr1->next;
        // if ptr1's data is bigger than ptr2, add ptr2 first, since it is smaller
        } else if(ptr1->data > ptr2->data) {
            add(&combined, ptr2->data);
            ptr2 = ptr2->next;
        // if not then add ptr1's data since it is smaller, or if ptr1 is not null but ptr2 is
        } else {
            add(&combined, ptr1->data);
            ptr1 = ptr1->next;
        }
    }
    return first;
}

Set *intersection(Set *s1, Set *s2) {
    Set *intersected = create(), *ptr1 = s1, *ptr2 = s2, *first;
    first = intersected;
    while(ptr1 != NULL) {
        ptr2 = s2;
        while(ptr2 != NULL) {
            if(ptr1->data == ptr2->data) {
                add(&intersected, ptr1->data);
                break;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }

    return first;
}

Set *difference(Set *s1, Set *s2) {
    Set *differentiated = create(), *ptr1 = s1, *ptr2, *first;
    first = differentiated;
    
    while(ptr1 != NULL) {
        ptr2 = s2;
        int doesExist = 0; // determines whether or not the current index exists
        while(ptr2 != NULL && !doesExist) {
            if(ptr1->data == ptr2->data) doesExist = 1;
            ptr2 = ptr2->next;
        }
        // if that thing doesnt exist, add it.
        if(!doesExist) add(&differentiated, ptr1->data);
        ptr1 = ptr1->next;
    }
    
    return first;
}

void print(Set *s) {
    Set *ptr = s;
    printf("{ ");
    while(ptr != NULL) {
        if(ptr->data != NULL) printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("}");
    printf("\n");
}