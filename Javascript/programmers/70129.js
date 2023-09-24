function solution(s) {
  let count = [0, 0]
  while (s !== 1) {
    count[1] += [...s.toString(2)].length
    s = [...s.toString(2)].filter((x) => x === '1').length
    count[1] -= s
    count[0]++
  }
  return count
}
