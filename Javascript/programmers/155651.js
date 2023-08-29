const getTime = (time) => {
  return +time.slice(0, 2) * 60 + +time.slice(3, 5)
}

function solution(book_time) {
  let minRoomCount = 1
  book_time.sort((a, b) => (a[0] > b[0] ? 1 : -1))
  let usingRoom = [getTime(book_time[0][1]) + 10]
  for (let i = 1; i < book_time.length; i++) {
    while (!usingRoom.empty && usingRoom[usingRoom.length - 1] <= getTime(book_time[i][0])) {
      usingRoom.pop()
    }
    usingRoom.push(getTime(book_time[i][1]) + 10)
    usingRoom.sort((a, b) => b - a)
    minRoomCount = Math.max(usingRoom.length, minRoomCount)
  }
  return minRoomCount
}
