#include <stdio.h>

int check_year(int input_year);
void print_month_name();
void print_weekdays();
void print_month();

int main(void)
{
	printf("%s\n", "Enter the year that you want to display as a calendar, between 1800 and 2100: ");
	int input_year = 0;
	scanf("%d", &input_year);
	if(check_year(input_year) == 1)
	{
		printf("%s\n", "This is a leap year");
	}
	int month_current = 0;
	int month_max = 12;
	for(int i = 0; i < month_max; ++i)
	{
		++month_current;
		print_month_name(month_current);
		print_weekdays();
		print_month(month_current);	
	}
	return 0;
}

//Goal: Print out one full year calendar in the terminal
//12 months, starting at January, to December
//Simple calendar format, Sun Mon Tue Wed Thu Fri Sat or so
//Year will be chosen by the user, so it must make sense dynamically
//No idea how a calendar is calculated
//Either way we have to start somewhere, so let's start at 1800 and go to 2100 or so
//The first of January in the year 1800 was Wednesday
//The main issue is definitely February with it's extra day because of leap years
//How was that, you skip leap years each 100 years?
//Unless it's divisible by 400?

//Loop from first day to last day of month
//Each month is printed separate, so dislocate the logic accordingly
//We will just go ahead and try and see what works, since I don't really have a clue


//Using the calendar of 1800 as reference and starting point
void print_month(int month_current)
{
	int print_offset = 0;
	int days_to_print = 0;

	switch(month_current)
	{
	case 1:
		days_to_print = 31;
		print_offset = 3;
		break;
	case 2:
		days_to_print = 28;
		print_offset = 6;
		break;
	case 3:
		days_to_print = 31;
		print_offset = 6;
		break;
	case 4:
		days_to_print = 30;
		print_offset = 2;
		break;
	case 5:
		days_to_print = 31;
		print_offset = 4;
		break;
	case 6:
		days_to_print = 30;
		print_offset = 0;
		break;
	case 7:
		days_to_print = 31;
		print_offset = 2;
		break;
	case 8:
		days_to_print = 31;
		print_offset = 5;
		break;
	case 9:
		days_to_print = 30;
		print_offset = 1;
		break;
	case 10:
		days_to_print = 31;
		print_offset = 3;
		break;
	case 11:
		days_to_print = 30;
		print_offset = 6;
		break;
	case 12:
		days_to_print = 31;
		print_offset = 1;
		break;
	}
	
	for(int j = 0; j < print_offset; ++j)
	{
		printf("%s", "   ");
	}
	int print_position = 0;
	int skip_digit_zero = 1;
	for(int i = skip_digit_zero; i < days_to_print + skip_digit_zero; ++i)
	{
		++print_position;
		printf(" %d", i);
		int days_until_new_line = 0;
		const int days_per_week = 7;
		days_until_new_line = days_per_week - print_offset;
		const int single_digit_max = 9;
		if(i <= single_digit_max)
		{
			printf("%c", ' ');
		}
		if(i == days_until_new_line)
		{
			int reset_position = 0;
			print_position = reset_position;
		}
		if(print_position % 7 == 0)
		{
			printf("\n");
		}
		if(i == days_to_print)
		{
			printf("\n");
		}
	}
}

int check_year(int input_year)
{
	//Check if input year is valid
	//Check for leap years
	if(input_year < 1800 || input_year > 2100)
	{
		printf("%s\n", "Input year is not between 1800 and 2100, try again.");
		return;
	}
	int is_leap_year = 0;
	if(input_year % 4 == 0)
	{
		is_leap_year = 1;
	}
	if(input_year % 100 == 0)
	{
		is_leap_year = 0;
	}
	else if(input_year % 400 == 0)
	{
		is_leap_year = 1;
	}
	return is_leap_year;
}

void print_weekdays()
{
	printf("%s %s %s %s %s %s %s\n", "Su", "Mo", "Tu", "We", "Th", "Fr", "Sa");
}

void print_month_name(int month_current)
{
	//No idea how strings work in C
	//So I will just use numbers for now
	//printf("%d\n\n\n", month_current);
	printf("\n\n%s %d\n\n ", "Month name placeholder", month_current);
}