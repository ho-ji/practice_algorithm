function solution(s) {
  const words = s.split(' ')

  for (let i = 0; i < words.length; i++) {
    if (words[i][0] >= 'A' && words[i][0] <= 'Z') {
      words[i] = words[i][0] + words[i].toLowerCase().slice(1)
    } else if (words[i][0] >= 'a' && words[i][0] <= 'z') {
      words[i] = String(words[i][0]).toUpperCase() + words[i].toLowerCase().slice(1)
    } else {
      words[i] = words[i].toLowerCase()
    }
  }
  return words.join(' ')
}
