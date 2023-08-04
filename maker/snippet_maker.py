"""
    snippet_maker.py

    My old way of generating snippets to insert into the JSON.
    Takes in cpp code in ./input.txt then returns it formatted in ./output.txt.
    May contain parsing errors.
"""

def main():
    with open("input.txt", "r") as f:
        lines = f.read().splitlines()

    with open("output.txt", "w") as f:
        for line in lines:
            f.write(f'"{line}",\n')

if __name__ == '__main__':
    main()
