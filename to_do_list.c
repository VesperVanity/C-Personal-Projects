#include <stdio.h>

void create_task_string(int task_count, int is_style_numbered);

//No clue how to set that up just in the command line without any GUI
//So let's just create the general functionality and print it to the console

//So I suppose we need to first be capable of string inputs that will be the task string name
//"Clean your room" for example, print that input string with all other to-do-list tasks
//We can also use a mode in which it's either a bullet list, or, a numbered list
int main(void)
{
	printf("%s\n", "Type B for bullet list style, and N for numbered list style: ");
	char style = ' ';
	scanf("%c", &style);
	int is_style_numbered = 0;
	if(style == 'b' || style == 'B')
	{
		is_style_numbered = 0;
	}
	else if(style == 'n' || style == 'N')
	{
		is_style_numbered = 1;
	}
	else
	{
		printf("%s\n", "Wrong input, try again");
	}
	printf("%s\n", "This is your to-do-list, just enter a task to add it to your task list: ");
	const int TASK_AMOUNT_LIMIT = 10 + 1; 
	for(int i = 1; i < TASK_AMOUNT_LIMIT; ++i)
	{
		create_task_string(i, is_style_numbered);
	}
	return 0;
}

//Pause for now to study about printf and streams and buffers and stuff
//Every time I run the script the behavior changes, as if the last test
//Is influencing the current test from a different runtime
//Will fix it (hopefully) after learning how arrays and printf works
void create_task_string(int task_count, int is_style_numbered)
{
	int task_character_count = 0;
	char current_character = ' ';
	//Fixed array size is probably a bug and should be dynamic, I do not know how yet
	const int ARRAY_MAX_SIZE = 1000;
	char task_string[ARRAY_MAX_SIZE];
	while((current_character = getchar()) != '\n')
	{
		task_string[task_character_count] = current_character;
		++task_character_count;
	}
	task_string[task_character_count] = '\0';
	const int TASK_LIST_LIMIT = 10 + 1;
	char tasks[TASK_LIST_LIMIT][ARRAY_MAX_SIZE];
	/*
	int task_list_amount = 0;
	if(task_list_amount < TASK_LIST_LIMIT)
	{
		++task_list_amount;
	}
	*/
	for(int i = 0; i < ARRAY_MAX_SIZE; ++i)
	{
		tasks[task_count][i] = task_string[i];
	}
	for(int i = 0; i < task_count; ++i)
	{
		if(is_style_numbered == 1)
		{
			printf("%d ", task_count - i - 1);
		}
		else if(is_style_numbered == 0)
		{
			printf("%c ", 'o');
		}
		printf("%s\n", tasks[task_count - i]);
	}
	printf("\n");
	//printf("%s\n", task_string);
	//printf("%s\n", tasks[task_list_amount]);
	//printf("%d\n", task_character_count);
}