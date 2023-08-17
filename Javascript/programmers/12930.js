function solution(s) {
  let answer = ''
  let index = 0
  for (const word of s) {
    if (word === ' ') {
      index = 0
      answer += ' '
      continue
    }
    index % 2 ? (answer += word.toLowerCase()) : (answer += word.toUpperCase())
    index++
  }
  return answer
}
