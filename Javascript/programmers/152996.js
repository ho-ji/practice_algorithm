function solution(weights) {
  let answer = 0
  let count = new Array(1000).fill(0)
  for (const weight of weights) count[weight]++
  for (let i = 100; i <= 1000; i++) {
    answer += (count[i] * (count[i] - 1)) / 2
    if (i % 2 === 0 && (i / 2) * 3 <= 1000) answer += count[i] * count[(i / 2) * 3]
    if (i * 2 <= 1000) answer += count[i] * count[i * 2]
    if (i % 3 === 0 && (i / 3) * 4 <= 1000) answer += count[i] * count[(i / 3) * 4]
  }
  return answer
}
