#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int cyber=0,digital=0 ,polymer=0 ,project=0 ,invest=0 ,ruby=0,n;
int seat=4;
struct node
{
	char name[10];
	char choice1[10];
	char choice2[10];
	char choice3[10];
	float cgpa;
	int roll;
	struct node *link;
	char choice_granted[10];	
};



int selector(char *z, struct node *a){
 char arr[10][10]={"cyber", "polymer","project","ruby","digital","investment"};
 
 if(strcmp(z,arr[0]))
 {
 	
 	if(cyber<seat)
 	{
 		strcpy(a->choice_granted,"CyberLaw");
 		//z->choice_granted[10]={'C','y','b','e','r'};
 		//a->choice_granted[10]="cyber law";
 		cyber++;
 		return 1;
	 }
	 else{
	 
	 return 0;
 	}
 }


else if(strcmp(z,arr[1]))
 {
 	if(polymer<seat)
 	{
 		strcpy(a->choice_granted,"POLYMER COMPOSITE");
 		//z->choice_granted[10]="POLYMER COMPOSITE";
	 	polymer++;
	 	return 1;
	 }
	 else{
	 	return 0;
	 }
 }
 else if(strcmp(z,arr[2]))
 {
 	
 	if(project<seat)
 	{
 		strcpy(a->choice_granted,"PROJECT MANAGEMENT");
 		//z->choice_granted[10]="PROJECT MANAGEMENT";
	 	project++;
	 	return 1;
	 }
	 else{
	 	return 0;
	 }
 }
 else if(strcmp(z,arr[3]))
 { 
 	if(ruby<seat)
 	{
 		strcpy(a->choice_granted,"RUBY ON RAILS");
 		//z->choice_granted[10]="RUBY on Rails";
	 	ruby++;
	 	return 1;
	 }
	 else{
	 	return 0;
	 }
 }
 else if(strcmp(z,arr[4]))
 {
 	
 	if(digital<seat)
 	{
	 
	 strcpy(a->choice_granted,"DIGITAL MARKETING");
 		//z->choice_granted[10]="DIGITAL MARKETING";
	 	digital++;
	 	return 1;
	 }
	 else{
	 	return 0;
	 }
 }
 else if(strcmp(z,arr[5]))
 {
 	if(invest<seat)
 	{
 		strcpy(a->choice_granted,"INVESTMENT MANAGEMENT");
 		//z->choice_granted[10]="INVESTMENT MANAGEMENT";
	 	invest++;
	 	return 1;
	 }
	 else{
	 	return 0;
	 }
 } 
 
}


//structure defination

struct node *ptr,*temp,*rear=NULL;				// structure pointers

// insert function
void insert()
{
		
	char name[10];
	char choice1[10];
	char choice2[10];
	char choice3[10];
	float cgpa;
	int roll;
	// get information 
	printf("\t**ENTER YOUR NAME and Roll No. to LOGIN**\n");
	printf("\tNAME:");
	scanf("%s",name);
	printf("\tRoll no.");
	scanf("%d",&roll);
	printf("\nEnter your CGPA:");
	scanf("%f",&cgpa);
	printf("\nEnter your 1st Choice:");
	scanf("%s",choice1);
	printf("\nEnter your 2nd Choice:");
	scanf("%s",choice2);
	printf("\nEnter your 3rd Choice:");
	scanf(" %s",choice3);	
	
	// information stored in database
	FILE *fp=fopen("entry_list.txt","a");
	fprintf(fp,"\n %s %d \t %f \t %s \t %s \t %s \t", name,roll,cgpa,choice1,choice2,choice3);
	fclose(fp);
	// memory allocation to new node
	temp=(struct node*)malloc(sizeof(struct node));

	
	// inputting value in the new node	
	temp->cgpa=cgpa;
	temp->roll=roll;
	strcpy(temp->name,name);	
	strcpy(temp->choice1,choice1);
	strcpy(temp->choice2,choice2);
	strcpy(temp->choice3,choice3);
	
	temp->link=NULL;
	
	//inserting the new node at end		
	if(rear==NULL)
		{
		ptr=rear=temp;
		}
	else{
		rear->link=temp;
		rear=rear->link;
		}
	

}


