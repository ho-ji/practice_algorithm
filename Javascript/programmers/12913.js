function solution(land) {
  let answer = 0
  const dp = []
  dp[0] = land[0]
  for (let col = 1; col < land.length; col++) {
    dp[col] = [0, 0, 0, 0]
    for (let i = 0; i < 4; i++) {
      for (let j = 0; j < 4; j++) {
        if (i !== j) {
          dp[col][i] = Math.max(dp[col][i], dp[col - 1][j] + land[col][i])
        }
      }
    }
  }
  return dp[land.length - 1].sort((a, b) => b - a)[0]
}
