const solution = (n, info) => {
  const sum = info.reduce((arr, cur, i) => arr + !!cur * (10 - i), 0)
  let max = 0
  const result = Array(info.length).fill(0)
  const result_list = []
  const dfs = (apeachSum, lionSum, lionN, i) => {
    if (lionN < 0) return
    if (i === info.length) {
      if (apeachSum < lionSum) {
        if (lionN > 0) result[10] += lionN
        if (max < lionSum - apeachSum) max = lionSum - apeachSum
        result_list.push([[...result], lionSum - apeachSum])
      }
      return
    }
    result[i] = info[i] + 1
    dfs(info[i] !== 0 ? apeachSum - 10 + i : apeachSum, lionSum + 10 - i, lionN - info[i] - 1, i + 1)
    result[i] = 0
    dfs(apeachSum, lionSum, lionN, i + 1)
  }

  dfs(sum, 0, n, 0)
  if (result_list.length === 0) return [-1]
  const list = result_list.filter((x) => x[1] === max)
  list.sort((a, b) => {
    for (let i = 10; i >= 0; i--) if (a[0][i] !== b[0][i]) return b[0][i] - a[0][i]
  })
  return list[0][0]
}
