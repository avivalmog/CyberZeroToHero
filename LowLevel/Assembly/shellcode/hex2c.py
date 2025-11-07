#!/usr/bin/env python3
import sys
import textwrap

def hex_to_cstring(hexstr, bytes_per_line=16):
    # remove non-hex chars (whitespace, newlines)
    s = ''.join(ch for ch in hexstr if ch in '0123456789abcdefABCDEF')
    if len(s) % 2 != 0:
        raise SystemExit("hex string has odd length")
    # split into byte tokens
    bytes_list = [s[i:i+2] for i in range(0, len(s), 2)]
    lines = []
    for i in range(0, len(bytes_list), bytes_per_line):
        chunk = bytes_list[i:i+bytes_per_line]
        esc = ''.join('\\x' + b.lower() for b in chunk)
        lines.append(f"\"{esc}\"")
    # join with newline and two-space indent for subsequent lines (like your example)
    if not lines:
        return ""
    out = lines[0]
    for line in lines[1:]:
        out += "\n  " + line
    return out

def main():
    if len(sys.argv) > 1:
        with open(sys.argv[1], 'r') as f:
            hexstr = f.read()
    else:
        hexstr = sys.stdin.read()

    result = hex_to_cstring(hexstr, bytes_per_line=16)
    print(result)

if __name__ == "__main__":
    main()
