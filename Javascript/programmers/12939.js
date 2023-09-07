function solution(s) {
  const list = s.split(' ')
  let min = +list[0]
  let max = +list[0]
  for (const data of list) {
    if (min > +data) min = +data
    if (max < +data) max = +data
  }
  return `${min} ${max}`
}
