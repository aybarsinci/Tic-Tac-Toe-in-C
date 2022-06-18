

#include <stdio.h>
#include <stdlib.h>
 //termios, TCSANOW, ECHO, ICANON
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <limits.h>

void vis_table(char arr[3][3]);
void user_move(int input, char arr[3][3]);
bool valid_input(int input, char arr[3][3]);
bool ai_move(char arr[3][3]);
bool win_condition(char arr[3][3]);
bool check_draw(char arr[3][3]);
void path_finder(const char[], char *, size_t);

int main() {
                char buffer[100];
		
                char b = ' ';
				char x = 'X';
				char o = 'O';
				bool game_state = true;
				char table[3][3] = {
					{b, b, b},
					{b, b, b},
					{b, b, b}};
				printf("You will be playing against Tic Tac Toe bot.\n");
				printf("Your symbol is X and Tic Tac Toe bot's symbol is O.\n");
				printf("You can play your turns by entering cordination of the Tic Tac Toe table.\n");
				printf("THe first move is yours.\n");

				while (game_state)
				{
					bool valid = true;
					int user_turn;
					while (valid)
					{
						vis_table(table);
						printf("\nYour turn:");

						fgets(buffer, 99, stdin);
						sscanf(buffer, "%d", &user_turn);

						valid = valid_input(user_turn, table);
					}
					user_move(user_turn, table);

					if (win_condition(table) || check_draw(table))
					{
						sleep(2);
						break;
					}

					vis_table(table);

					printf("\n");
					printf("Tic Tao Toe bot's turn:\n");
					bool ai_ct = ai_move(table);
					if (ai_ct)
					{
						bool z = true;
						while (z)
						{
							srand(time(NULL));
							int n1 = (rand() % 3);
							srand(time(NULL));
							int n2 = (rand() % 3);
							if (table[n1][n2] == b)
							{
								table[n1][n2] = o;
								z = false;
							}
						}
					}

					if (win_condition(table) || check_draw(table))
					{
						sleep(2);
						break;
					}
				}
				vis_table(table);
}

