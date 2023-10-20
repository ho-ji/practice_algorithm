function solution(dirs) {
  let answer = 0
  let posY = 0
  let posX = 0
  const check = {}
  for (const dir of dirs) {
    if (dir === 'U') {
      if (posY === 5) continue
      posY++
      if (check[[posY - 1, posX, posY, posX]] === undefined) {
        answer++
        check[[posY - 1, posX, posY, posX]] = true
      }
    } else if (dir === 'D') {
      if (posY === -5) continue
      posY--
      if (check[[posY, posX, posY + 1, posX]] === undefined) {
        answer++
        check[[posY, posX, posY + 1, posX]] = true
      }
    } else if (dir === 'R') {
      if (posX === 5) continue
      posX++
      if (check[[posY, posX - 1, posY, posX]] === undefined) {
        answer++
        check[[posY, posX - 1, posY, posX]] = true
      }
    } else if (dir === 'L') {
      if (posX === -5) continue
      posX--
      if (check[[posY, posX, posY, posX + 1]] === undefined) {
        answer++
        check[[posY, posX, posY, posX + 1]] = true
      }
    }
  }
  console.log(check)
  return answer
}
