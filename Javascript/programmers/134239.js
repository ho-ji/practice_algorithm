function solution(k, ranges) {
  let answer = []
  let sequence = [k]
  let area = []
  let n = 0
  while (k !== 1) {
    if (k % 2 === 0) k /= 2
    else k = k * 3 + 1
    sequence.push(k)
    n++
  }

  for (let i = 0; i < n; i++) {
    area[i] = sequence[i + 1] - (sequence[i + 1] - sequence[i]) / 2
  }
  for (const range of ranges) {
    let start = range[0]
    let end = n + range[1]
    let result = 0
    for (let i = start; i < end; i++) {
      result += area[i]
    }
    if (start > end) result = -1
    answer.push(result)
  }
  return answer
}
