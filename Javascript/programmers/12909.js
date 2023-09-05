function solution(s) {
  let ck = 1
  for (let i = 1; i < s.length; i++) {
    if (s[i] === '(') {
      ck++
    } else {
      if (check === 0) return false
      ck--
    }
  }
  if (ck !== 0) return false
  return true
}
