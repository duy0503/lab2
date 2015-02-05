#include <stdio.h>

//function to calculate the average score of above average
float average(int score[100], int number_people);

int main()
{
  int score[100];                 //create an array to hold 100 values
  int number_of_people = 0;           //variable to hold the total number of people
  int input_value = 0;            //variable to hold user's input value
  float above_average_score = 0.0;  //variable to hold value of the average of above average score
  puts("Input value: ");
  scanf("%d", &input_value);      //get user's input

  //while loop to keep user input values into the array, loop will exit when input value is a negative number
  while(input_value >= 0){
    ++number_of_people;
    score[number_of_people - 1] = input_value;
    scanf("%d",&input_value);
  }

  //call function average, the return value is assigned to above_average_score
  above_average_score = average(score, number_of_people);
  printf("The average score of above average is %.6f\n", above_average_score);
  return 0;
}

//implementing function average
float average(int score[100], int number_people)
{
  float sum = 0.0;
  //calculate the sum of all values
  for(int i= 0; i<number_people; i++){
    sum += score[i];
  }
  float average = 0.0;
  average = sum/number_people;         //calculate the avarage score of all values
  int above_average = 0;               //variable to keep track of the number of values above average
  sum = 0.0;         //reset the sum to hold total score of all the above average value

  //calculate the sum of all values that are above average
  for(int i = 0; i< number_people; i++){
    if(score[i] > average){
      ++above_average;
      sum += score[i];
    }
  }
  //return the average of the sum of all the values that are above average
  return sum/above_average;
}    
