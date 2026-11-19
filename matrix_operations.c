#include <stdio.h>

#define MAX 10

void readMatrix(int m[MAX][MAX], int rows, int cols)
{
for (int i = 0; i < rows; i++)
for (int j = 0; j < cols; j++)
scanf("%d", &m[i][j]);
}

void printMatrix(int m[MAX][MAX], int rows, int cols)
{
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++)
printf("%d ", m[i][j]);
printf("\n");
}
}

int main(void)
{
int a[MAX][MAX], b[MAX][MAX], sum[MAX][MAX], diff[MAX][MAX];
int rows, cols;

printf("Enter number of rows and columns (max %d): ", MAX);
if (scanf("%d %d", &rows, &cols) != 2 ||
rows < 1 || rows > MAX || cols < 1 || cols > MAX) {
printf("Invalid size.\n");
return 1;
}

printf("Enter first matrix elements:\n");
readMatrix(a, rows, cols);

printf("Enter second matrix elements:\n");
readMatrix(b, rows, cols);

for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
sum[i][j] = a[i][j] + b[i][j];
diff[i][j] = a[i][j] - b[i][j];
}
}

printf("Addition of two matrices is:\n");
printMatrix(sum, rows, cols);

printf("Subtraction of two matrices is:\n");
printMatrix(diff, rows, cols);

return 0;
}
