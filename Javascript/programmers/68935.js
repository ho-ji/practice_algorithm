function solution(n) {
  let num = []
  let answer = 0
  while (n > 0) {
    num.push(n % 3)
    n = parseInt(n / 3)
  }
  for (let i = 0; i < num.length; i++) {
    answer += 3 ** (num.length - 1 - i) * num[i]
  }
  return answer
}
