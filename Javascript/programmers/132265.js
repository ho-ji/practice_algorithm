function solution(topping) {
  const cutRollCake = new Set()
  const toppingList = {}

  let answer = 0
  let toppingCount = 0

  for (const t of topping) {
    if (!toppingList[t]) {
      toppingList[t] = 0
      toppingCount++
    }
    toppingList[t]++
  }

  for (const t of topping) {
    cutRollCake.add(t)
    toppingList[t]--

    if (!toppingList[t]) toppingCount--
    if (cutRollCake.size === toppingCount) answer++
  }

  return answer
}
