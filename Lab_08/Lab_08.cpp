#include "header.hpp"


void ShowMatrix(Matrix& in) {
	std::cout << "rows: " << in.m_ << "\n";
	std::cout << "cols: " << in.n_ << "\n";
	for (int i = 0; i < in.m_; i++) {
		for (int j = 0; j < in.n_; j++)
			std::cout << in.data_[i][j] << " ";
		std::cout << '\n';
	}
}


int main() {
	std::cout << "Task #1\n";
	char a[] = "Hello!";
	char* b = CopyString(a);
	std::cout << b << "\n";
	char d[] = "Bye?";
	char* c = ConcatinateStrings(d, b);
	std::cout << c << "\n";


	std::cout << "\nTask #2\n";
	Matrix mat;
	Construct(mat, 3, 4);
	ShowMatrix(mat);
	Destruct(mat);
	Matrix A, B, C;
	Construct(A, 3, 2); 
	Construct(B, 3, 2);
	Construct(C, 4, 3);
	// A
	A.data_[0][0] = 1; A.data_[0][1] = 2; A.data_[0][2] = 3;
	A.data_[1][0] = 4; A.data_[1][1] = 5; A.data_[1][2] = 6;

	// B
	B.data_[0][0] = 7; B.data_[0][1] = 8; B.data_[0][2] = 9;
	B.data_[1][0] = 1; B.data_[1][1] = 2; B.data_[1][2] = 3;

	// C 
	C.data_[0][0] = 1; C.data_[0][1] = 2; C.data_[0][2] = 3; C.data_[0][3] = 4;
	C.data_[1][0] = 0; C.data_[1][1] = 1; C.data_[1][2] = 0; C.data_[1][3] = 1;
	C.data_[2][0] = 2; C.data_[2][1] = 0; C.data_[2][2] = 1; C.data_[2][3] = 0;

	mat = Copy(A);
	ShowMatrix(mat);
	Destruct(mat);
	mat = Add(A, B);
	ShowMatrix(mat);
	Destruct(mat);
	mat = Sub(A, B);
	ShowMatrix(mat);
	Destruct(mat);
	mat = Mult(A, C);
	ShowMatrix(mat);
	Transposition(mat);
	ShowMatrix(mat);
	Destruct(mat);
	std::cout << (A == B) << '\n';
	return 0;
}