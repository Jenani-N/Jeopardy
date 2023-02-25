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
#include "questions.h"

// Initializes the array of questions for the game
void initialize_game(void)
{
question questions[NUM_QUESTIONS];
    // initialize each question struct and assign it to the questions array
    //Q1
    questions[0].category = "animals";
    questions[0].question = "What do you call a female deer?";
    questions[0].answer = "What is a doe?";
    questions[0].value = 100;
    questions[0].answered = false;
    
    //questions[0] = ["animals", "What do you call a female deer?", "What is a doe?", 100, false];
    
    //Q2
    questions[1].category = "animals";
    questions[1].question = "What do you call a group of giraffes?";
    questions[1].answer = "What is a tower?";
    questions[1].value = 200;
    questions[1].answered = false;
    
    //Q3
    questions[2].category = "animals";
    questions[2].question = "What is the largest type of frog?";
    questions[2].answer = "What is a Goliaath frog?";
    questions[2].value = 300;
    questions[2].answered = false;
    
    //Q4
    questions[3].category = "animals";
    questions[3].question = "What's the only insect that can turn its head?";
    questions[3].answer = "What is a Praying Mantis?";
    questions[3].value = 400;
    questions[3].answered = false;
    
    //Q5
    questions[4].category = "movies";
    questions[4].question = "Which disney movie has two sisters called Anna and Elsa?";
    questions[4].answer = "What is Frozen?";
    questions[4].value = 100;
    questions[4].answered = false;
    
    //Q6
    questions[5].category = "movies";
    questions[5].question = "What kind of fish are Nemo and his dad?";
    questions[5].answer = "What is a clownfish?";
    questions[5].value = 200;
    questions[5].answered = false;
    
    //Q7
    questions[6].category = "movies";
    questions[6].question = "What is the name of the dragon who helps Mulan?";
    questions[6].answer = "Who is Mushu?";
    questions[6].value = 300;
    questions[6].answered = false;

    //Q8
    questions[7].category = "movies";
    questions[7].question = "What is the name of Rapunzel's pet chameleon in Tangled?";
    questions[7].answer = "Who is Pascal?";
    questions[7].value = 400;
    questions[7].answered = false;
    
    //Q9
    questions[8].category = "geography";
    questions[8].question = "What are the colors on the Canadian flag?";
    questions[8].answer = "What is red and white?";
    questions[8].value = 100;
    questions[8].answered = false;
    
    //Q10
    questions[9].category = "geography";
    questions[9].question = "Which two countries share the longest border?";
    questions[9].answer = "What is Canada and the US?";
    questions[9].value = 200;
    questions[9].answered = false;
    
    //Q11
    questions[10].category = "geography";
    questions[10].question = "Which planet is nearest to the Earth?";
    questions[10].answer = "What is Venus?";
    questions[10].value = 300;
    questions[10].answered = false;
    
    //Q12
    questions[11].category = "geography";
    questions[11].question = "Which ocean is off the coast of California?";
    questions[11].answer = "What is the Pacific Ocean?";
    questions[11].value = 400;
    questions[11].answered = false;
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    for (int a = 0; a < NUM_QUESTIONS; a++){
    	if (questions[a].answered == false){
    		printf("Category: %s\n ", questions[a].category);
    		printf("Value: %d\n\n", questions[a].value);
    	}
    }
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
	for (int b = 0; b < NUM_QUESTIONS; b++){
		if (strcmp(questions[b].category, category) == 1 && questions[b].value == value && questions[b].answered == false){
			printf("Question: %s\n", questions[b].question);
		}
	}
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    for (int b = 0; b < NUM_QUESTIONS; b++){
    	if (strcmp(questions[b].category, category) == 1 && questions[b].value == value){
		if (strcmp(questions[b].answer, answer) == 1){
			return true;
		}
		else{
			return false;
		}
	}
    }
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    for (int b = 0; b < NUM_QUESTIONS; b++){
    	if (strcmp(questions[b].category, category) == 1 && questions[b].value == value && questions[b].answered == true){
		return true;
	}
	else{
		return false;
    	}
    }
}

//Returns true if the question has been marked as answered
bool mark_answered (char *category, int value){
    
    for(int b = 0; b < NUM_QUESTIONS; b++){
    
    	if(strcmp(questions[b].category,category)==0 && questions[b].value==value){
    		
		questions[b].answered=true;
    	}
    		  
    }
    }
