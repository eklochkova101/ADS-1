// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value < 2) return false;
  if (value == 2 || value == 3) return true;
  if (value % 2 == 0 || value % 3 == 0) return false;
  for (uint64_t i = 5; i <= value / i; i += 2) {
    if (value % i == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 1) return 2;
  if (n == 2) return 3;
  uint64_t counter = 2;
  for (uint64_t curr = 5; ; curr += 2 ) {
    bool isPrime = curr >= 2;
    if (curr > 2 && curr % 2 == 0) isPrime = false;
    for (uint64_t i = 3; i <= curr / i; i += 2) {
      if (curr % i == 0) isPrime = false;
    }
    if (isPrime && ++counter == n) return curr;
  }
}

uint64_t nextPrime(uint64_t value) {
  if (value < 2) return 2;
  uint64_t nextValue = value + 1;
  if (nextValue % 2 == 0) nextValue++;
  while (checkPrime(nextValue) != true) {
    nextValue += 2;
  }
  return nextValue;
}

uint64_t sumPrime(uint64_t hbound) {
  if (hbound <= 2) return 0;
  uint64_t summ = 2;
  for (uint64_t i = 3; i < hbound; i += 2) {
    if (checkPrime(i)) summ += i;
  }
  return summ;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t counter = 0;
  if (lbound % 2 == 0) lbound++;
  for (uint64_t curr = lbound; curr + 2 < hbound; curr += 2) {
    if (checkPrime(curr) && checkPrime(curr + 2)) counter++;
  }
  return counter;
}
