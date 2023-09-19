function solution(cards) {
  let answer = []
  let check = []
  const DFS = (n, count) => {
    if (check[n] === undefined) {
      check[n] = true
      return DFS(cards[n] - 1, count + 1)
    }
    return count
  }
  for (let i = 0; i < cards.length; i++) {
    if (check[i] === undefined) answer.push(DFS(i, 0))
  }
  if (answer.length === 1) return 0
  answer.sort((a, b) => b - a)
  return answer[0] * answer[1]
}
