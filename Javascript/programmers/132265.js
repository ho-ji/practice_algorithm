function solution(topping) {
  let answer = 0
  let left = {},
    leftCount = 1
  let right = {},
    rightCount = 0

  left[topping[0]] = 1
  for (let i = 1; i < topping.length; i++) {
    if (!right[topping[i]]) {
      rightCount++
      right[topping[i]] = 0
    }
    right[topping[i]]++
  }
  for (let i = 1; i < topping.length; i++) {
    if (leftCount === rightCount) answer++
    if (!left[topping[i]] || left[topping[i]] === 0) {
      leftCount++
      left[topping[i]] = 0
    }
    left[topping[i]]++
    if (--right[topping[i]] === 0) rightCount--
  }

  return answer
}
