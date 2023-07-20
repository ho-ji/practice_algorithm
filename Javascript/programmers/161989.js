function solution(n, m, section) {
  let count = 0,
    paint = 0;
  for (let i = 0; i < section.length; i++) {
    if (section[i] > paint) {
      paint = section[i] + m - 1;
      count++;
    }
  }
  return count;
}
