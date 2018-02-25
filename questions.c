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
    // initialize each question struct and assign it to the questions array

    //programming
    strcpy(questions[0].category, "programming");
    strcpy(questions[0].question, "Who invented FORTRAN?");
    strcpy(questions[0].answer, "IBM.");
    questions[0].value = 100;
    questions[0].answered = false;

    strcpy(questions[1].category, "programming");
    strcpy(questions[1].question, "Who invented the Turing machine?");
    strcpy(questions[1].answer, "Alan Turing.");
    questions[1].value = 200;
    questions[1].answered = false;

    strcpy(questions[2].category, "programming");
    strcpy(questions[2].question, "What is a pointer?");
    strcpy(questions[2].answer, "A pointer is a programming object, whose value points to another value.");
    questions[2].value = 300;
    questions[2].answered = false;

    strcpy(questions[3].category, "programming");
    strcpy(questions[3].question, "What is the difference between an Array and an ArrayList?");
    strcpy(questions[3].answer, "An array is a fixed length and arraylist is a variable length.");
    questions[3].value = 400;
    questions[3].answered = false;

    //algorithm
    strcpy(questions[4].category, "algorithms");
    strcpy(questions[4].question, "What is the simplest algorithm?");
    strcpy(questions[4].answer, "Bubble sort");
    questions[4].value = 100;
    questions[4].answered = false;

    strcpy(questions[5].category, "algorithms");
    strcpy(questions[5].question, "What is the wost time complexity for Quick Sort?");
    strcpy(questions[5].answer, "O(n^2)");
    questions[5].value = 200;
    questions[5].answered = false;

    strcpy(questions[6].category, "algorithms");
    strcpy(questions[6].question, "This sort divides and conqure algorithms and is like Merge sort?");
    strcpy(questions[6].answer, "Quick sort");
    questions[6].value = 300;
    questions[6].answered = false;

    strcpy(questions[7].category, "algorithms");
    strcpy(questions[7].question, "Name two sorts which use O(nlogn)?");
    strcpy(questions[7].answer, "Quick sort and Merge sort");
    questions[7].value = 400;
    questions[7].answered = false;

    //databases
    strcpy(questions[8].category, "databases");
    strcpy(questions[8].question, "What does SQL stand for?");
    strcpy(questions[8].answer, "Structured Query Language");
    questions[8].value = 100;
    questions[8].answered = false;

    strcpy(questions[9].category, "databases");
    strcpy(questions[9].question, "What is a schema?");
    strcpy(questions[9].answer, "Schema is a skeleton structre that represents the entire databases.");
    questions[9].value = 200;
    questions[9].answered = false;

    strcpy(questions[10].category, "databases");
    strcpy(questions[10].question, "What are datasets made of?");
    strcpy(questions[10].answer, "Data Object");
    questions[10].value = 300;
    questions[10].answered = false;

    strcpy(questions[11].category, "databases");
    strcpy(questions[11].question, "What are Tuples?");
    strcpy(questions[11].answer, "Tuples are sequences");
    questions[11].value = 400;
    questions[11].answered = false;
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    printf("Categories\n");

}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
  for(int i = 0; i < 12; i++) {
    if(questions[i].category == category && questions[i].value == value) {
      printf("Questions: %s dollar: %d\n",questions[i].question, questions[i].value);
    }
  }
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // Look into string comparison functions
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    for (int i = 0; i <= 12; i++) {
      if(questions[i].category == category && questions[i].value == value) {
        if (questions[i].answered == true) {
          return true;
        } else {
          return false;
        }
      }
    }
    return false;
}
