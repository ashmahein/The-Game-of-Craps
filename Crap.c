/*Name: Ash Mahein
* Date: 02/25/16
* Class: CptS 121, Spring 2016; Lab Section 4
* Programming Assignment: Craps.
* Collobaration: Connor Wytko, Fung, Eric Chen.
* Description: This program plays the game of craps by first prompting the user for their bank balance and then asking for their wager.  It rolls the dice and check to see
* if the player has either won, lost, made their point. The player rerolls until he has matched the point. If he loses or wins the bank balance is adjusted accordingly.
*
*
*
*Constants: None.
*
*Outputs: Number of rolls, number of wins/losses, initial bank balance, current bank balance, and adjusted bank balance.
*
*
*/
#include "Craps_header.h"

/*********************************************************************************************
* Programmer: Ash Mahein                                                                     *
* Class: CptS 121; Lab Section 4                                                             *
* Programming Assignment: Craps                                                              *
*                                                                                            *
* Date: 02/25/16                                                                             *
*                                                                                            *
* Description://Function for reading the rules to the player                                 *
*                                                                                            *
*                                                                                            *
*                                                                                            *
*                                                                                            *
*********************************************************************************************/
void print_game_rules(void)
{
	printf("Rules of Craps: A player rolls two dice. Each die has six faces.\n");
	printf("These faces contain 1, 2, 3, 4, 5, and 6 spots.\n");
	printf("After the dice have come to rest,\n");
	printf("the sum of the spots on the two upward faces is calculated.\n");
	printf("If the sum is 7 or 11 on the first throw, the player wins.\n");
	printf("If the sum is 2, 3, or 12 on the first throw (called craps),\n");
	printf("the player loses(i.e.the house wins).\n");
	printf("If the sum is 4, 5, 6, 8, 9, or 10 on the first throw,\n");
	printf("then the sum becomes the player's point.\n");
	printf("To win, you must kep rolling the dice until you make your point.\n");
	printf("The player loses by rolling a 7 before making the point.\n");
}
/*********************************************************************************************
* Programmer: Ash Mahein                                                                     *
* Class: CptS 121; Lab Section 4                                                             *
* Programming Assignment: Craps                                                              *
*                                                                                            *
* Date: 02/25/16                                                                             *
*                                                                                            *
* Description://Function for getting the players bank balance.                               *
*                                                                                            *
*                                                                                            *
*                                                                                            *
*                                                                                            *
*********************************************************************************************/
double get_bank_balance(void)
{
	double balance = 0.0;

	printf("Please enter your bank balance: ");

	scanf("%lf", &balance);

	printf("Bank Balance: $%.2lf\n", balance);

	return balance;
}
double intital_bank_balace(double balance)
{
	printf("Your initial bank balance is %.2lf\n currently.\n", balance);

	return balance;
}
/*********************************************************************************************
* Programmer: Ash Mahein                                                                     *
* Class: CptS 121; Lab Section 4                                                             *
* Programming Assignment: Craps                                                              *
*                                                                                            *
* Date: 02/25/16                                                                             *
*                                                                                            *
* Description://Function for getting the player wager amount.                                *
*                                                                                            *
*                                                                                            *
*                                                                                            *
*                                                                                            *
*********************************************************************************************/
double get_wager_amount(void)
{
	double wager = 0.0;

	printf("What is your wager for this roll: ");

	scanf("%lf", &wager);

	printf("Your wager is: %.2lf\n", wager);

	return wager;
}
/*********************************************************************************************
* Programmer: Ash Mahein                                                                     *
* Class: CptS 121; Lab Section 4                                                             *
* Programming Assignment: Craps                                                              *
*                                                                                            *
* Date: 02/25/16                                                                             *
*                                                                                            *
* Description://Function for checking the players wager amount against their bank            *
*               balance.                                                                     *
*                                                                                            *
*                                                                                            *
*                                                                                            *
*********************************************************************************************/
double check_wager_amount(double wager, double balance)
{
	double value = 0;

	value = wager;

	while (value > balance)
	{
		value = 0;

		printf("Your wager is too high. Please enter a lower wager.\n");

		printf("Enter a new wager:");

		scanf("%lf", &value);

		wager = value;
	}
	return wager;
}
/*********************************************************************************************
* Programmer: Ash Mahein                                                                     *
* Class: CptS 121; Lab Section 4                                                             *
* Programming Assignment: Craps                                                              *
*                                                                                            *
* Date: 02/25/16                                                                             *
*                                                                                            *
* Description://Function for rolling the dice                                                *
*                                                                                            *
*                                                                                            *
*                                                                                            *
*                                                                                            *
*********************************************************************************************/
int roll_die(void)
 {
	int die1 = 0;

	die1 = (rand() % 6 + 1);

	printf("Dice roll %d\n", die1);

	return die1;
}
/*********************************************************************************************
* Programmer: Ash Mahein                                                                     *
* Class: CptS 121; Lab Section 4                                                             *
* Programming Assignment: Craps                                                              *
*                                                                                            *
* Date: 02/25/16                                                                             *
*                                                                                            *
* Description://Function for calculating the sum of the dice roll                            *
*                                                                                            *
*                                                                                            *
*                                                                                            *
*                                                                                            *
*********************************************************************************************/
int calculate_sum_dice(int die1_value, int die2_value)
{
	int total_dice_value = 0; 

	total_dice_value = die1_value + die2_value;

	printf("Total: %d\n", total_dice_value);

	return total_dice_value;
}
/*********************************************************************************************
* Programmer: Ash Mahein                                                                     *
* Class: CptS 121; Lab Section 4                                                             *
* Programming Assignment: Craps                                                              *
*                                                                                            *
* Date: 02/25/16                                                                             *
*                                                                                            *
* Description://Function for checking if player wins, loses, or makes their point.           *
*                                                                                            *
*                                                                                            *
*                                                                                            *
*                                                                                            *
*********************************************************************************************/
int is_win_loss_or_point(int sum_dice)
{	 
	int total = 0;

	if ((sum_dice == 7) || (sum_dice == 11))
	{
		printf("Player wins.\n");

		total = 1;
	}

	else if ((sum_dice == 2) || (sum_dice == 3) || (sum_dice == 12))
	{
		printf("Player loses.\n");

		total = 0;
	}

	else
	{
		total = -1;
	}
	return total;
}
/*********************************************************************************************
* Programmer: Ash Mahein                                                                     *
* Class: CptS 121; Lab Section 4                                                             *
* Programming Assignment: Craps                                                              *
*                                                                                            *
* Date: 02/25/16                                                                             *
*                                                                                            *
* Description://Function for checking the successive rolls to see if the player wins, or     *
*               loses.                                                                       *
*                                                                                            *
*                                                                                            *
*                                                                                            *
*********************************************************************************************/
int is_point_loss_or_neither(int sum_dice, int point_value)
{
	int add_or_subtract = 0;

	if (sum_dice == point_value)
	{
		add_or_subtract = 1;
	}
	else if (sum_dice == 7)
	{
		add_or_subtract = 0;
	}
	else
	{
		add_or_subtract = -1;
	}
	return add_or_subtract;
}
/*********************************************************************************************
* Programmer: Ash Mahein                                                                     *
* Class: CptS 121; Lab Section 4                                                             *
* Programming Assignment: Craps                                                              *
*                                                                                            *
* Date: 02/25/16                                                                             *
*                                                                                            *
* Description://Function for adjusting the player bank balance after he wins or loses.       *
*                                                                                            *
*                                                                                            *
*                                                                                            *
*                                                                                            *
*********************************************************************************************/
double adjust_bank_balance(double balance, double wager, int add_or_subtract, int sum_dice)
{
	if ((sum_dice == 0) || (sum_dice == 1))
	{
		add_or_subtract = 1;

		balance += wager;

		printf("You won, Bank balance is %.2lf:\n", balance);
	}

	else if (sum_dice == -1)
	{
		add_or_subtract = 0;

		balance -= wager;

		printf("You lost, Bank balance is %.2lf :\n", balance);
	}
	return balance;
}
/*********************************************************************************************
* Programmer: Ash Mahein                                                                     *
* Class: CptS 121; Lab Section 4                                                             *
* Programming Assignment: Craps                                                              *
*                                                                                            *
* Date: 02/25/16                                                                             *
*                                                                                            *
* Description://Function for showing the player how many times they won, lost, the number of *
*               rolls, and also the initial bank balance and the current bank balance .      *
*                                                                                            *
*                                                                                            *
*                                                                                            *
*********************************************************************************************/
void chatter_messages(int number_rolls, int add_or_subtract, double balance, double new_bank_balance)
{
	printf("Number of rolls is %d\n", number_rolls);

	if (add_or_subtract == 1)
	{
		printf("You win!\n");
	}

	else
	{
		printf("You lose...\n");
	}
	printf("Your initial bank balance was %.2lf\n", balance);

	printf("Your ending bank balance is %.2lf\n", new_bank_balance);
}