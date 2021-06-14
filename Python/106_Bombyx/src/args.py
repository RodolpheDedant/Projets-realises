from argparse import ArgumentParser, ArgumentTypeError
from src.evolution import Bombyx, Generations
from sys import argv


def positive_int(value: str) -> int:
    try:
        result = int(value)
    except ValueError:
        raise ArgumentTypeError(f"{value} isn't a positive integer")

    if result <= 0:
        raise ArgumentTypeError(f"{value} isn't a positive integer")

    return result


def parse_args() -> Bombyx:
    parser = ArgumentParser(usage="%(prog)s n [k | i0 i1]")

    parser.add_argument("initial_population", type=positive_int)
    parser.add_argument("--growth_rate", metavar="k", type=float, help="Growth rate")
    parser.add_argument(
        "--generations",
        metavar=("i0", "i1"),
        nargs=2,
        type=positive_int,
        help="Generations",
    )

    # Epitech Arguments
    args = argv[1:]
    if len(args) == 2:
        args.insert(1, "--growth_rate")
    elif len(args) == 3:
        args.insert(1, "--generations")

    try:
        parsed_args = parser.parse_args(args)
    except SystemExit:
        exit(84)

    if not parsed_args.growth_rate is None:
        return Bombyx(parsed_args.initial_population, parsed_args.growth_rate)

    if not parsed_args.generations is None:
        generations = Generations(*parsed_args.generations)
        return Bombyx(parsed_args.initial_population, generations)

    print("No action passed")
    exit(84)
