function solution(arr) {
  let answer = [0, 0]
  let x = 2
  for (let x = 2; x <= arr.length; x = x * 2) {
    for (let n = 0; n < arr.length; n += x) {
      for (let m = 0; m < arr.length; m += x) {
        let count = [0, 0, 0]
        for (let i = n; i < n + x; i = i + x / 2) {
          for (let j = m; j < m + x; j = j + x / 2) {
            count[arr[i][j] + 1]++
          }
        }
        if ((count[1] !== 0 && count[2] !== 0) || count[0] !== 0) {
          answer[0] += count[1]
          answer[1] += count[2]
          arr[n][m] = -1
        }
      }
    }
  }
  if (arr[0][0] === 0) answer[0]++
  else if (arr[0][0] === 1) answer[1]++
  return answer
}
