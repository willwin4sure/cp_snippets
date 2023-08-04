"""
    compiler.py

    Script that collects C++ snippets from ./cpp/* and
    compiles them to ./out.json in a format suitable
    for VSCode user snippets. 
"""

import json
import os

from colorama import init as colorama_init
from colorama import Fore
from colorama import Style

def processLines(lines):
    """
    Process list of lines into new list of lines.
    """
    begin = lines.index("////////// SNIPPET BEGIN //////////")
    end = len(lines) - lines[-1::-1].index("////////// SNIPPET END //////////") - 1

    return lines[begin+1:end]

def main():
    colorama_init()

    out = {}

    for folder in os.listdir("./cpp"):
        for file in os.listdir(f"./cpp/{folder}"):
            if file.endswith(".cpp"):
                with open(f"./cpp/{folder}/{file}") as f:
                    name = file[3:-4]
                    lines = f.read().splitlines()
                    print(f"Adding {Fore.YELLOW}{folder}/{file}{Style.RESET_ALL}...")
                    out[f"CP-{name}"] = {
                        "prefix": name,
                        "body": processLines(lines),
                        "description": lines[3].strip(),
                    }

    # write to out.json file
    with open("out.json", "w") as f:
        json.dump(out, f, indent=4)


if __name__ == '__main__':
    main()
