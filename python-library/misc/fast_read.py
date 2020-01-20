# see: https://twitter.com/maspy_stars/status/1179226257982185472
import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines


def use_fast_io():
    global input
    import io
    import sys
    f = io.BytesIO(sys.stdin.buffer.read())
    input = f.readline
