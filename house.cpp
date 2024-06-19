#include <stdio.h>

int main() {
    int income,h_rent,g_bill,e_bill,i_bill,insurance,health,education,other,expenses,savings,tar_percent;
    float act_percent;
    char name[20];

    // Input file
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Output file
    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Read data from input file
    fscanf(input_file, "%s", name);
    fscanf(input_file, "%d", &tar_percent);
    fscanf(input_file, "%d", &income);
    fscanf(input_file, "%d", &h_rent);
    fscanf(input_file, "%d", &g_bill);
    fscanf(input_file, "%d", &e_bill);
    fscanf(input_file, "%d", &i_bill);
    fscanf(input_file, "%d", &insurance);
    fscanf(input_file, "%d", &health);
    fscanf(input_file, "%d", &education);
    fscanf(input_file, "%d", &other);

    // Calculate expenses and savings
    expenses = h_rent + g_bill + e_bill + i_bill + insurance + other;
    savings = income - expenses;

    // Calculate actual percentage savings
    act_percent=(float)savings/income*100;

    // Display output in console
    printf("Name: %s\n", name);
    printf("Savings Goal: %d%%\n", tar_percent);
    printf("Income: %d\n", income);
    printf("Expenses: %d\n", expenses);
    printf("Savings: %d\n", savings);
    printf("Actual Savings Percentage: %.2f%%\n", act_percent);

    // Write output to output file
    fprintf(output_file, "Name: %s\n", name);
    fprintf(output_file, "Savings Goal: %d%%\n", tar_percent);
    fprintf(output_file, "Income: %d\n", income);
    fprintf(output_file, "Expenses: %d\n", expenses);
    fprintf(output_file, "Savings: %d\n", savings);
    fprintf(output_file, "Actual Savings Percentage: %.2f%%\n", act_percent);

    // Close files
    fclose(input_file);
    fclose(output_file);

    return 0;
}
