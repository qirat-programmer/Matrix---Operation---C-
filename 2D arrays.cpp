#include <stdio.h>

#define MAX 10

// Function to input a matrix
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter elements of the matrix (%dx%d):\n", rows, cols);
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);
}

// Function to display a matrix
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }
}

// Function for matrix addition
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            result[i][j] = A[i][j] + B[i][j];
}

// Function for matrix multiplication
void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int r1, int c1, int c2) {
    for(int i = 0; i < r1; i++)
        for(int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < c1; k++)
                result[i][j] += A[i][k] * B[k][j];
        }
}

// Function for transpose of a matrix
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            result[j][i] = matrix[i][j];
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2, choice;

    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &r1, &c1);
    inputMatrix(A, r1, c1);

    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &r2, &c2);
    inputMatrix(B, r2, c2);

    do {
        printf("\n--- Matrix Operations Menu ---\n");
        printf("1. Addition\n2. Multiplication\n3. Transpose (Matrix A)\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(r1 == r2 && c1 == c2) {
                    addMatrices(A, B, result, r1, c1);
                    printf("\nMatrix Addition Result:\n");
                    displayMatrix(result, r1, c1);
                } else {
                    printf("\nAddition not possible. Matrices dimensions must be same.\n");
                }
                break;

            case 2:
                if(c1 == r2) {
                    multiplyMatrices(A, B, result, r1, c1, c2);
                    printf("\nMatrix Multiplication Result:\n");
                    displayMatrix(result, r1, c2);
                } else {
                    printf("\nMultiplication not possible. Columns of A must equal rows of B.\n");
                }
                break;

            case 3:
                transposeMatrix(A, result, r1, c1);
                printf("\nTranspose of Matrix A:\n");
                displayMatrix(result, c1, r1);
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while(choice != 4);

    return 0;
}
