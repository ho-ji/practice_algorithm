function solution(seoul) {
  let pos
  for (pos = 0; pos < seoul.length; pos++) if (seoul[pos] === 'Kim') break
  return `김서방은 ${pos}에 있다`
}
