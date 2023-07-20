function solution(maps) {
  let x = [],
    y = [];
  const moves = [
    [1, 0],
    [0, 1],
    [-1, 0],
    [0, -1],
  ];
  const n = maps.length,
    m = maps[0].length;
  x.push(0);
  y.push(0);

  while (x.length > 0) {
    let nx = x.shift();
    let ny = y.shift();

    for (let i = 0; i < 4; i++) {
      let mx = nx + moves[i][0];
      let my = ny + moves[i][1];
      if (mx >= 0 && mx < n && my >= 0 && my < m && maps[mx][my] === 1) {
        if (mx === n - 1 && my === m - 1) {
          return maps[nx][ny] + 1;
        }
        x.push(mx);
        y.push(my);
        maps[mx][my] = 2;
      }
    }
  }
  return -1;
}
