function solution(n) {
  let answer = 0
  let key = []
  for (let i = 2; i <= n; i++) {
    if (!key[i]) {
      answer++
      for (let j = i; j <= n; j += i) key[j] = true
    }
  }
  return answer
}
