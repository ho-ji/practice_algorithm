function solution(sequence, k) {
  let answer = [0, 1000000]
  let start = 0,
    end = 0,
    sum = sequence[0]
  while (end < sequence.length) {
    if (sum === k) {
      if (answer[1] - answer[0] > end - start) {
        answer = [start, end]
      }
      sum -= sequence[start++]
      sum += sequence[++end]
    } else if (sum > k) {
      sum -= sequence[start++]
    } else {
      sum += sequence[++end]
    }
  }
  return answer
}
