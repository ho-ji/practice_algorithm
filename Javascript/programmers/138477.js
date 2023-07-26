function solution(k, score) {
  let answer = [],
    lank = []
  for (const s of score) {
    lank.push(s)
    lank.sort((a, b) => a - b)
    if (lank.length > k) lank.shift()
    answer.push(lank[0])
  }
  return answer
}
