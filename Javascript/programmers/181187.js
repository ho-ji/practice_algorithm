function solution(r1, r2) {
  let count = 0
  for (let x = 1; x <= r2; x++) {
    let y2 = Math.floor(Math.sqrt(r2 ** 2 - x ** 2))
    let y1 = r1 > x ? Math.ceil(Math.sqrt(r1 ** 2 - x ** 2)) : 0
    count += y2 - y1 + 1
  }
  return count * 4
}
