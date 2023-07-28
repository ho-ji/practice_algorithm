function solution(food) {
  let answer = '0'
  for (let i = food.length - 1; i > 0; i--) {
    for (let j = 0; j < parseInt(food[i] / 2); j++) {
      answer = i + answer + i
    }
  }
  return answer
}
