function solution(people, limit) {
  let answer = 0
  people.sort((a, b) => b - a)
  let end = people.length
  for (let i = 0; i < people.length; i++) {
    if (i >= end) {
      break
    }
    if (people[i] + people[end - 1] <= limit) {
      end--
    }
    answer++
  }
  return answer
}
