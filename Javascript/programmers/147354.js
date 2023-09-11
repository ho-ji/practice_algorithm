function solution(data, col, row_begin, row_end) {
  let answer = 0
  data.sort((e1, e2) => {
    if (e1[col - 1] === e2[col - 1]) return e2[0] - e1[0]
    else return e1[col - 1] - e2[col - 1]
  })
  for (let i = row_begin - 1; i < row_end; i++) {
    let sum = 0
    for (const d of data[i]) {
      sum += d % (i + 1)
    }
    answer = answer ^ sum
  }
  return answer
}
