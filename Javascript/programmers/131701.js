function solution(elements) {
  const set = new Set([...elements])
  for (let len = 2; len <= elements.length; len++) {
    for (let i = 0; i < elements.length; i++) {
      let sum = 0
      for (let j = i; j < i + len; j++) {
        sum += elements[j % elements.length]
      }
      set.add(sum)
    }
  }
  return set.size
}
