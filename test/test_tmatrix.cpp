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
	TMatrix<int> m(10);
	TMatrix<int> b(m);
	EXPECT_EQ(m, b);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m(10);
	TMatrix<int> b(10);
	EXPECT_NE(&m[0], &b[0]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(4);
	EXPECT_EQ(4, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<char> m(12);
	ASSERT_NO_THROW({ m[3][4] = 3; m[3][4]; });
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<char> m(12);
	ASSERT_ANY_THROW(m[-3][4] = 5);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<char> m(12);
	ASSERT_ANY_THROW(m[3][100] = 5);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<char> m(12);
	ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<char> m(12);
	TMatrix<char> b(12);
	ASSERT_NO_THROW(m = b);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<char> m(10);
	TMatrix<char> b(3);
	int i = m.GetSize();
	m = b;
	EXPECT_NE(i, m.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<char> m(12);
	TMatrix<char> b(2);
	ASSERT_NO_THROW(m = b);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<char> m(12);
	TMatrix<char> b(m);
	EXPECT_EQ(m == b, true);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<char> m(12);
	EXPECT_EQ(m == m, true);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<char> m(12);
	TMatrix<char> b(3);
	EXPECT_EQ(m != b, true);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<char> m(12);
	TMatrix<char> b(12);
	ASSERT_NO_THROW(m + b);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<char> m(12);
	TMatrix<char> b(2);
	ASSERT_ANY_THROW(m + b);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<char> m(12);
	TMatrix<char> b(12);
	ASSERT_NO_THROW(m - b);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<char> m(12);
	TMatrix<char> b(2);
	ASSERT_ANY_THROW(m - b);
}

