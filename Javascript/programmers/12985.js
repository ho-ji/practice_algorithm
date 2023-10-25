function solution(n, a, b) {
  let answer = 0
  if (a > b) [a, b] = [b, a]
  while (a / 2 !== b / 2) {
    answer++
    a = a % 2 === 0 ? a / 2 : (a + 1) / 2
    b = b % 2 === 0 ? b / 2 : (b + 1) / 2
  }
  return answer
}
