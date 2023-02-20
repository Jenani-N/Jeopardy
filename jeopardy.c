/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens){	

char *token;
int i = 0;

token = strtok(input, ' ');

while (token){

strcpy(tokens[i++], token);
token = strtok(NULL, ' ');
}

}


// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players){	
for (int i = 0; i < num_players; i++){

printf("Name: %s", players[i].name);
printf("Final score: %d", players[i].score);

}

int highest_score;
int curr;

for(int i = 0; i < num_players; i++){

if(players[i].score > highest_score){

highest_score = players[i].score;
curr = i;
}

}

}

int main(int argc, char *argv[])
{
	int numofQ = NUM_QUESTIONS;

    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();
    
    
    printf("Welcome to Jeopardy. \n");
    printf("Answers will be first shown; please input the corresponding question. Input should start with 'who' or 'what'.");
    

    // Prompt for players names
  
   printf("Please enter the players' names: \n");
    
    
    // initialize each of the players in the array
    
    for(int i = 0; i < NUM_PLAYERS; i++){
    
    printf("Player number %d", i++);
    scanf("%[^\n]%*c", players[i].name);	
    players[i].score = 0;
    printf("The player has been entered. \n");
    
    }
    
    display_categories();
     

    // Perform an infinite loop getting command input from users until game ends
   
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
    	char *name;
    	char *token;
    	char *instr;
    	char category[100]; 
    	int ans;
    	char arr[100];
    	
    	printf("To select a category, please enter your name.");
    	fgets(buffer, BUFFER_LEN, stdin);
    	name = strtok(buffer, "\n");
    	
    	
    	// Call functions from the questions and players source files
    	
    	if (player_exists (players, NUM_PLAYERS, name) == true){	//If condition for whether the player exists, function is from player.c
    	
    	printf("Please select a category.");				//Asks user to select a category
    	fgets(buffer, BUFFER_LEN, stdin);
    	
    	token = strtok(buffer, "\n");					//Uses strtok to remove any newlines from the buffer and gets the value
    	instr = strtok(token, " ");
    	strcpy(arr[0], instr);
    	instr = strtok(NULL, " ");
    	strcpy(arr[1], instr);
    	token = NULL;
    						
    	
    	category[(strlen(category)-1)] = '\0';				
    	
    	if(!verify_category(category)){					//If condition for when the wrong category has been chosen
    	
    	printf("The wrong category has been entered.");
    	
    	continue;
    	
    	}
    	
    	printf("Please select the value of the category. ");		//Asks user for the value of the category
    	
    	fgets(category, BUFFER_LEN, stdin);				//Gets the input regarding the category from the user
    	category[(strlen(category)-1)] = '\0';
    	
    	fgets(arr, BUFFER_LEN, stdin);					//Uses fgets to get input from user; 
    	arr[strlen(arr)-1] = '\0';
    	
    	ans = atoi(arr);
    	
    	if(already_answered(category, ans)){			//Uses function from questions.c to check if it has been answered already; displays questions
    	
    	printf("This has already been answered. Please select another category/value.");
    	
    	display_question(category, ans);
    	
    	} else {						//If haven't been answered already, questions are displayed
    	
    	display_question(category, ans);
    	
    	break;
    	
    	}
    	
    	printf("Please enter your answer: ");		//Asks user to enter their answer and gets the input using fgets
    	
    	fgets(buffer, BUFFER_LEN, stdin);
    	
    	token = strtok(buffer, "\n");
    	buffer[(strlen(buffer)-1)] = '\0';
    	
    	
    	bool answer = valid_answer(category, ans, buffer);
    	
    	
    	if(answer){				//Checks for correct answer and updates score
    	
    	printf("This is the correct answer.");
    	
    	update_score(players, NUM_PLAYERS, name, ans);
    	
    	mark_answered(category, ans);
    	
    	numofQ = numofQ - 1;		//Decrements number of questions
    	
    	} else {			//User has selected a wrong answer and score is not updated but answer is displayed
    	
    	printf("This is the wrong answer.");
    	
    	display_answer(category, ans);
    	
    	mark_answered(category, ans);
    	
    	numofQ = numofQ - 1;		//Decrements number of questions
    	
    	}
    	
    	// Execute the game until all questions are answered
    	
    	if(numofQ == 0){
    	
    	break;
    	
    	}
    	    
        
    } else {
    
    printf("Please enter the name of the next player: ");	//Asks user for the name of the next player
    
    }
    
    }
    // Display the final results and exit
    
    show_results(players, NUM_PLAYERS);
    
    return EXIT_SUCCESS;
}
