function solution(maps) {
  let answer = []
  let move = [
    [0, 1],
    [1, 0],
    [0, -1],
    [-1, 0],
  ]
  let newMaps = []
  maps.forEach((v) => newMaps.push(v.split('')))
  for (let i = 0; i < newMaps.length; i++) {
    for (let j = 0; j < newMaps[0].length; j++) {
      if (newMaps[i][j] !== 'X') {
        let visited = []
        let sum = +newMaps[i][j]
        visited.push([i, j])
        while (visited.length !== 0) {
          let [x, y] = visited.pop()
          newMaps[x][y] = 'X'
          for (let k = 0; k < 4; k++) {
            let mx = x + move[k][0]
            let my = y + move[k][1]
            if (mx >= 0 && mx < newMaps.length && my >= 0 && my < newMaps[0].length && newMaps[mx][my] !== 'X') {
              visited.push([mx, my])
              sum += +newMaps[mx][my]
              newMaps[mx][my] = 'X'
            }
          }
        }
        answer.push(sum)
      }
    }
  }
  if (answer.length === 0) return [-1]
  return answer.sort((a, b) => a - b)
}
