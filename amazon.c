#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct node{
	struct node *next;
	char c ; 
	short i ;  
} typedef node ; 

int main(int argc, char ** argv)
{    if(argc==1){printf("missing argument !");exit(1);}
	node *fp=NULL,*Q=NULL,*ptr=NULL;
	char *mtr=NULL;
	mtr=argv[1] ;
	fp=malloc(sizeof(node));
     (*fp).next=NULL; (*fp).c=*mtr;(*fp).i=1;
     Q=fp;
    mtr++;
    ptr=fp;
    while(*mtr!=0)
    {
    	while(ptr!=NULL)
    		{
    			if((*ptr).c==*mtr) { (*ptr).i++; goto loop ;}
    			ptr=(*ptr).next;
    		}
    		node * cel=NULL ;
    		cel=malloc(sizeof(node)); 
    		(*cel).next=NULL; (*cel).c=*mtr;(*cel).i=1;
    		(*Q).next=cel ;
    		Q=cel ;
    		loop:
    		ptr=fp;
    		mtr++;
    }
    ptr=fp ;
    while((*ptr).i!=1)
    {if((*ptr).next==NULL){printf("all the caracters are duplicated");exit(1);}ptr=(*ptr).next;}
    printf("the firt non-repeating caracter caracter is '%c'",(*ptr).c);
	return 1 ;
}

