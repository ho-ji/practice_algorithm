function solution(n) {
  if (n === 1) return '수'
  return '수박'.repeat(n / 2) + (n % 2 === 1 ? '수' : '')
}
