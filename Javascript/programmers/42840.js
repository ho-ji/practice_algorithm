function solution(answers) {
  let result = [],
    maxCount = -1
  const solvePattern = [
    [1, 2, 3, 4, 5],
    [2, 1, 2, 3, 2, 4, 2, 5],
    [3, 3, 1, 1, 2, 2, 4, 4, 5, 5],
  ]
  for (let n = 0; n < 3; n++) {
    let correctCount = 0
    let len = solvePattern[n].length
    for (let i = 0; i < answers.length; i++) {
      if (answers[i] === solvePattern[n][i % len]) {
        correctCount++
      }
    }
    if (correctCount === maxCount) {
      result.push(n + 1)
    } else if (correctCount > maxCount) {
      result = [n + 1]
      maxCount = correctCount
    }
  }
  return result
}
