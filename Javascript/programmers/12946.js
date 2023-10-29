function solution(n) {
  let answer = []
  const hanoi = (count, from, to, other) => {
    if (count === 0) return
    hanoi(count - 1, from, other, to)
    answer.push([from, to])
    hanoi(count - 1, other, to, from)
  }
  hanoi(n, 1, 3, 2)
  return answer
}
