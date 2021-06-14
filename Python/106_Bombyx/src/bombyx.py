from typing import NamedTuple, Union
from src.evolution import Generations, Bombyx, GrowthRate, generate, growth_rate


def main(bombyx: Bombyx) -> int:

    if isinstance(bombyx.request, GrowthRate):
        generate(bombyx.n, bombyx.request)

    if isinstance(bombyx.request, Generations):
        growth_rate(bombyx.n, bombyx.request.i0, bombyx.request.i1)

    return 0
