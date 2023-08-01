function solution(survey, choices) {
  let answer = ''
  let result = {R: 0, T: 0, C: 0, F: 0, J: 0, M: 0, A: 0, N: 0}
  for (let i = 0; i < survey.length; i++) {
    const [n, p] = survey[i]
    if (choices[i] < 4) {
      result[n] += 4 - choices[i]
    } else if (choices[i] > 4) {
      result[p] += choices[i] - 4
    }
  }
  answer += result['R'] >= result['T'] ? 'R' : 'T'
  answer += result['C'] >= result['F'] ? 'C' : 'F'
  answer += result['J'] >= result['M'] ? 'J' : 'M'
  answer += result['A'] >= result['N'] ? 'A' : 'N'
  return answer
}
