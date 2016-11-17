/*Name: Ash Mahein
* Date: 02/25/16
* Class: CptS 121, Spring 2016; Lab Section 4
* Programming Assignment: Craps.
* Collobaration: Connor Wytko, Fung.
* Description: This program plays the game of craps by first prompting the user for their bank balance and then asking for their wager.  It rolls the dice and check to see
* if the player has either won, lost, made their point. The player rerolls until he has matched the point. If he loses or wins the bank balance is adjusted accordingly.
*
*Constants: None.
*
*Outputs: Number of rolls, number of wins/losses, initial bank balance, current bank balance, and adjusted bank balance.
*
*/
#include "Craps_header.h"
//Code in last function.
int main(void)
{
	//Defined variables.
	double start_bank_balance = 0.0;
	int player_choice = 0;
	char player_input = '\0';
	double bank_balance = 0.0;
	double wager_amount = 0.0;
	double wager = 0.0;
	double balance = 0.0;
	double value = 0.0;
	int die1_value = 0;
	int die2_value = 0;
	int win_or_loss = 0;
	int sum_dice = 0;
	int point_value = 0;
	int add_or_subtract = 0;
	int i = 0;
	double new_bank_balance = 0.0;
	int number_rolls = 0;
	int roll = 0;
	int win_loss_neither = 0;
	double initial_bank_balance = 0.0;
	double current_bank_balance = 0.0;

	srand((int)time(NULL));

	//Asks if player wants to play.
	printf("Would you like to play Craps <Y/N>?\n");

	scanf(" %c", &player_input);

	//If no then exits game.
	if (player_input == 'n')
	{
		printf("Hope you play next time!\n");
	}

	//If yes then the player is asked if they would like to play the game, see game rules, or exit game.
	else if (player_input = 'y')
	{
		while (player_input = 'y')
		{
			do
			{
				printf("Welcome to Craps!\n\n");

				printf("1. Game rules.\n");

				printf("2. Play Game.\n");

				printf("3. Exit.\n");

				scanf("%d", &player_choice);

			} while ((player_choice < 1) || (player_choice > 3));

			//Prints game rules if player chooses to see them.
			if (player_choice == 1)
			{
				print_game_rules();
			}
			//Plays the game if player chooses to play.
			else if (player_choice == 2)
			{
				//Get bank balance.
				balance = get_bank_balance();

				//Gets the wager amount
				wager = get_wager_amount();

				//Check to see if wager amount if less than or equal to bank balance.
				wager = check_wager_amount(wager, balance);

				//Rolls dice.
				die1_value = roll_die();

				//Rolls dice.
				die2_value = roll_die();

				//Calulates sum of dice.
				sum_dice = calculate_sum_dice(die1_value, die2_value);

				//See if you win, lose, or make a point.
				win_or_loss = is_win_loss_or_point(sum_dice);

				//if you make a point you will keep playing.
				if (win_or_loss == -1)
				{
					point_value = sum_dice;
				}

				//Will keep rolling until you win or lose.
				if ((sum_dice == 4) || (sum_dice == 5) || (sum_dice == 6) || (sum_dice == 8) || (sum_dice == 10))
				{
					do
					{
						sum_dice = 0;

						die1_value = 0;

						die1_value = roll_die();

						die2_value = roll_die();

						sum_dice = calculate_sum_dice(die1_value, die2_value);

						win_or_loss = is_point_loss_or_neither(sum_dice, point_value);

						number_rolls = number_rolls + 1;

					} while (sum_dice != 7 && sum_dice != point_value);
				}

				//Checks to see if your successive rolls are wins or losses.
				sum_dice = is_point_loss_or_neither(sum_dice, point_value);

				//Assigns bank balance adjustment to your rolls.
				add_or_subtract = is_point_loss_or_neither(sum_dice, point_value);

				new_bank_balance = adjust_bank_balance(balance, wager, add_or_subtract, sum_dice);

				if (new_bank_balance > 0)
				{
					//Adjusts the player bank balance each time they choose to play.
					new_bank_balance = adjust_bank_balance(balance, wager, add_or_subtract, sum_dice);
				}
				else
				{
					printf("Sorry, but you're out of money.\n");
					break;
				}

				printf("Play again? Press 2.\n\n");

			}
			//If player chooses 3 then they exit the game.
			if (player_choice == 3)
			{
				printf("Thanks for playing!\n");

				//Prints out the wins, losses, current and initial bank balances.
				chatter_messages(number_rolls, add_or_subtract, balance, new_bank_balance);

				break;
			}
		}
	}

	system("pause");

	return 0;
}