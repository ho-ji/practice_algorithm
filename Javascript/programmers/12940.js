function solution(n, m) {
  let x = 1
  for (let i = Math.min(n, m); i > 0; i--) {
    if (n % i === 0 && m % i === 0) {
      x = i
      break
    }
  }
  return [x, (n * m) / x]
}
