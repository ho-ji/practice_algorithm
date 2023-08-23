function solution(arr, divisor) {
  let answer = []
  for (const a of arr) {
    if (a % divisor === 0) answer.push(a)
  }
  if (!answer.length) return [-1]
  return answer.sort((a, b) => a - b)
}
