function solution(a, b, n) {
  let answer = 0
  while (n >= a) {
    answer += b
    n = n - a + b
  }
  return answer
}
