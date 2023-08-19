function solution(s) {
  if (s.length !== 4 && s.length !== 6) return false
  let regex = /^[0-9]+$/
  if (!regex.test(s)) return false
  return true
}
