
#include <iostream>

using namespace std;

int i, j;
const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
  int data[SIZE][SIZE];  // 2D array for matrix data (using int for simplicity)
   
public:
  // 1. Read values from stdin into a matrix
  void readFromStdin(){
    for (i = 0; i < SIZE; i++){ //iterates through every row of a matrix
      for (j = 0; j < SIZE; j++){ //iterates through every column of each row of a matrix
        cin >> data[i][j]; //takes in values from the user at each row and column (each position of the matrix)
      }
    }
  }

  // 2. Display a matrix
  void display() const{
    for (i = 0; i < SIZE; i++){ //iterates through every row of a matrix
      for (j = 0; j < SIZE; j++){ //iterates through every column of each row of a matrix
        cout << data[i][j] << ""; //prints out the value at each row and column of the matrix
      }
      cout << endl; //ends the output line at the end of each row, so that the output is a matrix(2d) and not a 1d list of the values
    }
  }

  // 3. Add two matrices (operator overloading for +)
  Matrix operator+(const Matrix& other) const{
    int mat1[SIZE][SIZE];
    int mat2[SIZE][SIZE];
    int sum[SIZE][SIZE];

    for (i = 0; i < SIZE; i++){ //iterates through every row of a matrix
      for (j = 0; j < SIZE; i++){ //iterates through every column of each row of a matrix
        sum[i][j] = (mat1[i][j] + mat2[i][j]); //sets the value of the sum matrix to the summation of the values of mat1 and mat2 at each i,j coordinate
      }
    }
  }

  // 4. Multiply two matrices (operator overloading for *)
  Matrix operator*(const Matrix& other) const{
    int mat1[SIZE][SIZE];
    int mat2[SIZE][SIZE];
    int product[SIZE][SIZE];

    for(i = 0; i < SIZE; i++){ //iterates through every row of a matrix
      for(j = 0; j < SIZE; j++){ //iterates through every column of each row of a matrix
        product[i][j] += (mat1[i][j] * mat2[j][i]); //product matrix value is the sum of all the row and column values of mat1 multiplied by the column and row values of mat2 (dot product)
      }
    }
  }

  // 5. Compute the sum of matrix diagonal elements
  int sumOfDiagonals() const{
    int sum = 0; //initialize a sum variable that starts at 0
    for (i = 0; i < SIZE; i++){ //iterates through each row of a matrix
      for (j = 0; j < SIZE; j++){ //iterates through each column of a matrix
        if (i == j){ //checks if both i and j values are equal (meaning the matrix coordinate is on the main diagonal)
          sum += data[i][j]; //adds the value at this position to the previous value of sum, thus increasing the value of the sum
        }
      }
    }
    cout << sum <<endl; //prints out the final sum a the end of the function call
  }

  // 6. Swap matrix rows
  void swapRows(int row1, int row2){
    int placeholder[SIZE]; //creates a placeholder row the same size as the array, which will be set to the values of row1 initially, before being re-written as the values of row2 after row2 has been changed to row1
    for (i = 0; i < SIZE; i++){ //iterates through all the rows of the main array(data)
      placeholder[i] = data[row1][i]; //sets the freshly defined placeholder array (1x4)(1 row 4 columns) to the values of the data in row 1 (numbers at 0-3 columns of row1)
      data[row1][i] = data[row2][i]; //sets the row1 data to row2, meaning the original data at row2 is replaced by the original data at row1
      data[row2][i] = placeholder[i]; //sets the row2 data to the placeholder data(which is the data at row1) meaning row2 now takes the position of the original row1
    }
  }
};

int main() {
  // Example usage:
  Matrix mat1;
  cout << "Enter values for Matrix 1:" << endl;
  mat1.readFromStdin();
  cout << "Matrix 1:" << endl;
  mat1.display();

  Matrix mat2;
  cout << "Enter values for Matrix 2:" << endl;
  mat2.readFromStdin();
  cout << "Matrix 2:" << endl;
  mat2.display();

  Matrix sum = mat1 + mat2;
  cout << "Sum of matrices:" << endl;
  sum.display();

  Matrix product = mat1 * mat2;
  cout << "Product of matrices:" << endl;
  product.display();

  cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

  mat1.swapRows(0, 2);
  cout << "Matrix 1 after swapping rows:" << endl;
  mat1.display();

  return 0;
}
