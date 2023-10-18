function solution(n) {
  const dp = new Array(n + 3).fill(0)
  dp[1] = 1
  dp[2] = 1
  for (let i = 1; i < n; i++) {
    dp[i + 1] = (dp[i + 1] + dp[i]) % 1234567
    dp[i + 2] = (dp[i + 2] + dp[i]) % 1234567
  }
  return dp[n]
}
