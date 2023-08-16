function solution(n) {
  let sq = Math.sqrt(n)
  if (Number.isInteger(sq)) return (sq + 1) ** 2
  return -1
}
