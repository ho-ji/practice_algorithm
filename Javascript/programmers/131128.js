function solution(X, Y) {
  let answer = '',
    listX = [],
    listY = []
  for (const x of X) {
    listX[+x] = (listX[+x] || 0) + 1
  }
  for (const y of Y) {
    listY[+y] = (listY[+y] || 0) + 1
  }
  for (let i = 10; i >= 0; i--) {
    if (listX[i] !== 0 && listY[i] !== 0) {
      for (let j = 0; j < Math.min(listX[i], listY[i]); j++) {
        answer += i
      }
    }
  }
  if (answer[0] === '0') return '0'
  if (answer === '') return '-1'
  return answer
}
