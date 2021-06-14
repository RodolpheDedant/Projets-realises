# from src.bombyx import Generations, main
from typing import NamedTuple, Union

GrowthRate = float


class Generations(NamedTuple):
    i0: int
    i1: int


class Bombyx(NamedTuple):
    n: int
    request: Union[GrowthRate, Generations]


def generate(n: float, k: float) -> None:
    i = 1
    while i <= 100:
        gen = n
        print(f"{i} {gen:.2f}")
        n = k * gen * ((1000 - gen) / 1000)
        i += 1


def growth_rate(n: float, i0: int, i1: int) -> int:
    save_i0 = i0
    if n < 1:
        return 84
    if i1 < 0 or i0 < 0:
        return 84
    xm = n
    k = 1.00
    if i0 > i1:
        return 84
    while k <= 4.00:
        for i in range(1, i0):
            xm = (k * xm) * (1000 - xm) / 1000
        while i0 <= i1:
            if xm < 0:
                print(f"{k:.2f} 0.00")
            else:
                print(f"{k:.2f} {xm:.2f}")
            xm = (k * xm) * (1000 - xm) / 1000
            i0 += 1
        xm = n
        i0 = save_i0
        k += 0.01
    return 0
