function solution(n) {
  let count = [...n.toString(2)].filter((x) => x === '1').length
  let number = n + 1
  while ([...number.toString(2)].filter((x) => x === '1').length !== count) number++
  return number
}
