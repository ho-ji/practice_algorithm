function solution(queue1, queue2) {
  let count = 0
  let sum1 = 0
  let sum2 = 0

  for (let i = 0; i < queue1.length; i++) {
    sum1 += queue1[i]
    sum2 += queue2[i]
  }

  let start1 = 0
  let start2 = queue1.length

  const list = [...queue1, ...queue2]

  while (start1 !== list.length && start2 !== queue1.length - 1) {
    if (start2 === list.length) start2 = 0
    if (sum1 > sum2) {
      sum1 -= list[start1]
      sum2 += list[start1]
      start1 += 1
    } else if (sum1 < sum2) {
      sum1 += list[start2]
      sum2 -= list[start2]
      start2 += 1
    } else return count
    count++
  }
  return -1
}
