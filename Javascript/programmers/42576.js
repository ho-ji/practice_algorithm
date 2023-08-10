function solution(participant, completion) {
  let checkComplete = {}
  for (const c of completion) checkComplete[c] = checkComplete[c] + 1 || 1
  for (const p of participant) {
    if (!checkComplete[p]) return p
    else {
      checkComplete[p]--
    }
  }
}
