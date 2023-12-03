const solution = (files) => {
  const answer = [...files]
  const regex = /(\D*)(\d*)/
  answer.sort((a, b) => {
    const regA = a.match(regex)
    const regB = b.match(regex)
    const headA = regA[1].toUpperCase()
    const headB = regB[1].toUpperCase()
    if (headA === headB) {
      return parseInt(regA[2]) - parseInt(regB[2])
    }
    return headA > headB ? 1 : -1
  })
  return answer
}
