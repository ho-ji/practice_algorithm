function solution(order) {
  const sub = []
  const main = []
  for (let i = order.length; i > 0; i--) main.push(i)

  for (let i = 0; i < order.length; i++) {
    while (main[main.length - 1] < order[i]) sub.push(main.pop())

    if (main[main.length - 1] === order[i]) {
      main.pop()
    } else if (sub[sub.length - 1] === order[i]) {
      sub.pop()
    } else if (sub[sub.length - 1] > order[i]) return i
  }
  return order.length
}
