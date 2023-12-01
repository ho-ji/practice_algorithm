function solution(n, t, m, p) {
  let answer = ''
  let str = ''
  for (let i = 0; str.length < t * m; i++) {
    str += i.toString(n).toUpperCase()
  }
  for (let i = p - 1; answer.length < t; i += m) {
    answer += str[i]
  }
  return answer
}
