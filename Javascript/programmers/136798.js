function solution(number, limit, power) {
  let result = 1
  for (let n = 1; n <= number; n++) {
    let count = 0
    for (let i = 1; i * i <= n; i++) {
      if (n % i === 0) {
        count++
        if (i * i < n) count++
      }
      if (count > limit) {
        count = power
        break
      }
    }
    result += count
  }
  return result
}
