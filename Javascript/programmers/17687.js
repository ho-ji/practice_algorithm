function solution(n, t, m, p) {
  let answer = ''
  let str = ''
  for (let i = 0; str.length < t; i++) {
    str += i.toString(n).toUpperCase()
  }
  for (let i = p - 1; i <= t; i += m) {
    answer += str[i]
  }
  return answer
}
