// òåñòû äëÿ ñòåêà


#include "stack.h"
#include <gtest.h>

TEST(Stack, can_create_stack)
{
	ASSERT_NO_THROW(TStack<int> s);
}
TEST(Stack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack <int> v(5));
}
TEST(Stack, cant_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> v(-5));
}
TEST(Stack, cant_create_stack_with_null_size)
{
	ASSERT_ANY_THROW(TStack<int> s(0));
}
TEST(Stack, cant_create_too_large_stack)
{
	ASSERT_ANY_THROW(TStack<int> v(MAX_STACK_SIZE + 1));
}
TEST(Stack, can_create_copied_stack)
{
	TStack<int> s;
	ASSERT_NO_THROW(TStack<int> s1(s));
}
TEST(Stack, can_push_element_in_stack)
{
	TStack<int> s;
	ASSERT_NO_THROW(s.push(5));
}
TEST(Stack, can_push_element_in_full_stack)
{
	TStack<int> s(2);
	s.push(8); s.push(2);
	s.push(5);
	EXPECT_EQ(5, s.getTop());
}
TEST(Stack, can_check_on_emptiness_for_empty_stack)
{
	TStack<int> s;
	EXPECT_EQ(true, s.isEmpty());
}
TEST(Stack, can_check_on_emptiness_for_not_empty_stack)
{
	TStack<int> s;
	s.push(3);
	EXPECT_EQ(false, s.isEmpty());
}
TEST(Stack, can_check_on_full_for_full_stack)
{
	TStack<int> s(2);
	s.push(1); s.push(2);
	EXPECT_EQ(true, s.isFull());
}
TEST(Stack, can_check_on_full_for_not_full_stack)
{
	TStack<int> s;
	EXPECT_EQ(false, s.isFull());
}
TEST(Stack, can_get_top_element_without_deletion)
{
	TStack<int> s(1);
	s.push(10);
	EXPECT_EQ(10, s.getTop());
	EXPECT_EQ(false, s.isEmpty());
}
TEST(Stack, can_pop_element)
{
	TStack<int> s;
	s.push(-9);
	EXPECT_EQ(-9, s.pop());
	EXPECT_EQ(true, s.isEmpty());
}
TEST(Stack, cant_pop_element_from_empty_stack)
{
	TStack<int> s;
	ASSERT_ANY_THROW(s.pop());
}
TEST(Stack, cant_get_top_element_from_empty_stack)
{
	TStack<int> s;
	ASSERT_ANY_THROW(s.getTop());
}
