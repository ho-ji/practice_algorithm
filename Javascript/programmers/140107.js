function solution(k, d) {
  let answer = 0
  let list = []
  for (let i = 0; i <= d; i++) {
    if (i * k <= d) list.push(i * k)
    else break
  }
  let count = list.length
  for (const x of list) {
    let y = Math.floor(Math.sqrt(d ** 2 - x ** 2))
    while (y < list[count - 1]) {
      count--
    }
    answer += count
  }

  return answer
}
