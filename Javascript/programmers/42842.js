function solution(brown, yellow) {
  let col = (brown - 6) / 2 + 2
  let row = 3
  while (col >= row) {
    if (col * row - brown === yellow) return [col, row]
    col--
    row++
  }
  return -1
}
