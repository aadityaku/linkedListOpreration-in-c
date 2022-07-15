#include<stdio.h>
#include<malloc.h>

#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *start = NULL;
struct node *createAll(struct node *);
struct node *display(struct node *) ;
struct node *insertBeg(struct node *);
struct node *insertEnd(struct node *);
struct node *insertBefore(struct node *);
struct node *insertAfter(struct node *);
struct node *deleteBeg(struct node *);
struct node *deleteEnd(struct node *);
struct node *deleteNode(struct node *);
struct node *deleteAfter(struct node *);
struct node *deleteList(struct node *);
struct node *sortList(struct node *);

int main(){
	int option;
	
	do{
		printf("\n \n *************MAIN MENU ***************");
		printf("\n 1. Create a list");
		printf("\n 2. display the list");
		printf("\n 3. Add node at the beging");
		printf("\n 4. Add node at the end");
		printf("\n 5. Add a node before a given node");
		printf("\n 6. Add a node after a given node");
		printf("\n 7. Delete from the beging ");
		printf("\n 8. Delete from the end");
		printf("\n 9. Delete by given node");
		printf("\n 10. Delete after a given a node");
		printf("\n 11. Delete Entire List");
		printf("\n 12. Sort the list");
		printf("\n 13. Exit");
		printf("\n *************************");
		printf("\n Enter chose any option");
		scanf("%d  ",&option);
		switch(option){
			case 1:
				start=createAll(start);
				printf("\n Linked list created");
				break;
			case 2 :
				start=display(start);
				break;
			case 3 :
				start= insertBeg(start);
				break;
			case 4:
				start=insertEnd(start);
				break;
			case 5:
				start = insertBefore(start);
				break;
			case 6:
				start= insertAfter(start);
				break;
			case 7:
				start = deleteBeg(start);
				break;
			case 8:
				start= deleteEnd(start);
				break;
			case 9:
				start = deleteNode(start);
				break;
			case 10 : 
				start = deleteAfter(start);
				break;
			case 11 :
				start = deleteList(start);
				printf("\n Linked ist is deleted");
				break;
			case 12 :
				start = sortList(start);
				break;
		}
		
		
	}while(option !=13);
	
	return 0;
	
}
struct node *createAll(struct node *start){
	struct node *new_node,*ptr;
	int num;
	printf("\n Enter -1 to end ");
	printf("\n Enter the data");
	scanf("%d",&num);
	while(num != -1){
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node->data = num;
		if(start == NULL){
			new_node->next=NULL;
			start = new_node;
		}
		else{
			ptr = start;
			while(ptr->next !=NULL){
				ptr=ptr->next;
			}
			ptr->next=new_node;
			new_node->next = NULL;
		}
		printf("\n Enter the data:");
		scanf("%d ",&num);
	}
	return start;
}

struct node *display(struct node *start){
    struct node *ptr;
    ptr = start;
    printf("[ :");
    while(ptr != NULL){
        printf("\t %d",ptr->data);
        ptr=ptr->next;
    }
    printf(": ]");
    return start;
}
struct node *insertBeg(struct node *start){
    struct node *new_node;
    int num;
    printf("\n Eneter the data");
    scanf("%d ",&num);
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    start = new_node;
    return start;
}

struct node *insertEnd(struct node *start){
    struct node *new_node,*ptr;
    int num;
    printf("\n Enter data");
    scanf("%d ",&num);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    ptr = start;
    while(ptr->next !=NULL){
        ptr=ptr->next;
    }
    ptr->next = new_node;
    return start;
    
}
struct node *insertBefore(struct node * start){
    struct node *new_node,*ptr,*prePtr;
    int num,pos;
    printf("\n Enter data ");
    scanf("%d ",&num);
    printf("\n Enter the position for Before inserted data");
    scanf("%d ",&pos);
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while(ptr->data !=pos){
        prePtr = ptr;
        ptr=ptr->next;
    }
    prePtr->next=new_node;
    new_node->next = ptr;
    return start;
}
struct node *insertAfter(struct node *start){
    struct node *new_node,*ptr,*prePtr;
    int num,pos;
    printf("\n Enter data");
    scanf("%d ",&num);
    printf("\n Enter Position After inserted data");
    scanf("%d ",&pos);
    new_node=(struct node*)malloc(sizeof(struct node));
    ptr=start;
    prePtr=ptr;
    while(prePtr->data != pos){
        prePtr=ptr;
        ptr=ptr->next;
    }
    prePtr->next=new_node;
    new_node->next=ptr;
    return start;
    
}
struct node *deleteBeg(struct node *start){
    struct node *ptr;
    ptr=start;
    start=start->next;
    free(ptr);
    return start;
}
struct node *deleteEnd(struct node *start){
    struct node *ptr,*prePtr;
    ptr=start;
    while(ptr->next !=NULL){
        prePtr = ptr;
        ptr=ptr->next;
    }
    prePtr->next = NULL;
    free(ptr);
    return start;
}
struct node *deleteNode(struct node *start){
    struct node *ptr,*prePtr;
    int pos;
    printf("\n Enter Node for deleted");
    scanf("%d ",&pos);
    ptr=start;
   if(ptr->data == pos){
       start = deleteBeg(start);
       return start;
   }
   else{
        while(ptr->data != pos){
        prePtr=ptr;
        ptr=ptr->next;
    }
    prePtr->next=ptr->next;
    free(ptr);
    return start;
   }
}
struct node *deleteAfter(struct node *start){
    struct node *ptr,*prePtr;
    int pos;
    printf("\n ENter node for after delete data");
    scanf("%d ",&pos);
    ptr=start;
    while(ptr->data != pos){
        prePtr=ptr;
        ptr=ptr->next;
    }
    prePtr->next=ptr->next;
    free(ptr);
    return start;
}
struct node *deleteList(struct node *start){
    struct node *ptr;
    ptr=start;
    while(ptr->next !=NULL){
        printf("\n %d is to be deleted next",ptr->data);
        start=deleteBeg(start);
        ptr=ptr->next;
    }
    return start;
}

struct node *sortList(struct node *start){
    struct node *ptr1,*ptr2;
    int temp;
    ptr1 = start;
    while(ptr1->next !=NULL){
        ptr2=ptr1->next;
        while(ptr2->data !=NULL){
            if(ptr1->data > ptr2->data){
                temp=ptr1->data;
                ptr1->data=ptr2->data;
                ptr2->data=temp;
            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    return start;
}
