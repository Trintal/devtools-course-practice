//
// Copyright 2018 Batanina Liubov
//

 #ifndef MODULES_MATRIX_CALCULATOR_INCLUDE_MATRIX_OPERATION_HPP_
 #define MODULES_MATRIX_CALCULATOR_INCLUDE_MATRIX_OPERATION_HPP_


 #include "include/matrix_calculator.h"

class MatrixOperation {
	public:
	MatrixOperation() = default;
	MatrixCalculator operator()(int argc, const char** argv);
  std::vector<matrix_type> getInputMatrix();
	private:
  std::vector<matrix_type> inputs;
  matrix_type create_random_matrix(int rows, int cols);
	bool validate_data(int argc, const char** argv);
  int find_operation(std::string operation);
};

#endif  // MODULES_MATRIX_CALCULATOR_INCLUDE_MATRIX_OPERATION_HPP_
