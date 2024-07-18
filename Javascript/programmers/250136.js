class Queue {
  constructor() {
    this.data = {}
    this.head = 0
    this.tail = 0
  }

  size() {
    return this.tail - this.head
  }

  push(element) {
    this.data[this.tail++] = element
  }

  pop() {
    const removed = this.data[this.head]
    delete this.data[this.head]
    this.head++

    if (this.head === this.tail) {
      this.head = 0
      this.tail = 0
    }
    return removed
  }
}

const solution = (land) => {
  const n = land.length
  const m = land[0].length
  let visited = -1
  const total = {}
  let answer = 0
  const q = new Queue()
  const directions = [
    [1, 0],
    [0, 1],
    [0, -1],
    [-1, 0],
  ]

  for (let j = 0; j < m; j++) {
    let sum = 0
    const check = []
    for (let i = 0; i < n; i++) {
      if (land[i][j] === 1) {
        let count = 1
        land[i][j] = visited
        q.push([i, j])
        while (q.size() !== 0) {
          const [x, y] = q.pop()
          for (const [dx, dy] of directions) {
            const nx = x + dx
            const ny = y + dy
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && land[nx][ny] === 1) {
              count++
              land[nx][ny] = visited
              q.push([nx, ny])
            }
          }
        }
        sum += count
        check.push(visited)
        total[visited--] = count
      } else if (land[i][j] < 0 && !check.includes(land[i][j])) {
        check.push(land[i][j])
        sum += total[land[i][j]]
      }
    }
    if (sum > answer) answer = sum
  }
  return answer
}
