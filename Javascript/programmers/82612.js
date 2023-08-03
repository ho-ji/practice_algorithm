function solution(price, money, count) {
  for (let n = 1; n <= count; n++) {
    money -= n * price
  }
  return money > 0 ? 0 : -1 * money
}
