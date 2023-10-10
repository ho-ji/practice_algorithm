function solution(s) {
  let answer = s[0].toUpperCase()
  for (let i = 1; i < s.length; i++) {
    answer += s[i - 1] === ' ' ? s[i].toUpperCase() : s[i].toLowerCase()
  }
  return answer
}
