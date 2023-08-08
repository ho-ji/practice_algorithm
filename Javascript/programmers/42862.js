function solution(n, lost, reserve) {
  let count = 0
  lost.sort((a, b) => a - b)
  reserve.sort((a, b) => a - b)

  for (let i = 0; i < lost.length; i++) {
    for (let j = 0; j < reserve.length; j++) {
      if (lost[i] === reserve[j]) {
        lost[i] = -1
        reserve[j] = -1
        count++
      }
    }
  }
  for (let i = 0; i < lost.length; i++) {
    if (lost[i] !== -1) {
      for (let j = 0; j < reserve.length; j++) {
        if (lost[i] - 1 === reserve[j]) {
          count++
          reserve[j] = -1
          break
        } else if (lost[i] + 1 === reserve[j]) {
          count++
          reserve[j] = -1
          break
        }
      }
    }
  }
  return n - lost.length + count
}
