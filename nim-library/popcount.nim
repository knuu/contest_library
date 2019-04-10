proc popcount[T: int](a: T): cint {. importc: "__builtin_popcountl", nodecl, nosideeffect.}
