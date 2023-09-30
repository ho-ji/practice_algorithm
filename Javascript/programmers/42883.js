function solution(number, k) {
  let answer = ''
  const list = [...number].map((value, i) => [value, i])
  let start = 0
  for (let i = list.length - k - 1; i >= 0; i--) {
    let max = list[start]
    for (let j = start + 1; j < list.length - i; j++) {
      if (max[0] < list[j][0]) max = list[j]
      if (max[0] === '9') break
    }
    answer += max[0]
    start = max[1] + 1
  }
  return answer
}
