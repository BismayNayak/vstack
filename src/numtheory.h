#pragma once
#include <iostream>
#include <vector>
#include <cstdint>

int64_t ext_gcd(int64_t a,int64_t b,int64_t& x,int64_t& y);
void test_bezout();
int64_t binary_exp_mod(int64_t base ,int64_t exp ,int64_t mod);
void test_flt();