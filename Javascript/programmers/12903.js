function solution(s) {
  const mid = parseInt(s.length / 2)
  return s.length % 2 ? s[mid] : s[mid - 1] + s[mid]
}
