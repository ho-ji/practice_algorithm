function solution(numbers) {
  let answer = 0
  const count = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
  for (let num = 0; num < numbers.length; num++) {
    count[numbers[num]]++
  }

  let max = 10 ** numbers.length

  const primeCheck = []

  for (let i = 2; i <= max; i++) {
    if (primeCheck[i]) continue
    for (let j = i + i; j <= max; j += i) {
      primeCheck[j] = true
    }
  }

  for (let num = 2; num <= max; num++) {
    if (!primeCheck[num]) {
      let x = num.toString()
      let checkList = [...count]
      for (let i = 0; i < x.length; i++) {
        checkList[x[i]]--
        if (checkList[x[i]] < 0) {
          answer--
          break
        }
      }
      answer++
    }
  }
  return answer
}
