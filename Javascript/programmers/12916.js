function solution(s) {
  let cntP = 0,
    cntY = 0
  for (const word of s) {
    if (word === 'p' || word === 'P') cntP++
    else if (word === 'y' || word === 'Y') cntY++
  }
  if (cntP === 0 && cntY === 0) return true
  if (cntP === cntY) return true
  return false
}
