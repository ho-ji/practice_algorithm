function solution(babbling) {
  let answer = 0
  for (let i = 0; i < babbling.length; i++) {
    if (babbling[i] === 'a') {
      if (i < babbling.length - 2 && babbling[i + 1] == 'y' && babbling[i + 2] == 'a') {
        i += 2
      }
    }
  }
  return answer
}
