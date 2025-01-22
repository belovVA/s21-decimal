
#include "../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int fail = 0;
  s21_null_decimal(dst);
  if (!dst) {
    // Если указатель на decimal является NULL
    fail = 1;
  } else if (src == 0.0) {
    // Если ноль
    *dst = s21_decimal_get_zero();
    *dst = s21_sign(src, *dst);
  } else if (isinf(src) || isnan(src)) {
    // Отдельно обрабатываем +inf, -inf, +nan, и -nan
    s21_null_decimal(dst);
    *dst = s21_sign(src, *dst);
    fail = 1;
  } else if (fabsf(src) > MAX_FLOAT_TO_CONVERT) {
    // максимальное число, которое можно сконвертировать в decimal
    fail = 1;
    s21_null_decimal(dst);
    *dst = s21_sign(src, *dst);
  } else if (fabsf(src) < MIN_FLOAT_TO_CONVERT) {
    // минимальное число, которое можно сконвертировать в decimal
    fail = 1;
    s21_null_decimal(dst);
  } else {
    s21_null_decimal(dst);
    char str[1000] = "";
    sprintf(str, "%.7g", src);
    // printf("str %s\n", str);
    int exp = s21_get_float_exp_from_string(str);
    // int first_exp = exp; // суббота (для ласт теста)
    exp = s21_string_exp(exp, str);

    s21_decimal_num(dst, str);

    // printf("exp %d\n", exp);
    //  суббота (для 166 теста и 167)
    s21_min_exp(dst, exp);

    if (src < 0) s21_set_sign(dst, 1);
  }
  return fail;
}

s21_decimal s21_sign(float flot, s21_decimal src) {
  if (signbit(flot) != 0) {
    s21_set_sign(&src, 1);
  }
  return src;
}

int s21_get_float_exp_from_string(char *str) {
  int result = 0;
  char *ptr = str;
  while (*ptr) {
    if (*ptr == 'e') {
      ++ptr;
      result = strtol(ptr, NULL, 10);
      break;
    }
    ++ptr;
  }

  return result;
}

s21_decimal s21_decimal_get_zero(void) {
  s21_decimal result;
  s21_null_decimal(&result);
  return result;
}

int s21_string_exp(int exp, char str[]) {
  int flag = 0;
  if (exp > 0) {
    exp = 0;
    flag = 1;
  }
  char *ptr = strchr(str, '.') + 1;  // начало строки
  if (strchr(str, '.') != NULL && !flag) {
    while (*ptr != 'e' && *ptr != '\0') {
      if (exp < 0)
        exp -= 1;
      else
        exp += 1;
      ptr++;
    }
  }
  return exp;
}

void s21_decimal_num(s21_decimal *dst, char str[]) {
  s21_decimal num = {0};
  s21_decimal ten = {0};
  ten.bits[0] = 10;
  char *ptr = str;
  while (*ptr != 'e' && *ptr != '\0') {
    if (isdigit(*ptr)) {
      num.bits[0] = *ptr - '0';
      s21_add(*dst, num, dst);  // суммируем к дст если число
      if (*(ptr + 1) != 'e' &&
          *(ptr + 1) != '\0')  // если не последняя итерация
        s21_mul(*dst, ten, dst);  // умножаем на 10 для следующего
    }
    ptr++;
  }
}

void s21_min_exp(s21_decimal *dst, int exp) {
  if (exp < -28) {
    s21_big_decimal one = {0};
    s21_big_decimal tmp = {0};
    s21_from_dec_to_big(*dst, &tmp);
    one.bits[0] = 1;
    int rzn = -exp - 28;
    for (int i = 0; i < rzn; i++) {
      int ost = s21_big_ost_10(tmp);
      s21_big_div_10(tmp, 0, &tmp);
      if (ost >= 5) tmp = s21_sum_big(tmp, one);
    }
    s21_from_big_to_dec(tmp, dst);
    s21_set_scale(dst, 28);
  } else
    s21_set_scale(dst, abs(exp));
}