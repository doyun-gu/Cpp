/* 
This code calculates BMR and Recommended intake in Kcal with user's height, weight, and age. 
Then how many grams of carbs, protein, and fat for every meal depends on the user's condition (Cutting or Bulking) 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {

    // Get the Data of weight, height, calories
    double weight, height, calories;
    int age, exercise;

    printf("Input Weight: ");
    scanf("%lf", &weight);

    printf("Input Height: ");
    scanf("%lf", &height);

    printf("Input age: ");
    scanf("%d", &age);

    // Calculate the BMR using Harris-Benedict Equation
    double BMR = 66.5 + (13.75 * weight) + (5.003 * height) - (6.75 * age);

    // Get the number of exercise a week for Activity Factor
    printf("Input No. of Exercise out of 7 days: ");
    scanf("%d", &exercise);

    if (exercise < 0 || exercise > 7) {
        printf("Error! The number must be between 0-7!");
        return 0;
    }

    if (exercise == 0) {
        calories = BMR * 1.2;
    }

    else if (exercise >= 1 && exercise <= 3) {
        calories = BMR * 1.375;
    }

    else if (exercise >= 4 && exercise <= 5) {
        calories = BMR * 1.55;
    }

    else if (exercise >= 6 && exercise <=7) {
        calories = BMR * 1.725;
    }

    // convert the calculated data into integer just for conveniency
    int BMR_int = (int)ceil(BMR);
    int calories_int = (int)ceil(calories);
    int dietplan;

    printf("Your Bascal Metabolic Rate = %d and Recommended Calories = %d Kcal\n", (BMR_int), (calories_int));

    // Cutting: - 500 Kcal Bulking: +500 Kcal
    printf("input '1' if Cutting otherwise '2': ");
    scanf("%d", &dietplan);

    if (dietplan == 1) {
        calories_int = calories_int - 500;
    }

    else {
        calories_int = calories_int + 500;
    }

    // Carbon : Protein: Fat = 4 : 4: 2
    int carbon_Kcal, protein_Kcal, fat_Kcal, rate_calories, meal_time;

    rate_calories = calories_int / 10;

    carbon_Kcal = rate_calories * 4;
    protein_Kcal = carbon_Kcal;
    fat_Kcal = carbon_Kcal/2;

    // Calculate the grams of Carbs, Protein, Fat every meal
    printf("How many times are you going to have meals a day? (3-5): ");
    scanf("%d", &meal_time);

    int carbon_aday_Kcal, protein_aday_Kcal, fat_aday_Kcal;

    if (meal_time == 3) {
        carbon_aday_Kcal = carbon_Kcal/3;
        protein_aday_Kcal = protein_Kcal/3;
        fat_aday_Kcal = fat_Kcal/3;
    }

    else if (meal_time == 4) {
        carbon_aday_Kcal = carbon_Kcal/4;
        protein_aday_Kcal = protein_Kcal/4;
        fat_aday_Kcal = fat_Kcal/4; 
    }

    else if (meal_time == 5) {
        carbon_aday_Kcal = carbon_Kcal/5;
        protein_aday_Kcal = protein_Kcal/5;
        fat_aday_Kcal = fat_Kcal/5;
    }

    else {
        printf("Error! only 3-5!");
        return -1;
    }

    // Convert Kcal into Grams: 1 Kcal = 0.129598 g
    double carbon_aday_gram, protein_aday_gram, fat_aday_gram;

    carbon_aday_gram = carbon_aday_Kcal * 0.129598;
    protein_aday_gram = carbon_aday_gram;
    fat_aday_gram = carbon_aday_gram/2;

    // Output
    printf("You should have %d Kcal in a day and %d g of carbon, %d g of protein, %d g of fat for every meal", (int)calories_int, (int)carbon_aday_gram, (int)protein_aday_gram, (int)fat_aday_gram);
    
    return 0;
}