/* Bubble sort the given linked lsit with parameter n which is total no. of nodes */
void bubbleSort(int n)
{
	 int i, j, k;
	 float temp ;
    struct node *p, *q ;

    k = n ;
    for ( i = 0 ; i < n - 1 ; i++, k-- )
    {
        p = ptr ;
        q = p -> link ;

        for ( j = 1 ; j < k ; j++ )
        {
            if ( p -> cgpa < q -> cgpa )
            {
                temp = p -> cgpa ;
                p -> cgpa = q -> cgpa ;
                q -> cgpa = temp ;
            }
            p = p -> link ;
            q = q -> link ;
        }
    }
}
   

 // count function to count no. of nodes in liked list
int count ( struct node * q )
{
    int c = 0 ;

    /* traverse the entire linked list */
while ( q != NULL )
    {
        q = q -> link ;
        c++ ;
    }

    return c ;
}


// main function starts
 void main()
{
	// printing of menue
	printf("\t *****WELCOME TO OPEN ELECTIVE CHOICES*****\n");
	printf("____List Of Choices____\n");
	printf(" 1. Cyber Law\n 2.Digital Marketing\n 3.Polymer Composite\n 4.Project Management\n 5.Investment Management\n 6.Ruby on Rails\n ");
	printf("\n Every Elective has only %d seats\n",seat );
	
	char ch='y';
	
	// loop for data entry by user
	while(ch=='y'|| ch=='Y')
	{	
	insert();
	printf("you want to enter more? y/n");
	scanf(" \t %c" ,&ch);
	}
	
	// counting no. of nodes
	int x;
	x= count(ptr);
	printf("%d",x);
	printf("\n \n \t Total No. of Entries %d\n",x);
	// bubble sort of the linked list
	bubbleSort(x);
	
	// no more entries in database
 	printf("\t _____Entry has Been Closed.!_____");
	FILE *fp=fopen("entry_list.txt","a");
	fprintf(fp,"\n\n\t __________**********ENTRY has CLOSED**********__________\n \n \n");
	fprintf(fp,"\n\n\t __________**********THIS is a SORTED LIST**********__________\n \n \n");
	struct node *a = ptr;
	
	int catch,catch1;
	while(a!=NULL)
	{
	catch=selector(a->choice1, a);
	if(catch==0)
	{
		catch1=selector(a->choice2, a);
		{
		if(catch1==0)
		catch=selector(a->choice3, a);
		}
	
		
	}
	a=a->link;
	
	
}
		FILE *fp1=fopen("final_list.txt","a");
		fprintf(fp1,"\t \t********THIS IS THE FINAL LIST OF ALLOTED COURSES**********\n \n \n");
		printf("\t \t********THIS IS THE FINAL LIST OF ALLOTED COURSES**********\n \n \n");
		
	/*   IT IS TO PRINT THE SORTED LIST*/
	struct node *tem = ptr;
    printf("\n");
    int c=0;
    while (tem!=NULL)
    {       
       fprintf(fp,"\n %s %d \t %f \t %s \t %s \t %s \t", tem->name,tem->roll,tem->cgpa,tem->choice1,tem->choice2,tem->choice3,tem->choice_granted);
	   fprintf(fp1,"%s_______%d_______%f_______\t CHOICE GRANTED: %s \n \n",tem->name,tem->roll,tem->cgpa,tem->choice_granted);
		//fprintf(fp,"\n %s %d \t %f \t %s \t %s \t %s \t", tem->name,tem->roll,tem->cgpa,tem->choice1,tem->choice2,tem->choice3,tem->choice_granted);
	   printf("\n %s_______%d_______%f_______\t CHOICE GRANTED: %s \n \n",tem->name,tem->roll,tem->cgpa,tem->choice_granted);
		tem = tem->link;
        c++;
        
    }
	fclose(fp);
	fclose(fp1);
	printf("\n \n \t **** SEATS HAS BEEN ALLOTED*****");
	
}



