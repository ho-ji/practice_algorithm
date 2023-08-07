function solution(N, stages) {
  let stayUserCount = new Array(N + 2).fill(0)
  failPercentList = []
  for (const stage of stages) {
    stayUserCount[stage]++
  }
  let clearUserCount = stages.length
  for (let n = 1; n <= N; n++) {
    clearUserCount -= stayUserCount[n - 1]
    failPercentList[n - 1] = {number: n, failPercent: stayUserCount[n] / clearUserCount}
  }
  failPercentList.sort((a, b) => b.failPercent - a.failPercent)
  return failPercentList.map((stage) => stage.number)
}
