const solution = (m, musicinfos) => {
  let answer = ''
  let answerTime = 0
  const regex = new RegExp(`${m}(?!#)`, 'g')
  for (const musicinfo of musicinfos) {
    const music = musicinfo.split(',')
    const time = parseInt(music[1].slice(0, 2)) * 60 + parseInt(music[1].slice(3)) - (parseInt(music[0].slice(0, 2)) * 60 + parseInt(music[0].slice(3)))
    let melody = ''
    let count = 0
    for (let i = 0; count < time; i++) {
      if (i >= music[3].length) i = 0
      melody += music[3][i]
      if (i + 1 < music[3].length && music[3][i + 1] === '#') {
        melody += '#'
        ++i
      }
      count++
    }

    if (melody.search(regex) !== -1) {
      if (answerTime < time) {
        answerTime = time
        answer = music[2]
      }
    }
  }
  if (answer === '') return '(None)'
  return answer
}
