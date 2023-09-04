function solution(x, y, n) {
  if (x === y) return 0
  const dp = {}
  dp[x] = 0
  let dataList = [x]
  while (dataList.length !== 0) {
    const newDataList = []
    for (const data of dataList) {
      for (const value of [data + n, data * 2, data * 3]) {
        if (!dp[value]) {
          if (value === y) return dp[data] + 1
          else if (value < y) {
            dp[value] = dp[data] + 1
            newDataList.push(value)
          }
        }
      }
    }
    dataList = newDataList
  }
  return -1
}
