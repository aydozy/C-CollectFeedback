#include <stdio.h>
#include <stdlib.h>

//step1: node struct
struct Node
{
    struct Node* next;
    int userID;
    int itemID;
    float ratingValue;
};

 struct LinkedList
{
    struct Node *head;
};

//step2: insert method
void insert(int userID, int itemID, float ratingValue,struct LinkedList *linkedList)
{
    struct Node *current = linkedList->head;

    while(current != NULL)
    {
        if(current->userID == userID && current->itemID == itemID)
        {
            current->ratingValue = ratingValue;
            printf("Customer rating (%d,%d) is added updated\n",userID,itemID);
            return;
        }
        else
        {
            current = current->next;
        }
    }
    // allocate node
    struct Node *linked = malloc(sizeof(struct Node));
    //put in data
    linked->userID = userID;
    linked->itemID = itemID;
    linked->ratingValue = ratingValue;
    //make next of linked as head
    linked->next = linkedList->head;
    //move the head to point to the linked
    linkedList->head = linked;
    printf("Customer rating (%d, %d) is added successful.\n",userID,itemID);
}

//step3: remove method
void removeRemove(int userID, int itemID,struct LinkedList *linkedList)
{
    struct Node *current = linkedList->head;
    struct Node *previous = NULL;

    if(current == NULL)
    {
        printf("Customer rating (%d, %d) does not exist.\n",userID,itemID);
        return;
    }

    while(current != NULL)
    {
        if(current->userID == userID && current->itemID == itemID)
        {
            if(previous == NULL)
            {
                linkedList->head = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            free(current);
            printf("Customer rating (%d, %d) is removed successfully.\n", userID, itemID);
        }
    }


}

// step4: rating method
void rating (int userID, int itemID,struct LinkedList *linkedList)
{
    struct Node *current = linkedList->head;
    while(current != NULL)
    {
        if(current->userID == userID && current->itemID == itemID)
        {
            printf("Customer rating (%d,%d) is: %.1f \n",current->userID,current->itemID,current->ratingValue);
            return;

        }
        else
        {
            current = current->next;
        }

    }

    printf("Customer rating (%d,%d) is: 0.0 \n",userID,itemID);

}

// step5: average method
void average(int itemID, struct LinkedList *linkedList)
{
    struct Node *current = linkedList->head;
    int numberOfItems = 0;
    double ratingSum = 0;

    while (current != NULL)
    {
        if (current->itemID == itemID)
        {
            ratingSum += current->ratingValue;
            numberOfItems++;
        }
        current= current->next;
    }

    if(numberOfItems == 0)
    {
        printf("Average rating (%d) is: 0.0\n", itemID);
    }
    else
    {
        double avg = (double) ratingSum / numberOfItems;
        printf("Average rating (%d) is: %.1f \n",itemID,avg);
    }

}

int main()
{

    struct LinkedList linkedList = { NULL, 0 };
    char command[30]; //command string
    int userID, itemID;
    float ratingValue;


    while(1)
    {
        scanf("%s", command);
        if(strcmp("break",command)==0 ||strcmp("\nbreak",command)==0 || strcmp("break\n",command)==0)
        {
            break;
        }
        if (strcmp(command, "INSERT") == 0)
        {
            scanf("%d %d %f",&userID, &itemID, &ratingValue);
            insert(userID,itemID,ratingValue,&linkedList);
        }
        else if (strcmp(command, "REMOVE") == 0)
        {
            scanf("%d %d",&userID, &itemID);
            removeRemove(userID, itemID, &linkedList);
        }
        else if (strcmp(command, "RATING") == 0)
        {
            scanf("%d %d",&userID, &itemID);
            rating(userID, itemID, &linkedList);
        }
        else if (strcmp(command, "AVERAGE") == 0)
        {
            scanf("%d",&itemID);
            average(itemID, &linkedList);
        }
    }

}
