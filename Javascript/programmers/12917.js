function solution(s) {
  return s
    .split('')
    .sort((a, b) => {
      return b.charCodeAt() - a.charCodeAt()
    })
    .join('')
}
