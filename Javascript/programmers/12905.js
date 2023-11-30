const solution = (board) => {
  let max = 0
  for (let i = 0; i < board.length; i++) {
    for (let j = 0; j < board[0].length; j++) {
      if (board[i][j] !== 0 && max === 0) max = 1
      if (i + 1 < board.length) {
        if (j + 1 < board[0].length) {
          if (board[i + 1][j + 1] === 0) continue
          board[i + 1][j + 1] = Math.min(board[i + 1][j], board[i][j + 1], board[i][j]) + 1
          if (board[i + 1][j + 1] > max) max = board[i + 1][j + 1]
        }
      }
    }
  }
  return max * max
}
