function solution(sizes) {
  let w = 0,
    h = 0
  for (let i = 0; i < sizes.length; i++) {
    w = Math.max(w, Math.max(sizes[i][0], sizes[i][1]))
    h = Math.max(h, Math.min(sizes[i][0], sizes[i][1]))
  }
  return w * h
}
