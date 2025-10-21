import os
import curses
import random
from typing import List, Tuple

Vector2 = Tuple[int, int] 
Snake = List[Vector2]
Apple = Vector2
Window = curses.window

DIRECTIONS = {
    curses.KEY_LEFT: 'left',
    curses.KEY_RIGHT: "right",
    curses.KEY_UP: "up",
    curses.KEY_DOWN: "down"
}

UPDATE_RATE = 500

def create_apple(game_bounds: Tuple[int, int]) -> Apple:
    height, width = game_bounds
    return [random.randint(1, height - 2), random.randint(1, width - 2)]

def draw_apple(window: Window, apple: Apple):
    window.addch(*apple, curses.ACS_DIAMOND)

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

def move_snake(snake: Snake, direction: str):
    new_head = snake[0]
    if direction == "left":
        new_head = (new_head[0], new_head[1] - 1)
    elif direction == "right":
        new_head = (new_head[0], new_head[1] + 1)
    elif direction == "up":
        new_head = (new_head[0] - 1,new_head[1])
    elif direction == "down":
        new_head = (new_head[0] + 1, new_head[1])
    snake.insert(0, new_head)

def trim_snake(window: Window, snake: Snake):
    tail = snake.pop()
    window.addch(*tail, " ")

def init_update_loop(window: Window) -> int:
    curses.curs_set(0)
    game_bounds = window.getmaxyx()
    
    snake = init_snake()
    apple = create_apple(game_bounds)

    key = curses.KEY_RIGHT
    direction = "right"

    draw_snake(window, snake)
    draw_apple(window, apple)

    while True:
        window.border(0)
        window.timeout(UPDATE_RATE)

        next_key = window.getch()
        if next_key != -1:
            key = next_key
        direction = DIRECTIONS[key] if DIRECTIONS[key] else direction

        move_snake(snake, direction)
        trim_snake(window, snake)

        draw_snake(window, snake)
        draw_apple(window, apple)


if __name__ == "__main__":
    curses.wrapper(init_update_loop)