const solution = (n) => {
  const answer = new Array(n).fill().map((_, i) => new Array(i + 1).fill(0))
  const total = (n * (n + 1)) / 2
  let [i, j, count] = [0, 0, 1]

  while (count <= total) {
    while (i < n && answer[i][j] === 0) {
      answer[i][j] = count++
      i++
    }
    i--
    j++
    while (j < n && answer[i][j] === 0) {
      answer[i][j] = count++
      j++
    }
    i--
    j -= 2
    while (i > 0 && j > 0 && answer[i][j] === 0) {
      answer[i][j] = count++
      i--, j--
    }
    i += 2
    j++
  }
  return [].concat(...answer)
}
