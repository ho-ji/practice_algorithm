function solution(strings, n) {
  return strings.sort((a, b) => {
    if (a[n] === b[n]) {
      return b < a ? 1 : -1
    }
    return b[n] < a[n] ? 1 : -1
  })
}
