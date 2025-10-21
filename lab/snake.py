import os
import curses

UPDATE_RATE = 500

def init_update_loop(window: curses.window) -> int:
    curses.curs_set(0)
    while True:
        window.border(0)
        window.timeout(UPDATE_RATE)
        window.addch(*[5, 5], "@")
        window.refresh()


if __name__ == "__main__":
    curses.wrapper(init_update_loop)