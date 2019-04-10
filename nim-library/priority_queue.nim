# tuple など C++ で直接対応するものがないと使えない
type
  CPriorityQueue {.importcpp: "std::priority_queue", header: "<queue>".} [T] = object
proc cNewPriorityQueue(T: typedesc): CPriorityQueue[T]
  {.importcpp: "std::priority_queue<'*1>()", nodecl.}
proc newPriorityQueue*[T](): CPriorityQueue[T] = cNewPriorityQueue(T)
proc len*[T](this: CPriorityQueue[T]): int {.importcpp: "#.size(@)", nodecl.}
proc add*[T](this: CPriorityQueue[T], x: T) {.importcpp: "#.push(@)", nodecl.}
proc top*[T](this: CPriorityQueue[T]): T {.importcpp: "#.top(@)", nodecl.}
proc pop*[T](this: CPriorityQueue[T]) {.importcpp: "#.pop(@)", nodecl.}