void vis_table(char arr[3][3])
{
	int a = 254;
	char c = a;

	printf("-------\n");
	printf("|%c|%c|%c|\n", arr[0][0], arr[0][1], arr[0][2]);
	printf("-------\n");
	printf("|%c|%c|%c|\n", arr[1][0], arr[1][1], arr[1][2]);
	printf("-------\n");
	printf("|%c|%c|%c|\n", arr[2][0], arr[2][1], arr[2][2]);
	printf("-------\n");
}
void user_move(int input, char arr[3][3])
{

	if (input == 11)
	{
		arr[0][0] = 'X';
	}
	else if (input == 12)
	{
		arr[0][1] = 'X';
	}
	else if (input == 13)
	{
		arr[0][2] = 'X';
	}
	else if (input == 21)
	{
		arr[1][0] = 'X';
	}
	else if (input == 22)
	{
		arr[1][1] = 'X';
	}
	else if (input == 23)
	{
		arr[1][2] = 'X';
	}
	else if (input == 31)
	{
		arr[2][0] = 'X';
	}
	else if (input == 32)
	{
		arr[2][1] = 'X';
	}
	else if (input == 33)
	{
		arr[2][2] = 'X';
	}
}
bool valid_input(int input, char arr[3][3])
{
	bool valid;

	if (input == 11)
	{
		if (arr[0][0] == ' ')
		{
			valid = false;
		}
		else
		{
			printf("You have entered invalid cordinates\n");
			valid = true;
		}
	}
	else if (input == 12)
	{
		if (arr[0][1] == ' ')
		{
			valid = false;
		}
		else
		{
			printf("You have entered invalid cordinates\n");
			valid = true;
		}
	}
	else if (input == 13)
	{
		if (arr[0][2] == ' ')
		{
			valid = false;
		}
		else
		{
			printf("You have entered invalid cordinates\n");
			valid = true;
		}
	}
	else if (input == 21)
	{
		if (arr[1][0] == ' ')
		{
			valid = false;
		}
		else
		{
			printf("You have entered invalid cordinates\n");
			valid = true;
		}
	}
	else if (input == 22)
	{
		if (arr[1][1] == ' ')
		{
			valid = false;
		}
		else
		{
			printf("You have entered invalid cordinates\n");
			valid = true;
		}
	}
	else if (input == 23)
	{
		if (arr[1][2] == ' ')
		{
			valid = false;
		}
		else
		{
			printf("You have entered invalid cordinates\n");
			valid = true;
		}
	}
	else if (input == 31)
	{
		if (arr[2][0] == ' ')
		{
			valid = false;
		}
		else
		{
			printf("You have entered invalid cordinates\n");
			valid = true;
		}
	}
	else if (input == 32)
	{
		if (arr[2][1] == ' ')
		{
			valid = false;
		}
		else
		{
			printf("You have entered invalid cordinates\n");
			valid = true;
		}
	}
	else if (input == 33)
	{
		if (arr[2][2] == ' ')
		{
			valid = false;
		}
		else
		{
			printf("You have entered invalid cordinates\n");
			valid = true;
		}
	}
	return valid;
}
bool ai_move(char arr[3][3])
{
	char c = 'X';
	char b = ' ';
	char o = 'O';
	bool f = false;
	if (arr[0][0] == c && arr[0][1] == c && arr[0][2] == b)
	{ //ok
		arr[0][2] = o;
	}
	else if (arr[0][1] == c && arr[0][2] == c && arr[0][0] == b)
	{ //ok
		arr[0][0] = o;
	}
	else if (arr[1][0] == c && arr[1][1] == c && arr[1][2] == b)
	{ //ok
		arr[1][2] = o;
	}
	else if (arr[1][1] == c && arr[1][2] == c && arr[1][0] == b)
	{ //ok
		arr[1][0] = o;
	}
	else if (arr[2][0] == c && arr[2][1] == c && arr[2][2] == b)
	{ //ok
		arr[2][2] = o;
	}
	else if (arr[2][1] == c && arr[2][2] == c && arr[2][0] == b)
	{ // ok
		arr[2][0] = o;
	}
	else if (arr[0][0] == c && arr[1][0] == c && arr[2][0] == b)
	{ //ok
		arr[2][0] = o;
	}
	else if (arr[1][0] == c && arr[2][0] == c && arr[0][0] == b)
	{ // ok
		arr[0][0] = o;
	}
	else if (arr[0][1] == c && arr[1][1] == c && arr[2][1] == b)
	{ //ok
		arr[2][1] = o;
	}
	else if (arr[1][1] == c && arr[2][1] == c && arr[0][1] == b)
	{ //ok
		arr[0][1] = o;
	}
	else if (arr[0][2] == c && arr[1][2] == c && arr[2][2] == b)
	{ //ok
		arr[2][2] = o;
	}
	else if (arr[1][2] == c && arr[2][2] == c && arr[0][2] == b)
	{ //ok
		arr[0][2] = o;
	}
	else if (arr[0][0] == c && arr[0][2] == c && arr[0][1] == b)
	{ //ok
		arr[0][1] = o;
	}
	else if (arr[1][0] == c && arr[1][2] == c && arr[1][1] == b)
	{ //ok
		arr[1][1] = o;
	}
	else if (arr[2][0] == c && arr[2][2] == c && arr[2][1] == b)
	{ //ok
		arr[2][1] = o;
	}
	else if (arr[0][0] == c && arr[2][0] == c && arr[1][0] == b)
	{ //ok
		arr[1][0] = o;
	}
	else if (arr[0][1] == c && arr[2][1] == c && arr[1][1] == b)
	{ //ok
		arr[1][1] = o;
	}
	else if (arr[0][2] == c && arr[2][2] == c && arr[1][2] == b)
	{ //ok
		arr[1][2] = o;
	}
	else if (arr[0][0] == c && arr[1][1] == c && arr[2][2] == b)
	{ //ok
		arr[2][2] = o;
	}
	else if (arr[1][1] == c && arr[2][2] == c && arr[0][0] == b)
	{ //ok
		arr[0][0] = o;
	}
	else if (arr[0][0] == c && arr[2][2] == c && arr[1][1] == b)
	{ //ok
		arr[1][1] = o;
	}
	else if (arr[2][0] == c && arr[1][1] == c && arr[0][2] == b)
	{ //ok
		arr[0][2] = o;
	}
	else if (arr[1][1] == c && arr[0][2] == c && arr[2][0] == b)
	{ //ok
		arr[2][0] = o;
	}
	else if (arr[2][0] == c && arr[0][2] == c && arr[1][1] == b)
	{ //ok
		arr[1][1] = o;
	}
	else
	{
		f = true;
	}
	return f;
}
bool win_condition(char arr[3][3])
{
	bool f = false;
	char c = 'X';
	char b = ' ';
	char o = 'O';
	if (arr[0][1] == c && arr[0][2] == c && arr[0][0] == c)
	{
		f = true;
		printf("Congratulaitons you have won.\n");
	}
	else if (arr[1][1] == c && arr[1][2] == c && arr[1][0] == c)
	{
		f = true;
		printf("Congratulaitons you have won.\n");
	}
	else if (arr[2][1] == c && arr[2][2] == c && arr[2][0] == c)
	{
		f = true;
		printf("Congratulaitons you have won.\n");
	}
	else if (arr[0][0] == c && arr[1][0] == c && arr[2][0] == c)
	{
		f = true;
		printf("Congratulaitons you have won.\n");
	}
	else if (arr[0][1] == c && arr[1][1] == c && arr[2][1] == c)
	{
		f = true;
		printf("Congratulaitons you have won.\n");
	}
	else if (arr[0][2] == c && arr[1][2] == c && arr[2][2] == c)
	{
		f = true;
		printf("Congratulaitons you have won.\n");
	}
	else if (arr[0][0] == c && arr[1][1] == c && arr[2][2] == c)
	{
		f = true;
		printf("Congratulaitons you have won.\n");
	}
	else if (arr[2][0] == c && arr[1][1] == c && arr[0][2] == c)
	{ //ok
		f = true;
		printf("Congratulaitons you have won.\n");
	}
	else if (arr[0][1] == o && arr[0][2] == o && arr[0][0] == o)
	{
		f = true;
		printf("You have lost. Try again.\n");
	}
	else if (arr[1][1] == o && arr[1][2] == o && arr[1][0] == o)
	{
		f = true;
		printf("You have lost. Try again.\n");
	}
	else if (arr[2][1] == o && arr[2][2] == o && arr[2][0] == o)
	{
		f = true;
		printf("You have lost. Try again.\n");
	}
	else if (arr[0][0] == o && arr[1][0] == o && arr[2][0] == o)
	{
		f = true;
		printf("You have lost. Try again.\n");
	}
	else if (arr[0][1] == o && arr[1][1] == o && arr[2][1] == o)
	{
		f = true;
		printf("You have lost. Try again.\n");
	}
	else if (arr[0][2] == o && arr[1][2] == o && arr[2][2] == o)
	{
		f = true;
		printf("You have lost. Try again.\n");
	}
	else if (arr[0][0] == o && arr[1][1] == o && arr[2][2] == o)
	{
		f = true;
		printf("You have lost. Try again.\n");
	}
	else if (arr[2][0] == o && arr[1][1] == o && arr[0][2] == o)
	{
		f = true;
		printf("You have lost. Try again.\n");
	}
	return f;
}
bool check_draw(char arr[3][3])
{
	bool f = false;
	char b = ' ';
	if ((arr[0][0] != b) && (arr[0][1] != b) && (arr[0][2] != b) &&
		(arr[1][0] != b) && (arr[1][1] != b) && (arr[1][2] != b) &&
		(arr[2][0] != b) && (arr[2][1] != b) && (arr[2][2] != b))
	{
		printf("STALEMATE\n");
		f = true;
	}
	return f;
}


