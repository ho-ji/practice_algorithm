function solution(n) {
  const s = n.toString(2)
  let answer = 0
  for (let i = 0; i < s.length; i++) {
    if (s[i] === '1') answer++
  }
  return answer
}
