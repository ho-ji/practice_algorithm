function solution(sequence, k) {
  let answer = []
  let start = 0,
    end = 0,
    sum = 0
  for (let i = 0; i < sequence.length; i++) {
    sum += sequence[i]
    end = i
    while (sum > k) {
      sum -= sequence[start++]
    }
    if (sum === k) {
      if (answer.length === 0 || answer[1] - answer[0] > end - start) {
        answer = [start, end]
      }
      start = i + 1
      sum = 0
    }
  }
  return answer
}
