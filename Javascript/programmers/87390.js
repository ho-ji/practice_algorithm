function solution(n, left, right) {
  const answer = []
  for (let i = left; i <= right; i++) {
    let y = parseInt(i / n) + 1
    let x = (i % n) + 1
    y <= x ? answer.push(x) : answer.push(y)
  }
  return answer
}
