function solution(word) {
  let answer = 0
  let wordList = ['A', 'E', 'I', 'O', 'U']
  let count = 0
  const DFS = (str) => {
    if (str === word) {
      answer = count
    }
    if (str.length < 5) {
      for (let i = 0; i < 5; i++) {
        count++
        DFS(str + wordList[i])
      }
    }
  }
  DFS('')
  return answer
}
