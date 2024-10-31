#include "./q2.c"
#include <criterion/criterion.h>

Test(q2, part1_1) {
  char input_data[] = "2x3x4\0";
  cr_assert_eq(area_paper_req(input_data), 58);
}

Test(q2, part1_2) {
  char input_data[] = "1x1x10\0";
  cr_assert_eq(area_paper_req(input_data), 43);
}

Test(q2, part1_3) {
  char input_data[] = "22x19x18\0";
  cr_assert_eq(area_paper_req(input_data),
               2 * 22 * 19 + 2 * 19 * 18 + 2 * 18 * 22 + 18 * 19);
}
