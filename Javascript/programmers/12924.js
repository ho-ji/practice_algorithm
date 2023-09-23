function solution(n) {
  let answer = 0
  let sum = 0
  let start = 0
  let end = 0
  while (start < n) {
    if (sum < n) {
      sum += ++end
    } else {
      if (sum === n) answer++
      sum -= ++start
    }
  }
  return answer
}
