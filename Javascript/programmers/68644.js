function solution(numbers) {
  let map = []
  let answer = []
  for (let i = 0; i < numbers.length; i++) {
    for (let j = i + 1; j < numbers.length; j++) {
      map[numbers[i] + numbers[j]] = true
    }
  }
  for (let i = 0; i <= 200; i++) {
    if (map[i]) answer.push(i)
  }
  return answer
}
