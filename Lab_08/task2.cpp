#include "header.hpp"


// Создает заполненную нулями матрицу n x m.
void Construct(Matrix& out, size_t n, size_t m) {
	out.data_ = new int* [m];
	out.n_ = n;
	out.m_ = m;
	for (int i = 0; i < m; i++) {
		out.data_[i] = new int[n];
		for (int j = 0; j < n; j++)
			out.data_[i][j] = 0;
	}
}

// Освобождает выделенную память.
void Destruct(Matrix& in) {
	for (int i = 0; i < in.m_; i++) 
		delete[] in.data_[i];	
	delete[] in.data_;
	in.data_ = nullptr;
	in.n_ = 0u;
	in.m_ = 0u;
}

// Создает копию матрицы |matrix|.
Matrix Copy(const Matrix& matrix) {
	Matrix out;
	out.data_ = new int* [matrix.m_];
	out.n_ = matrix.n_;
	out.m_ = matrix.m_;
	for (int i = 0; i < matrix.m_; i++) {
		out.data_[i] = new int[matrix.n_];
		for (int j = 0; j < matrix.n_; j++)
			out.data_[i][j] = matrix.data_[i][j];
	}
	return out;
}
// Возвращает сумму двух матриц.
// Если операция невозможна - вернуть пустую матрицу
Matrix Add(const Matrix& a, const Matrix& b) {
	Matrix out;
	if (a.m_ == b.m_ && a.n_ == b.n_) {
		out.data_ = new int* [a.m_];
		out.n_ = a.n_;
		out.m_ = a.m_;
		for (int i = 0; i < a.m_; i++) {
			out.data_[i] = new int[a.n_];
			for (int j = 0; j < a.n_; j++)
				out.data_[i][j] = a.data_[i][j] + b.data_[i][j];
		}
	}
	return out;
}
// Возвращает разницу двух матриц.
// Если операция невозможна - вернуть пустую матрицу
Matrix Sub(const Matrix& a, const Matrix& b) {
	Matrix out;
	if (a.m_ == b.m_ && a.n_ == b.n_) {
		out.data_ = new int* [a.m_];
		out.n_ = a.n_;
		out.m_ = a.m_;
		for (int i = 0; i < a.m_; i++) {
			out.data_[i] = new int[a.n_];
			for (int j = 0; j < a.n_; j++)
				out.data_[i][j] = a.data_[i][j] - b.data_[i][j];
		}
	}
	return out;
}
// Возвращает произведение двух матриц.
// Если операция невозможна - вернуть пустую матрицу
Matrix Mult(const Matrix& a, const Matrix& b) {
	Matrix out;
	if (a.n_ == b.m_ ) {
		int cols = b.n_, rows = a.m_, count = a.n_;
		out.data_ = new int* [rows];
		out.n_ = cols;
		out.m_ = rows;
		for (int i = 0; i < rows; i++) {
			out.data_[i] = new int[cols];
			for (int j = 0; j < cols; j++) {
				out.data_[i][j] = 0;
				for (int k = 0; k < count; k++) {
					out.data_[i][j] += a.data_[i][k] * b.data_[k][j];
				}
			}	
		}
	}
	return out;
}

// Транспонирование матрицы.
void Transposition(Matrix& matrix) {
	Matrix out;
	out.data_ = new int* [matrix.n_];
	out.n_ = matrix.m_;
	out.m_ = matrix.n_;
	for (int i = 0; i < matrix.n_; i++) {
		out.data_[i] = new int[matrix.m_];
		for (int j = 0; j < matrix.m_; j++)
			out.data_[i][j] = matrix.data_[j][i];
	}
	Destruct(matrix);
	matrix = out;
}

// Сравнение двух матриц.
bool operator==(const Matrix& a, const Matrix& b) {
	if (a.m_ != b.m_ or a.n_ != b.n_)
		return false;
	for (int i = 0; i < a.m_; i++) 
		for (int j = 0; j < a.n_; j++)
			if (a.data_[i][j] != b.data_[i][j])
				return false;
	return true;
}
