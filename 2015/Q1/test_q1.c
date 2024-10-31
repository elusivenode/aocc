#include "./q1.c"
#include <criterion/criterion.h>

Test(q1, part1_1) {
  char *input_data = "(())";
  cr_assert_eq(part1(input_data), 0);
}

Test(q1, part1_2) {
  char *input_data = "()()";
  cr_assert_eq(part1(input_data), 0);
}

Test(q1, part1_3) {
  char *input_data = ")))";
  cr_assert_eq(part1(input_data), -3);
}

Test(q1, part2) {
  char *input_data = "()())";
  cr_assert_eq(part2(input_data), 5);
}