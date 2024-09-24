# So_Long

![Language: C](https://img.shields.io/badge/Language-C-blue.svg)
![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)

## Introduction

`So_Long` is a simple 2D game where the player must collect items and find the exit on a predefined map. The game is inspired by the universe of [Freeze Corleone](https://twitter.com/freezecorleone). It utilizes textures, sprites, and basic gameplay mechanics. The primary goal of this project is to help you work with basic computer graphics, window management, and event handling using the MiniLibX library.

## Gameplay GIFs

![gameplay_gif](https://github.com/Zaiicko/so_long/blob/main/map3.gif)


![gameplay_gif2](https://github.com/Zaiicko/so_long/blob/main/map.gif)

<img width="564" alt="Sprites" src="https://github.com/user-attachments/assets/6bdb6e58-5769-4b9e-a21c-23ece01ce837">

## Features

- **Game Objective**:
  - The player must collect all collectibles on the map and reach the exit.
  - The game is controlled with the keyboard using either the `W`, `A`, `S`, and `D` keys or the arrow keys for movement.
  - Movement should be restricted to valid spaces, avoiding walls.
  - The number of moves is displayed in the terminal after each action.

- **Map**:
  - The map is built from specific characters: `0` for empty space, `1` for walls, `C` for collectibles, `E` for exits, and `P` for the player's start position.
  - Maps must be rectangular, surrounded by walls, and contain at least one exit, one collectible, and one starting point.

## Usage

To use the `so_long` program:

1. **Compile the Project:**

    ```sh
    make
    ```

2. **Run the Program:**

    ```sh
    ./so_long <map_file.ber>
    ```

    Replace `<map_file.ber>` with the path to a valid `.ber` map file.

3. **Example:**

    ```sh
    ./so_long maps/simple_map.ber
    ```

    This will start the game using the specified map file.

## Example Maps

Here is an example of a valid `.ber` map file:

    1111111
    1P00001
    100C0E1
    1111111

    P - Player's starting position.
    C - Collectible.
    E - Exit.
    1 - Wall.
    0 - Empty space.

## System Compatibility

This project is compatible with macOS and Linux systems.

## Resources

I used [PiskelApp](https://www.piskelapp.com/) to modify the player sprite to show the back view and to make the exit appear closed.
Here are the links to the assets used in the project :

- [Player_right_Sprite](https://www.instagram.com/p/CBiPU_jithJ/?utm_source=ig_web_copy_link)
- [Wall_Sprite](https://opengameart.org/content/dead-tree-1)
- [Exit_Sprite](https://www.vectorstock.com/royalty-free-vector/pixel-art-old-abandoned-house-isolated-vector-21959510)
- [Ground_Sprite](https://kalponic-studio.itch.io/stylized-ground-textures?download)
