import os
import curses
from typing import List, Tuple

Vector2 = Tuple[int, int] 
Snake = List[Vector2]
Window = curses.window

DIRECTIONS = {
    curses.KEY_LEFT: 'left',
    curses.KEY_RIGHT: "right",
    curses.KEY_UP: "up",
    curses.KEY_DOWN: "down"
}

UPDATE_RATE = 500

def init_snake() -> Snake:
    snake = [
        (10, 7),
        (10, 6),
        (10, 5)
    ]
    return snake

def draw_snake(window: Window, snake: Snake) -> Snake:
    head, *body = snake
    window.addch(*head, "@"),
    for body_part in body:
        window.addch(*body_part, "#")

def init_update_loop(window: Window) -> int:
    curses.curs_set(0)
    
    snake = init_snake()
    draw_snake(window, snake)

    while True:
        window.border(0)
        window.timeout(UPDATE_RATE)
        window.refresh()


if __name__ == "__main__":
    curses.wrapper(init_update_loop)