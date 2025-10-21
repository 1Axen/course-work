import os
import curses
import random
from typing import List, Tuple

Vector2 = Tuple[int, int] 
Snake = List[Vector2]
Apple = Vector2
Bounds = Tuple[int, int]
Window = curses.window

DIRECTIONS = {
    curses.KEY_LEFT: 'left',
    curses.KEY_RIGHT: "right",
    curses.KEY_UP: "up",
    curses.KEY_DOWN: "down"
}

REVERSE_DIRECTIONS = {
    curses.KEY_LEFT: "right",
    curses.KEY_RIGHT: "left",
    curses.KEY_UP: "down",
    curses.KEY_DOWN: "up"
}

UPDATE_RATE = 300

def create_apple(game_bounds: Bounds) -> Apple:
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

def is_not_reverse_direction(direction: str, key: int) -> bool:
    return REVERSE_DIRECTIONS[key] != direction

def snake_overlaps_apple(snake: Snake, apple: Apple) -> bool:
    head = snake[0]
    return head[0] == apple[0] and head[1] == apple[1]

def snake_is_out_of_bounds(game_bounds: Bounds, snake: Snake) -> bool:
    head = snake[0]
    y, x = head
    max_y, max_x = game_bounds[0], game_bounds[1]
    return (x < 1 or x > max_x - 2) or (y < 1 or y > max_y - 2)

def snake_overlaps_itself(snake: Snake) -> bool:
    return snake[0] in snake[1:]
    
def game_is_over(game_bounds: Bounds, snake: Snake) -> bool:
    return snake_is_out_of_bounds(game_bounds, snake) or snake_overlaps_itself(snake)

def init_update_loop(window: Window) -> int:
    curses.curs_set(0)
    game_bounds = window.getmaxyx()
    
    score = 0
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
        key = next_key if next_key != -1 and next_key in DIRECTIONS else key
        direction = DIRECTIONS[key] if is_not_reverse_direction(direction, key) else direction

        move_snake(snake, direction)
        if snake_overlaps_apple(snake, apple):
            score += 1
            apple = create_apple(game_bounds)
        else:
            trim_snake(window, snake)

        if game_is_over(game_bounds, snake):
            return score

        draw_snake(window, snake)
        draw_apple(window, apple)


if __name__ == "__main__":
    score = curses.wrapper(init_update_loop)
    print("Game Over!")
    print(f"Your score: {score}")