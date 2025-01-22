#ifndef S21_CONVERTER_H
#define S21_CONVERTER_H
#define MAX_FLOAT_TO_CONVERT 79228157791897854723898736640.0f
#define MIN_FLOAT_TO_CONVERT \
  0.00000000000000000000000000010000000031710768509710513471352647538147514756461109f

// big_to_dec
int s21_scale_downgrade(s21_big_decimal *n, int *flag);
int s21_from_big_to_dec(s21_big_decimal value_1, s21_decimal *value_2);
void s21_convert_proccess(s21_big_decimal value_1, s21_decimal *value_2);
int s21_check_high_bits(s21_big_decimal value_1);

// dec_to_big
void s21_from_dec_to_big(s21_decimal src, s21_big_decimal *dst);

// int&dec
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);

// float&dec
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// help funcs for converting
s21_decimal s21_sign(float flot, s21_decimal src);
int s21_get_float_exp_from_string(char *str);
s21_decimal s21_decimal_get_zero(void);
int s21_string_exp(int exp, char str[]);
void s21_decimal_num(s21_decimal *dst, char str[]);
void s21_min_exp(s21_decimal *dst, int exp);
//
int s21_scale_upgrade(s21_big_decimal *n);

#endif  // S21_CONVERTER_H