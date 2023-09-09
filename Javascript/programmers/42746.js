function solution(numbers) {
  let answer = ''
  let numbersList = numbers
    .map((v) => v.toString())
    .sort((a, b) => {
      return parseInt(b + a) - parseInt(a + b)
    })
  return numbersList[0] === '0' ? '0' : numbersList.join('')
}
