function solution(dartResult) {
  let scores = [],
    score
  for (let i = 0; i < dartResult.length; i++) {
    if (!isNaN(dartResult[i])) {
      score = parseInt(dartResult[i])
      if (dartResult[i + 1] === '0') {
        i++
        score = 10
      }
      scores.push(score)
    } else if (dartResult[i] === 'D') {
      score = scores.pop()
      scores.push(score ** 2)
    } else if (dartResult[i] === 'T') {
      score = scores.pop()
      scores.push(score ** 3)
    } else if (dartResult[i] === '*') {
      let score = scores.pop()
      if (scores.length !== 0) {
        let temp = scores.pop()
        scores.push(temp * 2)
      }
      scores.push(score * 2)
    } else if (dartResult[i] === '#') {
      let score = scores.pop()
      scores.push(score * -1)
    }
  }
  return scores[0] + scores[1] + scores[2]
}
