#include "alist.h"
//#include <alist.o>
#include "bool.h"
#include "llist.h"
#include <stdlib.h>

llist_t* llaloc(int val){
	struct llist *new_llist = malloc(sizeof(struct llist));
	new_llist->val = val;
	new_llist->next = NULL;
	return new_llist;
};

llist_t* copy(llist_t *lst){
	struct llist *copy_llist = malloc(sizeof(struct llist));
	struct llist *temp_llist= NULL;
	struct llist *preCopy = NULL;
	while(lst != 0){
		if(copy_llist == NULL){
			exit(1); //allocation failed	
		//	return;
		}
		//copy the data from the source to destination node
		copy_llist->val = lst->val;
		copy_llist->next = 0;
		if(temp_llist == NULL){ //keep the root for the destination list
			temp_llist = copy_llist;
			preCopy = copy_llist;
		}
		else{
			//point the newly created node to the previous created node
			preCopy->next = copy_llist;
			//keep the new node to use it as previous node in next node creation
			preCopy = copy_llist;
		}
		lst = lst->next;
	}
	return temp_llist;
};

llist_t* convert(unsigned int *arr, unsigned int size){
	if (size > 0){
		struct llist *convert_llist = llaloc(arr[0]);
		struct llist *head = convert_llist;
		int i;
		for(i = 1; i < size; i++){
			convert_llist->next = llaloc(arr[i]);
			convert_llist = convert_llist->next;
		}
		return head;
	}
	return NULL; //size is 0 or less
};

proof_t* tort_hare(llist_t *lst){
	llist_t* tort = lst->next;
	llist_t* tort2 = lst;
   	llist_t* hare = lst->next->next;
	proof_t* returnProof = malloc(sizeof(proof_t));
//	proof_t* no = malloc(sizeof(proof_t));
    	//do{
	while(hare && hare->next){
	//	hare = hare->next->next;
               // tort = tort->next;
       		if (hare != NULL && hare != tort && returnProof->return_val != -1){
            		returnProof->return_val = -1;
        	}
	//	hare = hare->next->next;
        	if(hare == tort ){
            		returnProof->proof = &tort->val;
           		//returnProof->proof = lst;
			//return returnProof;
			
			while(tort2 && tort){
				tort2 = tort2->next;
				tort = tort->next;
				if(tort2 == tort){
					returnProof->return_val = tort->val;
					return returnProof;
				}
			}
        	}
		hare = hare->next->next;
		tort = tort->next;
		
    	}//while(hare && hare->next);
	return NULL;
};

proof_t* rev_cycle(llist_t *lst, int num){
	llist_t *head = lst, *prev = NULL, *current = lst, *next = NULL, *list = lst;
//	int valcount = 0;
//	struct proof *rev_proof	= calloc(num  , sizeof(struct proof));
	
	struct proof *rev_proof = malloc(sizeof(struct proof)); //good
	rev_proof->proof = calloc(num, sizeof(int *)); //good
	//rev_proof->return_val = malloc(sizeof(int));
//	for(int i = 0; i < num; i++){		
	if(lst == NULL){
		//free(rev_proof);
		rev_proof->return_val= -1;
		return rev_proof; //no cycle
	}
/*
	//do{
	while(current !=NULL){
		if(current->next != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		}
	}//}while(current != NULL);	
	lst = prev;
*/
	int n = 1, condition = 0, checkval = 0, valcount = 0;
	int *arr = malloc(sizeof(*arr)*50);
	//code below in this while statement checks for 2 instances of a val (indication of where loop begins)
	//while simultaneosly scaling the arry to be big enough to hold the values
	while(condition == 0 && list !=NULL){
		arr = realloc(arr, sizeof(*arr) * (n+1));
		arr[n] = &list->val;
		for(int j = 0; j < n; j++){
			checkval = arr[n];
			if(arr[j] = checkval){
				valcount++;
			}
			if(valcount == 2){
				rev_proof->return_val = arr[j];
				condition = 1;
			}
			valcount = 0;
		}
		n++;
		list = list->next;
	}
//INFINITE LOOP BELOW, BUT COMPILES WITH NO ERRORS
	int loopcount = 0;
	 while(current !=NULL && loopcount != n){
                if(current->next != NULL){
            	   	next = current->next;
               		current->next = prev;
               		prev = current;
                	current = next;
                }
		loopcount = loopcount + 1;
	
        }//}while(current != NULL);
        lst = prev;
	for(int i = 0; i < num; i++){
		rev_proof->proof[i] = lst;
		lst = lst->next;
	}
	return rev_proof;
	
/*			rev_proof->proof[i] = lst->val; //good
			
			for(int j = 0; j < i; j++){
				valcount = 0;
				if (rev_proof->proof[j] == lst->val){
					valcount++;
				}
				if(valcount >= 2){
					rev_proof->return_val = lst->val;
					return rev_proof;
				}
			}		
		lst = lst->next;
	}
//	return NULL;
*/

};






