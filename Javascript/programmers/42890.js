function solution(relation) {
  const k = 1 << relation[0].length
  const answer = []
  for (let i = 1; i < k; i++) {
    const duplicateCheck = new Set()
    for (let row = 0; row < relation.length; row++) {
      let key = ''
      for (let col = 0; col < relation[0].length; col++) {
        if (i & (1 << col)) key += relation[row][col]
      }
      duplicateCheck.add(key)
    }
    if (duplicateCheck.size === relation.length) answer.push(i)
  }

  for (let i of answer) {
    for (let j of answer) {
      if (i >= j) continue
      if ((i & j) === i) answer.delete(j)
    }
  }
  return answer.length
}
