function solution(s, n) {
  let answer = ''
  for (const word of s) {
    if (word === ' ') {
      answer += ' '
    } else {
      let x = word.charCodeAt()
      if (x <= 'Z'.charCodeAt() && x + n > 'Z'.charCodeAt()) {
        x -= 26
      } else if (x + n > 'z'.charCodeAt()) {
        x -= 26
      }
      x += n
      answer += String.fromCharCode(x)
    }
  }
  return answer
}
