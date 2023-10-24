function solution(msg) {
  const answer = []
  const dic = {A: 1, B: 2, C: 3, D: 4, E: 5, F: 6, G: 7, H: 8, I: 9, J: 10, K: 11, L: 12, M: 13, N: 14, O: 15, P: 16, Q: 17, R: 18, S: 19, T: 20, U: 21, V: 22, W: 23, X: 24, Y: 25, Z: 26}
  let num = 26
  for (let i = 0; i < msg.length; i++) {
    let str = msg[i]
    let ans = dic[msg[i]]
    for (let j = i + 1; j < msg.length; j++) {
      if (dic[str + msg[j]] === undefined) {
        dic[str + msg[j]] = ++num
        ans = dic[str]
        i = j - 1
        break
      }
      if (j === msg.length - 1) {
        ans = dic[str + msg[j]]
        i = j
        break
      }
      str += msg[j]
    }
    answer.push(ans)
  }
  return answer
}
