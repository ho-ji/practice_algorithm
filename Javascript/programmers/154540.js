function solution(maps) {
  let answer = []
  let move = [
    [0, 1],
    [1, 0],
    [0, -1],
    [-1, 0],
  ]
  for (let i = 0; i < maps.length; i++) {
    for (let j = 0; j < maps[0].length; j++) {
      if (maps[i][j] !== 'X') {
        let visit = []
        let sum = +maps[i][j]
        maps[i][j] = 'X'
        visit.push([i, j])
        while (!visit.empty) {
          let [x, y] = visit.pop()
          for (let k = 0; k < 4; k++) {
            let mx = x + move[k][0]
            let my = y + move[k][1]
            if (mx >= 0 && mx < maps.length && my >= 0 && my < maps[0].length && maps[mx][my] !== 'X') {
              visit.push([mx, my])
              sum += +maps[mx][my]
              maps[mx][my] = 'X'
            }
          }
        }
        answer.push(sum)
      }
    }
  }
  return answer.sort((a, b) => a - b)
}
