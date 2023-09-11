class MaxHeap {
  constructor() {
    this.heap = [null]
  }
  push(value) {
    this.heap.push(value)
    let currentIndex = this.heap.length - 1
    let parentIndex = Math.floor(currentIndex / 2)
    while (parentIndex !== 0 && this.heap[parentIndex] < value) {
      ;[this.heap[parentIndex], this.heap[currentIndex]] = [this.heap[currentIndex], this.heap[parentIndex]]
      currentIndex = parentIndex
      parentIndex = Math.floor(currentIndex / 2)
    }
  }
  pop() {
    const max = this.heap[1]
    this.heap[1] = this.heap.pop()
    let currentIndex = 1
    let leftIndex = 2
    let rightIndex = 3
    while (this.heap[currentIndex] < this.heap[leftIndex] || this.heap[currentIndex] < this.heap[rightIndex]) {
      if (this.heap[leftIndex] < this.heap[rightIndex]) {
        ;[this.heap[currentIndex], this.heap[rightIndex]] = [this.heap[rightIndex], this.heap[currentIndex]]
        currentIndex = rightIndex
      } else {
        ;[this.heap[currentIndex], this.heap[leftIndex]] = [this.heap[leftIndex], this.heap[currentIndex]]
        currentIndex = leftIndex
      }
      leftIndex = currentIndex * 2
      rightIndex = currentIndex * 2 + 1
    }
    return max
  }
  isEmpty() {
    return this.heap.length === 1
  }
}
function solution(n, k, enemy) {
  let successRound = new MaxHeap()
  for (let i = 0; i < enemy.length; i++) {
    successRound.push(enemy[i])
    n -= enemy[i]
    if (n < 0) {
      if (k > 0) {
        k--
        n += successRound.pop()
      } else return i + 1
    }
  }
  return enemy.length
}
