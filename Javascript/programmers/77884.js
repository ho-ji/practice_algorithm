function solution(left, right) {
  let answer = 0
  for (let n = left; n <= right; n++) {
    let count = 0
    for (let i = 1; i <= n * n; i++) {
      if (n % i === 0) count++
    }
    if (count % 2 === 0) answer += n
    else answer -= n
  }
  return answer
}
