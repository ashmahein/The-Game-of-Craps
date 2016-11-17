/*Name: Ash Mahein
* Date: 02/25/16
* Class: CptS 121, Spring 2016; Lab Section 4
* Programming Assignment: Craps.
* Collobaration: Connor Wytko, Fung, Eric Chen.
* Description: This program plays the game of craps by first prompting the user for their bank balance and then asking for their wager.  It rolls the dice and check to see
* if the player has either won, lost, made their point. The player rerolls until he has matched the point. If he loses or wins the bank balance is adjusted accordingly.
* 
*Constants: None.
*           
*Outputs: Number of rolls, number of wins/losses, initial bank balance, current bank balance, and adjusted bank balance.
* 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Fucntion defintions.
void print_game_rules(void);
double get_bank_balance(void);
double get_wager_amount(void);
double check_wager_amount(double wager, double balance);
int roll_die(void);
int calculate_sum_dice(int die1_value, int die2_value);
int is_win_loss_or_point(int sum_dice);
int is_point_loss_or_neither(int sum_dice, int point_value);
double adjust_bank_balance(double balance, double wager, int add_or_subtract, int sum_dice);
void chatter_messages(int number_rolls, int add_or_subtract, double balance, double new_bank_balance);