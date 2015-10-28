#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v(3);
	v[0] = 2;
	v[1] = 5;
	v[2] = 6; 
	TVector<int> b(v);
	EXPECT_EQ(v, b);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v(3);
	v[0] = 2;
	v[1] = 5;
	v[2] = 6;
	TVector<int> b(v);
	EXPECT_NE(&v[0], &b[0]);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);
  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(10);
	ASSERT_ANY_THROW(v[-3] = 1);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(10);
	ASSERT_ANY_THROW(v[10] = 100);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(10);
	ASSERT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v(3);
	v[0] = 1;
	v[1] = 5;
	v[2] = 3;
	TVector<int> b(3);
	ASSERT_NO_THROW(v = b);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v(10);
	TVector<int> b(3);
	int i = v.GetSize();
	v = b;
	EXPECT_NE(i, v.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v(2);
	TVector<int> b(3);
	ASSERT_NO_THROW(v = b);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v(5);
	TVector<int> b(5);
	for (int i = 0; i < 5; i++)
	{
		v[i] = i;
		b[i] = i;
	}
	EXPECT_EQ(v, b);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(10);
	for (int i = 0; i < 10; i++)
		v[i] = i;
	EXPECT_EQ(v, v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v(10);
	TVector<int> b(4);
	for (int i = 0; i < 10; i++)
		v[i] = i;
	for (int i = 0; i < 4; i++)
		b[i] = 2;
	EXPECT_NE(v, b);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<float> v(5);
	// FIX: fill
	ASSERT_NO_THROW(v + 5);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<float> v(5);
	// FIX: fill
	ASSERT_NO_THROW(v - 5);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<float> v(5);
	// FIX: fill
	ASSERT_NO_THROW(v * 5);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<float> v(5);
	TVector<float> b(5);
	// FIX: fill
	ASSERT_NO_THROW(v + b);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<float> v(5);
	TVector<float> b(8);
	// FIX: fill
	ASSERT_ANY_THROW(v + b);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<float> v(5);
	TVector<float> b(5);
	// FIX: fill
	ASSERT_NO_THROW(v - b);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<float> v(5);
	TVector<float> b(8);
	// FIX: fill
	ASSERT_ANY_THROW(v - b);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<float> v(5);
	TVector<float> b(5);
	// FIX: fill
	ASSERT_NO_THROW(v * b);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<float> v(5);
	TVector<float> b(8);
	// FIX: fill
	ASSERT_ANY_THROW(v * b);
}

