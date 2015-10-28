#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);
  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m(3);
	m[0][0] = 1;
	m[0][1] = 7;
	m[0][2] = 4;
	m[1][1] = 2;
	m[1][2] = 1;
	m[2][2] = 3;
	TMatrix<int> mc(m);
	EXPECT_EQ(mc, m);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m(10), b(m);
	EXPECT_NE(&m[0][0], &b[0][0]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(4);
	EXPECT_EQ(4, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(12);
	ASSERT_NO_THROW({ m[3][4] = 3; m[3][4]; });
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(12);
	ASSERT_ANY_THROW(m[-3][4] = 5);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(12);
	ASSERT_ANY_THROW(m[3][100] = 5);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(2);
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][1] = 3;
	ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m(12);
	TMatrix<int> b(12);
	ASSERT_NO_THROW(m = b);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m(10);
	TMatrix<int> b(3);
	int i = m.GetSize();
	m = b;
	EXPECT_NE(i, m.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m(12);
	TMatrix<int> b(2);
	ASSERT_NO_THROW(m = b);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m(2);
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][1] = 6;
	TMatrix<int> b(m);
	b[0][0] = 1;
	b[0][1] = 2;
	b[1][1] = 6;
	EXPECT_EQ(m, b);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m(2);
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][1] = 6;
	EXPECT_EQ(m, m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m(12);
	TMatrix<int> b(3);
	EXPECT_NE(m, b);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m(12);
	TMatrix<int> b(12);
	// FIX: fill
	ASSERT_NO_THROW(m + b);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m(12);
	TMatrix<int> b(2);
	// FIX: fill
	ASSERT_ANY_THROW(m + b);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m(12);
	TMatrix<int> b(12);
	// FIX: fill
	ASSERT_NO_THROW(m - b);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m(12);
	TMatrix<int> b(2);
	// FIX: fill
	ASSERT_ANY_THROW(m - b);
}

