# Algorithm

## Complexity of Sorting Algorithms

> refer to https://en.wikipedia.org/wiki/Sorting_algorithm

|      name      |  best   | average |  worst  | memory | stable |  method   | other notes                                              |
| :------------: | :-----: | :-----: | :-----: | :----: | :----: | :-------: | :------------------------------------------------------- |
| Selection sort |  $n^2$  |  $n^2$  |  $n^2$  |  $1$   |   No   | Selection | Stable with O(n) extra space or when using linked lists. |
|  Bubble sort   |   $n$   |  $n^2$  |  $n^2$  |  $1$   |  Yes   | Insertion | Tiny code size.                                          |
| Insertion sort |   $n$   |  $n^2$  |  $n^2$  |  $1$   |  Yes   | Insertion | Tiny code size.                                          |
|   Merge sort   | $nlogn$ | $nlogn$ | $nlogn$ |  $n$   |  Yes   |  Merging  | Tiny code size.                                          |
|   Heap sort    |   $n$   | $nlogn$ | $nlogn$ |  $1$   |   No   | Selection | Tiny code size.                                          |
|   Quick sort   | $nlogn$ | $nlogn$ |  $n^2$  |  $logn$   |   No   | Selection | Tiny code size.                                          |