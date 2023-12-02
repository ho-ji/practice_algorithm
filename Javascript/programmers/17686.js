const solution = (files) => {
  const answer = [...files]
  answer.sort((a, b) => {
    const headA = a
      .split(/\d/)
      .filter((x) => x)[0]
      .toUpperCase()
    const headB = b
      .split(/\d/)
      .filter((x) => x)[0]
      .toUpperCase()
    if (headA === headB) {
      let numA = parseInt(a.split(/\D/).filter((x) => x)[0])
      let numB = parseInt(b.split(/\D/).filter((x) => x)[0])
      return numA - numB
    }
    return headA > headB ? 1 : -1
  })
  return answer
}
