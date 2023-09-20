function solution(want, number, discount) {
  let answer = 0
  const saleList = {}

  for (let i = 0; i < 9; i++) {
    saleList[discount[i]] = saleList[discount[i]] ? saleList[discount[i]] + 1 : 1
  }

  for (let i = 9; i < discount.length; i++) {
    saleList[discount[i]] = saleList[discount[i]] ? saleList[discount[i]] + 1 : 1
    let check = true
    for (let i = 0; i < want.length; i++) {
      if (saleList[want[i]] !== number[i]) {
        check = false
        break
      }
    }
    if (check) answer++
    saleList[discount[i - 9]]--
  }
  return answer
}
