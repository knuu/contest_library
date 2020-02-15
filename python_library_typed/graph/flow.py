from typing import List, TypeVar, Generic
T = TypeVar('T', int, float)


class ResidualEdge(Generic[T]):
    def __init__(self, fr: int, to: int, cap: int) -> None:
        self.fr: int = fr
        self.to: int = to
        self.cap: T = cap


class ResidualGraph:
    pass
