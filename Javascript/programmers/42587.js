function solution(priorities, location) {
  let count = 0
  const stack = [...priorities].sort((a, b) => a - b)
  const queue = [...priorities]

  while (1) {
    let x = queue.shift()
    if (x === stack[stack.length - 1]) {
      count++
      location--
      stack.pop()
      if (location === -1) return count
    } else {
      queue.push(x)
      location--
      if (location === -1) location = queue.length - 1
    }
  }
}
