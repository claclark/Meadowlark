#!/usr/bin/env python3

#!/usr/bin/env python3

import argparse
from meadowlark import Meadow

def main():
    parser = argparse.ArgumentParser(description="Print Meadow metadata")
    parser.add_argument("--burrow", required=True, help="Path to the burrow")
    args = parser.parse_args()

    try:
        meadow = Meadow.open(args.burrow)
        with meadow:
            print("Name:", meadow.name())
            print("Recipe:", meadow.recipe())
    except RuntimeError as e:
        print(e)

if __name__ == "__main__":
    main()
