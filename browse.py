#!/usr/bin/env python3
import argparse
import readline
from meadowlark import Meadow, maxfinity

def sanitize(s: str) -> str:
    return s.replace("\n", " ")

def main():
    parser = argparse.ArgumentParser(
        description="Interactive Meadowlark query shell"
    )
    parser.add_argument(
        "-b", "--burrow",
        default=None,
        help="Path to the burrow"
    )
    args = parser.parse_args()

    try:
        meadow = Meadow.open(args.burrow)
    except RuntimeError as e:
        print(f"Error opening burrow: {e}")
        return

    WINDOW = 128
    prompt = ">> "

    while True:
        try:
            line = input(prompt)
        except (EOFError, KeyboardInterrupt):
            break

        if not line.strip():
            continue
        readline.add_history(line)

        try:
            with meadow:
                hopper = meadow.hopper(line)
                for j, (p, q, v) in enumerate(hopper):
                    if j >= 24 or p >= maxfinity:
                        break

                    label = f"({p},{q}, {v}): "

                    span_len = q - p
                    if span_len <= WINDOW:
                        text = sanitize(meadow.translate(p, q))
                        print(label + text)
                    else:
                        a = sanitize(meadow.translate(p, p + WINDOW // 2))
                        c = sanitize(meadow.translate(q - WINDOW // 2, q))
                        print(label + f"{a}... {c}")

        except RuntimeError as e:
            print(f"Parse error: {e}")

if __name__ == "__main__":
    main()
