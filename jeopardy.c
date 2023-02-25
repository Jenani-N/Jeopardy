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
#include "rrquestions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here
extern question questions[NUM_QUESTIONS];

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens){

char* token;
int i = 0;

token = strtok(input, " ");

while (token) {
    
    strcpy(tokens[i++], token);
   
    token = strtok(NULL, " ");
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
	int j = 0;
	
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();
    
    printf("Welcome to Jeopardy. \n");
    printf("Answers will be first shown; please input the corresponding question. Input should start with 'who' or 'what'.");
    
    // Prompt for players names
    
    printf("Please enter the players' names. ");
    
    char category[300];
    char name[300];
    
    // initialize each of the players in the array
    
    for(int i = 0; i < NUM_PLAYERS; i++){
    	
    	printf("Player number %d",j+1);
    	fgets(buffer, BUFFER_LEN, stdin);
    	
    	buffer[(strlen(buffer)-1)]='\0';
    	strcpy(players[j].name,buffer);
    	
    	players[j].score=0;
    	j++;

    }
	display_categories();
	char arr[300];			
	int ans;
    
    printf("To select a category, please enter your name");
    
   // Perform an infinite loop getting command input from users until game ends
   
    while (fgets(name, BUFFER_LEN, stdin) != NULL)
    {
	name[(strlen(name)-1)]='\0';						//Removes the newline from the user input
    	
    	if(player_exists(players, NUM_PLAYERS, name) == true ){
    	
    			while(1){
    				printf("Please select a category: ");
    				
				fgets(category, BUFFER_LEN, stdin);		//Gets user input for category with fgets
				
				category[(strlen(category)-1)]='\0';	
				
				printf("Please select the value of the category: ");
				
				fgets(arr, BUFFER_LEN, stdin);			//Gets user input for value 
				
				arr[(strlen(arr)-1)]='\0';
			
				ans=atoi(arr);					//Uses atoi to make it into an integer
				
				if(!already_answered(category, ans)){	//Uses function from questions.c to check if it has been answered already
					
					display_question(category, ans);	//If haven't been answered already, questions are displayed
					
					break;			
				}
				
				else {						//If answered already, a statement is printed out to notify user
	    				
	    				printf("This has already been answered. Please select another category/value. ");
				}
    			}
    		
    			printf("Please enter your answer: ");	//Asks user to enter their answer and gets the input using fgets
    			
    			fgets(buffer, BUFFER_LEN, stdin);
    			
			buffer[(strlen(buffer)-1)]='\0';
			
			bool ans = valid_answer(category, ans, buffer);
			
			if(ans){
				printf("User input: %s \n This is the correct answer.");	//Checks for correct answer and updates score
												
				update_score(players, NUM_PLAYERS, name, ans);
				
				mark_answered(category, ans);
				
				numofQ = numofQ - 1;			//Decrements number of questions
			}else{
				
				printf("User input: %s \n This is the wrong answer.");	//User has selected a wrong answer and score is not updated but answer is displayed
	    			
	    			display_answer(category, ans);
				
				mark_answered(category, ans);
	    			
	    			numofQ = numofQ - 1;			//Decrements number of questions
			}

			if(numofQ == 0){
				
				break;
			}   	    	
    	}
       
	printf("Please enter the name of the next player: "); 	//Asks user for the name of the next player
       
    }
      // Display the final results and exit
     
     show_results(players, NUM_PLAYERS);
   
    return EXIT_SUCCESS;
}
