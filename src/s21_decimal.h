#ifndef SRC_S21_DECIMAL_H
#define SRC_S21_DECIMAL_H

typedef struct {
  int bits[4];
} s21_decimal;

typedef struct {
  int bits[8];
} s21_big_decimal;

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./arithmetic/s21_arithmetic.h"
#include "./comparison/s21_compare.h"
#include "./convertors/s21_converter.h"
#include "./help_funcs/s21_align_scale.h"
#include "./help_funcs/s21_base_func.h"
#include "./rounding/s21_rounding.h"
#endif  // SRC_S21_DECIMAL_H