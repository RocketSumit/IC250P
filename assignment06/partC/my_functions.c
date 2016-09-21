/*..............................................................................
   Name: Sumit Patidar
   Roll no: B15237
   Purpose: Assignment 06, part C
   Date: 21/09/2016
   ..............................................................................*/

#include "my_library.h"

struct randomListNode* copyRandomList (struct randomListNode *head)
{
        struct randomListNode *temp = NULL, *current = NULL;

        current = head;
        do {
                struct randomListNode *copy_node;
                copy_node = (struct randomListNode*)malloc(sizeof(struct randomListNode));
                temp = current->next;
                current->next = copy_node;
                copy_node->label = current->label;
                copy_node->next = temp;
                current = temp;
        } while(current != NULL);

        current = head;
        do {
                current->next->random = current->random->next;
                current = current->next->next;
        } while(current!= NULL);

        struct randomListNode *copy_head = NULL, *copy_current = NULL;
        current = head;
        copy_head = copy_current = current->next;

        while(copy_current->next != NULL) {
                current->next = current->next->next;
                copy_current->next = copy_current->next->next;
                current = current->next;
                copy_current = copy_current->next;
        }
        current->next = NULL; // original list ends

        return copy_head;
}

void createOriginalSinglyList(struct randomListNode **head, int identity)
{
        struct randomListNode *newNode = NULL, *current = *head;
        newNode = (struct randomListNode*)malloc(sizeof(struct randomListNode));

        newNode->label = identity;

        if(*head == NULL) {
                *head = newNode;
                newNode->next = NULL;
        }
        else{
                while(current->next != NULL) {
                        current = current->next;
                }

                current->next = newNode;
                newNode->next = NULL;
        }
}

void insertRandomLinks(struct randomListNode *head, int identity, int random_label)
{
        struct randomListNode *current_node = head, *current_random_node = head;

        //search for identity element
        // improve it further for not matching any element
        while(current_node->label != identity) {
                current_node = current_node->next;
        }

        //search for node to which current_node randomly points
        while(current_random_node->label != random_label) {
                current_random_node = current_random_node->next;
        }

        //eliminating the possibility of pointing to itself
        if(current_node == current_random_node)
                return;

        current_node->random = current_random_node;

}
