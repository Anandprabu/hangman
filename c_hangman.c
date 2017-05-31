#include<stdio.h>
#include<string.h>
int flag=0;
void startup()
{
	printf("      *  *       \n");
	printf("    *      *     \n");
	printf("    *      *     \n");
	printf("     *    *      \n");
	printf("        *        \n");
	printf("     *  *  *     \n");
	printf("   *   * *   *   \n");
	printf("      *   *      \n");
	printf("     *     *     \n");
	printf("   **       **   \n");
	if(flag==0)
	{
		printf(" Will You Please Save Me...\n");	
		sleep(3);
	}
}
void hangman_out(int count)
{
	switch(count)
	{

		case 1: printf("      *  *       \n");
			printf("    *      *     \n");
			printf("    *      *     \n");
			printf("     *    *      \n");
			printf("        *        \n");
			printf("     *  *  *     \n");
			printf("   *   *     *   \n");
			printf("      *          \n");
			printf("     *           \n");
			printf("   **            \n");
			printf("Oh I lost my Left Leg\n\n");
			break;

		case 2: printf("      *  *       \n");
			printf("    *      *     \n");
			printf("    *      *     \n");
			printf("     *    *      \n");
			printf("        *        \n");
			printf("     *     *     \n");
			printf("   *         *   \n");
			printf("                 \n");
			printf("                 \n");
			printf("                 \n");
			printf("Oh I lost my Right Leg too\n\n");
			break;

		case 3: printf("      *  *       \n");
			printf("    *      *     \n");
			printf("    *      *     \n");
			printf("     *    *      \n");
			printf("        *        \n");
			printf("           *     \n");
			printf("             *   \n");
			printf("                 \n");
			printf("                 \n");
			printf("                 \n");
			printf("Oh I lost my Right Hand man... Pls do something\n\n");
			break;

		case 4: printf("      *  *       \n");
			printf("    *      *     \n");
			printf("    *      *     \n");
			printf("     *    *      \n");
			printf("        *        \n");
			printf("                 \n");
			printf("                 \n");
			printf("                 \n");
			printf("                 \n");
			printf("                 \n");
			printf("Oh my God I lost my Left Hand too and only one life is thr pls be carefull buddy!\n\n");
			break;

		case 5: printf("      *  *       \n");
			printf("    *      *     \n");
			printf("    *      *     \n");
			printf("     *    *      \n");
			printf("        * * * *  \n");
			printf("              *  \n");
			printf("              *  \n");
			printf("              *  \n");
			printf("                 \n");
			printf("                 \n");
			printf("OOPS.....You Killed Me !\n\n");
			break;	

	}	
}
void print(char *p)
{
	int iter;
	for(iter=0;p[iter];iter++)
		printf("%c ",p[iter]);
	printf("\n");
}

main()
{
	FILE *filePointer;
	char option,input,word[20],list1[20],list2[20];
	int index,wordLength,iterator,count=0;


	filePointer=fopen("tempFile","r");		//opening a file called tempFile and reading word by word from the file

	while(1)
	{
		startup();
	
		if(fscanf(filePointer,"%s",word)==-1)
		{
			printf("Game Over Buddy!\n\n");
			return;
		}
		
		wordLength=strlen(word);	
		
		printf("It is a %d letter word \n",wordLength);

		strcpy(list1,word);	

		for(iterator=0;word[iterator];iterator++)
			list2[iterator]='_';
	
		list2[iterator]='\0';


		print(list2);

		while(count<5)
		{
			if(strchr(list2,'_'))
			{
				printf("Can u pls Guess a letter?\n");	
				scanf(" %c",&input);

				if(strchr(list1,input))  
				{
					index = strchr(list1,input)-list1;

					list1[index]='_';
					list2[index]=input;  
					print(list2);
				}
				else
				{
					count=count+1;
					hangman_out(count);
					print(list2);
				}
			}
			else
			{
				printf("Thank u for saving me...\n");
				break;
			}

		}
		printf("Would u like to continue?(y/n)\n");
		scanf(" %c",&option);
		if(option=='y')
		{
			flag=1;
			continue;
		}
		else
			break;	
	}	 
}
