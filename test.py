#!/usr/bin/env python3

import argparse
import  meadowlark as lark

def main():
    parser = argparse.ArgumentParser(description="Print Meadow metadata")
    parser.add_argument("--burrow", required=True, help="Path to the burrow")
    args = parser.parse_args()

    try:
        meadow = lark.Meadow.open(args.burrow)
        with meadow:
            hopper = meadow.hopper("hello world")
            k = 0
            while True:
                p, q, _ = hopper.tau(k)
                if p == lark.maxfinity:
                    break
                print(p, q)
                k = p + 1
    except RuntimeError as e:
        print(e)

if __name__ == "__main__":
    main()
