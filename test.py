#!/usr/bin/env python3

import argparse
import  meadowlark as lark

def main():
    parser = argparse.ArgumentParser(description="Test Meadowlark")
    parser.add_argument("--burrow", required=True, help="Path to the burrow")
    args = parser.parse_args()

    try:
        meadow = lark.Meadow.open(args.burrow)
        with meadow:
            for p, q, _ in meadow.hopper("hello world"):
                print(p, q)
    except RuntimeError as e:
        print(e)

if __name__ == "__main__":
    main()
