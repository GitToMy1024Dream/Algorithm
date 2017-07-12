#include <iostream>
using namespace std;
void PrintMatrix(int** matrix, int rows, int cols, int start);
void Matrix(int** matrix, int rows, int cols)
{
	if (matrix == NULL || rows <= 0 || cols <= 0)
		return;
	int start = 0;
	while (start * 2 < rows && start * 2 < cols)
	{
		PrintMatrix(matrix, rows, cols, start);
		++start;
	}
}

void PrintMatrix(int** matrix, int rows, int cols, int start)
{
	int endX = cols - start - 1;
	int endY = rows - start - 1;
	//left->right
	for (int i = start; i <= endX; ++i)
	{
		int num = matrix[start][i];
		cout << num << " ";
	}
	//top->down
	if (endY > start)
	{
		for (int i = start + 1; i <= endY; ++i)
		{
			int num = matrix[i][endX];
			cout << num << " ";
		}
	}
	//right->left
	if (endX > start)
	{
		for (int i = endX - 1; i >= start; --i)
		{
			int num  = matrix[endY][i];
			cout << num << " ";
		}
	}
	//down->top
	if (start < endX && start < endY)
	{
		for (int i = endY - 1; i > start; i--)
		{
			int num = matrix[i][start];
			cout << num << " ";
		}
	}
}
void FunTest(int rows,int cols)
{
	int** matrix = new int*[rows];
	for (int i = 0; i < rows; ++i)
	{
		matrix[i] = new int[rows];
		for (int j = 0; j < cols; ++j)
		{
			matrix[i][j] = i * cols + j + 1;
		}
	}
	Matrix(matrix, 4, 4);
	cout << endl;
}
int main()
{
	int matrix[][4] = { 1,2,3,4,
						5,6,7,8,
						9,10,11,12,
						13,14,15,16 };
  	FunTest(4, 4);
	system("pause");
	return 0;
}