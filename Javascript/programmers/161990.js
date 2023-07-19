function solution(wallpaper) {
  let minX = wallpaper.length,
    minY = wallpaper[0].length,
    maxX = -1,
    maxY = -1;
  for (let i = 0; i < wallpaper.length; i++) {
    for (let j = 0; j < wallpaper[0].length; j++) {
      if (wallpaper[i][j] === "#") {
        console.log(i, j);
        if (i < minX) minX = i;
        if (j < minY) minY = j;
        if (i > maxX) maxX = i;
        if (j > maxY) maxY = j;
      }
    }
  }
  return [minX, minY, maxX + 1, maxY + 1];
}
