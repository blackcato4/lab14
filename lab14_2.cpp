#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

//Do not modify source code above this line 

void inputMatrix(double A[][N]){
	for(int i = 0; i < N; i++){
		cout << "Row " << i+1 << ": ";
		for(int j = 0; j < N; j++){
			cin >> A[i][j];
		}
	}
}

void findLocalMax(const double A[][N], bool B[][N]){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			B[i][j] = false;
		}
	}

	for(int i = 1; i < N-1; i++){
		for(int j = 1; j < N-1; j++){
			bool isMax = true;
			double current = A[i][j];
			
			if(A[i-1][j] > current) isMax = false;
			if(A[i+1][j] > current) isMax = false;
			if(A[i][j-1] > current) isMax = false;
			if(A[i][j+1] > current) isMax = false;
			
			B[i][j] = isMax;
		}
	}
}

void showMatrix(const bool B[][N]){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << B[i][j] << " ";
		}
		cout << "\n";
	}
}